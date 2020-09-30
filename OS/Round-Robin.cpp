//Round-Robin Algorithm
#include<iostream>
using namespace std;
class Process
{
	private: 
		int n;
		int tq;
		int bt[10];
		char p[10];
		int wt[10];
		int tat[10];
		//int time[30];  //for gnatt chart
	public: 
		void input();
		void compute();
		void display();				
};

void Process :: input()
{
	char ch = 'A';
	cout<<"Enter the no. of processes (max 10): ";
	cin>>n;
	cout<<"Enter the Burst Time (BT) for:\n";
	for(int i=0; i<n; ++i)
	{
		cout<<"Process "<<ch<<": ";
		cin>>bt[i];
		p[i] = ch++;
	}
	cout<<"Enter the time quantam: ";
	cin>>tq;
}

void Process :: compute()
{
	//time[0] = 0;
	//int k = 0;
	int rem_bt[n];   //remaining burst time
    for (int i = 0 ; i < n ; i++) 
        rem_bt[i] =  bt[i]; 
  	
  	int t = 0;
  	cout<<"\nGnatt Chart: \n";
  	cout<<t;//time[0];
  	while(1)
  	{
  		bool done = true;
		for(int i = 0; i<n; ++i)
		{
			if(rem_bt[i] > 0)
			{
				done = false;
				if(rem_bt[i] > tq)
				{
					//time[k+1] = time[k] + tq;
					t += tq;
					rem_bt[i] -= tq;
					//k++;
				}
				else
				{
					//time[k+1] = time[k] + rem_bt[i];
					t += rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
					//k++;
				}
				cout<<"  "<<p[i]<<"  "<<t;//time[k];
			}
		}
		if(done == true)
			break;
	}

	for(int i = 0; i < n; ++i)
		tat[i] = bt[i] + wt[i];
}

void Process :: display()
{
	cout<<"\n\nProcess\t BT\tWT\tTAT\n";
	for(int i=0; i<n; ++i)
	{
		if(p[i] != p[i+1])
			cout<<p[i]<<"\t "<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
	}
	cout<<"WT is Wait Time\nTAT is Turn Around Time\n";
} 

int main()
{
	Process obj;
	int ch;
	cout<<"CPU Scheduling\n";
	cout<<"Algorithm - Round-Robin\n";
	obj.input();
	obj.compute();
	obj.display();
	return 0;
}
