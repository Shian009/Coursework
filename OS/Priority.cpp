#include<iostream>
#include<stdlib.h>
using namespace std;
class Process
{
	private:
		int n;
		int at[10];
		int bt[10];
		int wt[10];
		int tat[10];
		int time[10];
		int prio[10];
		char p[10];
		
		void swap(int, int);
		void sortAT();
		void sortPr(int,int);
		void gnatt_chart1();
		void gnatt_chart2();
		
	public:
		void input1();
		void input2();
		void calc_prio1();
		void calc_prio2();
		void display();
};

void Process :: input1()
{
	char ch = 'A';
	cout<<"Enter the no. of processes (max 10): ";
	cin>>n;
	cout<<"Enter the Burst Time (BT) and Priority (Pr) for:\n";
	for(int i=0; i<n; ++i)
	{
		cout<<"Process "<<ch<<": ";
		cin>>bt[i];
		cin>>prio[i];
		at[i] = 0;
		p[i] = ch++;
	}
}
		
void Process :: input2()
{
	char ch = 'A'; 
	cout<<"Enter the no. of processes (max 10): ";
	cin>>n;
	cout<<"Enter the Burst Time (BT), Priority (Pr) and Arrival Time (AT) for:\n";
	for(int i=0; i<n; ++i)
	{
		cout<<"Process "<<ch<<":- \n";
		cout<<"\tBT: ";
		cin>>bt[i];
		cout<<"\tPr: ";
		cin>>prio[i];
		cout<<"\tAT: ";
		cin>>at[i];
		p[i] = ch++;
	}
}

void Process :: calc_prio1()
{
	sortPr(0,n-1);			
	wt[0] = 0;
	tat[0] = bt[0];
	for(int i=1; i<n; ++i)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = wt[i] + bt[i];
	}
	cout<<"\nGnatt Chart: \n";
	gnatt_chart1();
}
		
void Process :: gnatt_chart1()
{
	cout<<0<<"\t";
	for(int i=0; i<n; ++i)
	{
		 cout<<tat[i]<<"\t";
	}
	cout<<endl<<"    ";
	for(int i=0; i<n; ++i)
	{
		cout<<p[i]<<"       ";
	}
	cout<<endl<<endl;
}
		
void Process :: swap(int i, int pos)
{
	int temp = at[i];
	at[i] = at[pos];
	at[pos] = temp;

	temp = bt[i];
	bt[i] = bt[pos];
	bt[pos] = temp;
	
	temp = prio[i];
	prio[i] = prio[pos];
	prio[pos] = temp;
		
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

void Process :: sortPr(int x, int y)
{
	for(int i=x; i<=y-1; ++i)
	{
		int pos = i;
		for(int j=i+1; j<=y; ++j)
		{
			if(prio[j]<prio[pos])
				pos = j;
		}
		swap(i,pos);
	}
	int count,index;
	for(int i=x; i<=y-1; ++i)
	{
		int pos = i;
		count = 0;
		while(prio[i] == prio[pos+1] && pos<y+1)
		{	
			count++;
			pos++;
		}
		//cout<<"\nCount: "<<count; 
		for(int j=count; j>0; --j)
		{
			index =(int) rand() % (j+1);
			//cout<<"\nIndex: "<<index<<endl;
			swap(i, i+index);
		}
	}
}

void Process :: calc_prio2()
{
	sortPr(0,n-1);
	sortAT();
	time[0] = at[0];
	for(int i=0; i<n; ++i)
	{				
		if(time[i] < at[i])
		{
			time[i+1] = at[i];
			n++;
			for(int j=n-1; j>=i+1; j--)
			{
				p[j] = p[j-1];
				at[j] = at[j-1];
				bt[j] = bt[j-1];
			}
		}
		else
			time[i+1] = time[i] + bt[i];
		wt[i] = time[i] - at[i];
		tat[i] = wt[i] + bt[i];
		
		//cout<<"   "<<p[i]<<"       "<<at[i]<<"     "<<bt[i]<<"     "<<wt[i]<<"     "<<tat[i]<<endl;
		
		int index = i;
		while(time[i+1]>=at[index+1] && index<n)
		{
			 index++;
		}
		sortPr(i+1,index);
	}
	cout<<"\nGnatt chart: \n";
	gnatt_chart2();
}
		
void Process :: gnatt_chart2()
{
	for(int i=0; i <= n; ++i)
	{
		cout<<time[i]<<"\t";
	}
	cout<<endl<<"    ";
	for(int i=0; i<n; ++i)
	{
		if(p[i] == p[i+1])
			cout<<"Idle"<<"     ";
		else
			cout<<p[i]<<"       ";
	}
	cout<<endl<<endl;
}
	
void Process :: display()
{
	cout<<"Process    AT    BT    Pr    WT    TAT\n";
	for(int i=0; i<n; ++i)
	{
		if(p[i] != p[i+1])
			cout<<"   "<<p[i]<<"       "<<at[i]<<"     "<<bt[i]<<"     "<<prio[i]<<"     "<<wt[i]<<"     "<<tat[i]<<endl;
	}
	cout<<"WT is Wait Time\nTAT is Turn Around Time\n";
}

int main()
{
	Process obj;
	int ch;
	cout<<"CPU Scheduling\n";
	cout<<"Algorithm - Priority\n";
	do
	{
		cout<<"\nMENU: \n";
		cout<<"1. Without Arrival Time\n"
			<<"2. With Arrival Time\n"
			<<"3. Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:	obj.input1();
					obj.calc_prio1();
					obj.display();
					break;
			case 2: obj.input2();
					obj.calc_prio2();
					obj.display();
					break;
			case 3: return 0;
			default: cout<<"Invalid choice!! Please choose a valid option!\n";
		}
	}while(ch!=3);
	return 0;
} 
