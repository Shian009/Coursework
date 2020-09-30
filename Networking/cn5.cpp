//Selective Repeat ARQ
#include<iostream>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

class Protocol
{
	bool Naksent, AckNeeded;
	bool *Marked;

	public:
		int receiver(int seqno, int &rn)
		{
			int ack;
			cout<<"\n\t\t\t\t\t\tReceived Frame "<<seqno;
			sleep(2);
			if(seqno != rn && !Naksent)
			{
				cout<<"\n\t\t\t\t\t\tSending NAK "<<rn;
				sleep(2);
				Naksent = true;
				ack = 1;	
			}
			if(!Marked[seqno])
			{
				cout<<"\n\t\t\t\t\t\tStoring Frame "<<seqno;
				Marked[seqno] = true;
			}
			else
				cout<<"\n\t\t\t\t\t\tDiscarding Frame (Duplicate)";
			while(Marked[rn])
			{
				sleep(2);
				cout<<"\n\t\t\t\t\t\tDelivering Data "<<rn;
				sleep(2);
				cout<<"\n\t\t\t\t\t\tPurging Frame "<<rn;
				rn++;
				AckNeeded = true;
			}
			if(AckNeeded)
			{
				cout<<"\n\t\t\t\t\t\tSending ACK "<<rn;
				sleep(3);
				ack = 2;
				AckNeeded = false;
				Naksent = false;
			}
			return ack;
		}

		void sender(int nf, int sw)
		{
			Naksent = false;								//Initialized for the receiver
			AckNeeded = false;
			Marked = new bool [nf];
			for(int i = 0; i < nf; i++)
				Marked[i] = false;

			int sn = 1, sf = 1, ackno = 1;
			bool timer[nf] = {false};
			int ackNotification = 0;
			int flag1, flag2, trigger = 0;
			while(sf <= nf)
			{
				if(trigger == 0)
				{
					if(sn - sf >= sw || sn > nf)
					{
						cout<<"\n\n\t(All frames in current window have been sent)\n";
						trigger = 2;
						continue;
					}
					cout<<"\nStoring Frame "<<sn;
					sleep(2);
					cout<<"\nSending frame "<<sn;
					if(!timer[sn])
					{
						cout<<"\nStarting timer for "<<sn;
						timer[sn] = true;
					}
					sn++;
					sleep(3);
					flag1 = rand() % 2;
					if(flag1)
					{
						ackNotification = receiver(sn-1, ackno);			//call receiver
						trigger = 1;	
					}
					else
					{
						cout<<"\n\t\t     (Frame Lost)";
						continue;
					}
				}
				if(trigger == 1)
				{	
					sleep(2);
					flag2 = rand() % 2;
					if(flag2 == 0 && sn < nf)
						cout<<"\n\t\t    (Acknowledgement Lost)";
					else
					{
						if(ackNotification == 1)			//negative ack
						{
							if(ackno >= sf && ackno <= sn)
							{
								cout<<"\nReceived NAK "<<ackno;
								sleep(2);
								cout<<"\nResending Frame "<<ackno;
								cout<<"\nRestarting timer for "<<ackno;
								timer[ackno] = true;
								sleep(2);
								ackNotification = receiver(ackno, ackno);			//call receiver
								trigger = 1;
								continue;
							}
						}
						else
						{
							cout<<"\nReceived ACK "<<ackno;
							while(sf < ackno)
							{
								cout<<"\nPurging Frame "<<sf;
								sleep(2);
								cout<<"\nStopping timer for "<<sf;
								sleep(2);
								timer[sf] = false;
								sf++;
							}
							cout<<endl;
						}
					}
					trigger = 0;
				}
				if(trigger == 2)
				{
					for(int temp = sf; temp < sn; ++temp)
						if(timer[temp])
						{	
							cout<<"\n\t\t(Timeout "<<temp<<")";
							sleep(2);
							cout<<"\nRestarting Timer "<<temp;
							sleep(2);
							cout<<"\nResending Frame "<<temp;
							sleep(3);
							ackNotification = receiver(temp, ackno);
						}
					trigger = 1;
				}
			}
		}
};

int main()
{
	Protocol p;
	cout<<"Enter the no. of frames: ";
	int nf,sw;
	cin>>nf;
	cout<<"Enter the window size: ";
	cin>>sw;
	cout<<"\nSENDER\t\t\t\t\t\tRECEIVER\n";
	p.sender(nf,sw);
	cout<<"\n\t\tALL FRAMES ARE DELIVERED TO THE RECEIVER\n";
	return 0;
}