#include<iostream>
#include<cstdlib>
#include<ctime>
#include<unistd.h>		
using namespace std;
int count;
class Frame{
	int start,n;
	bool ack,canSend;
	public:
		Frame(int x){
			n=x;
			ack=true;
			count=1;
		}
		void send(){
			cout<<"\n Sending Frame "<<count<<"\t\t\t\t"; 
			canSend=false;
			start=clock();
			if(rand()%2)
				sleep(rand()%6);
			if(!isTimeout()){	
				if(!ack){
					cout<<"Discarded Frame "<<count<<" (Duplicate)";
					ack=true;
				}
				else
					cout<<"Received Frame "<<count<<" ";
				count++;
			}
			else{
				cout<<"----\n";
				cout<<"\t\t(Frame Lost)\n";
				canSend=true;
			}
		}
		void receive(){
			start=clock();
			if(!canSend){
				if(rand()%2)
					sleep(rand()%6);
				if(!isTimeout())
					cout<<"\nAcknowledgement "<<count<<"\n";
				else{
					cout<<"\n\t\t(Acknowledgement Lost)\n";
					count--;
					ack=false;
				}
			}
		}
		bool isTimeout(){
			return(((int)clock()-start)>4);
		}
};
int main(){
	int n;
	cout<<"\n No. of frames: ";
	cin>>n;
	Frame f(n);
	cout<<"\n\t Sender: \t\t|\t\t Receiver: ";
	do{
		f.send();
		f.receive();
	}while(count<=n);
	return 0;
}
