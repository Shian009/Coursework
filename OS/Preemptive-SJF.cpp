#include<iostream>
using namespace std;
class Process
{
	private: 
		int n;
		int bt[10];
		char p[10];
		int wt[10];
		int tat[10];
		int at[10];
		int rem_bt[10];   //remaining burst time
		//int time[30];  //for gnatt chart

		void swap(int, int);
		void sortAT();
		//void sortBT(int, int);

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
	cout<<"Enter the Burst Time (BT) and Arrival Time (AT) for:\n";
	for(int i=0; i<n; ++i)
	{
		cout<<"Process "<<ch<<": ";
		cin>>bt[i];
		cin>>at[i];
		p[i] = ch++;
		rem_bt[i] = bt[i];
	}
}

void Process :: swap(int i, int pos)
{
	int temp = at[i];
	at[i] = at[pos];
	at[pos] = temp;

	temp = bt[i];
	bt[i] = bt[pos];
	bt[pos] = temp;

	temp = rem_bt[i];
	rem_bt[i] = rem_bt[pos];
	rem_bt[pos] = temp;
		
	char ctemp = p[i];
	p[i] = p[pos];
	p[pos] = ctemp;
}
		
void Process :: sortAT()
{
	for(int i=0; i<n-1; ++i)
	{
		int pos = i;
		for(int j=i+1; j<n; ++j)
		{
			if(at[j]<at[pos])
				pos = j;
		}
		swap(i,pos);
	}
}		

void Process :: compute()
{
  	int t = 0, pcom = 0, shortest = 0, prev = -1, count = 0;
  	int min = 1000;
  	int finishTime;
  	bool check = false;
  	sortAT();
  	cout<<"\nGnatt Chart:\n";
  	while(pcom < n)
  	{
  		for(int i = 0; i < n; ++i)
  		{
  			if((at[i] <= t) && (rem_bt[i] < min && rem_bt[i] > 0))
  			{
  				shortest = i;
  				min = rem_bt[i];
  				check = true;
  			}
  		}
  		if(!check)
  		{
  			t++;
  			count++;
  			continue;
  		}
  		rem_bt[shortest]--;

  		min = rem_bt[shortest];
  		if(min == 0)				//process is complete
  		{
  			min = 1000;
  			pcom++;
  			check = false;

  			finishTime = t + 1;		//finish time of the current process
  			wt[shortest] = finishTime - bt[shortest] - at[shortest];

  			if(wt[shortest] < 0)
  				wt[shortest] = 0;
  		}
  		if(prev != shortest)
  		{
  			if(count != 0)
  			{
  				cout<<t-count<<"  Idle  ";
  			}
  			cout<<t<<"  "<<p[shortest]<<"  ";
  		}
  		count = 0;
  		prev = shortest;
  		t++;
  	}
  	cout<<t;

  	for(int i = 0; i < n; ++i)
  		tat[i] = bt[i] + wt[i];
}

void Process :: display()
{
	cout<<"\n\nProcess\t BT\tAT\tWT\tTAT\n";
	for(int i=0; i<n; ++i)
	{
		if(p[i] != p[i+1])
			cout<<p[i]<<"\t "<<bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
	}
	cout<<"WT is Wait Time\nTAT is Turn Around Time\n";
} 

int main()
{
	Process obj;
	int ch;
	cout<<"CPU Scheduling\n";
	cout<<"Algorithm - Preemptive SJF\n";
	obj.input();
	obj.compute();
	obj.display();
	return 0;
}