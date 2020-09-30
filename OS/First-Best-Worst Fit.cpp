#include<iostream>
using namespace std;

void firstFit(int b[], int m, int p[], int n)
{
	int alloc[n];
	int available[m];
	for(int i = 0; i < n; ++i)
		alloc[i] = -1;
	for(int j =0; j < m; ++j)
		available[j] = 1;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(b[j] >= p[i] && available[j])
			{
				alloc[i] = j;
				available[j] = 0;
				break;
			}
		}
	}
	cout<<"\nProcess No.\tProcess Size\tBlock No.\t Block Size\n";
	for(int i = 0; i < n; ++i)
	{
		cout<<i+1<<"\t\t"<<p[i]<<"\t\t";
		if(alloc[i] != -1)
			cout<<alloc[i] + 1<<"\t\t "<<b[alloc[i]]<<endl;
		else
			cout<<"Not Allocated\t -"<<endl;
	}
}

void bestFit(int b[], int m, int p[], int n)
{
	int alloc[n];
	int available[m];
	for(int i = 0; i < n; ++i)
		alloc[i] = -1;
	for(int j =0; j < m; ++j)
		available[j] = 1;
	for(int i = 0; i < n; ++i)
	{
		int best = -1;
		for(int j = 0; j < m; ++j)
		{
			if(b[j] >= p[i] && available[j])
			{
				if((best == -1) || (b[j] < b[best]))
				{
					alloc[i] = j;
					best = j;
				}
			}
		}
		available[alloc[i]] = 0;
	}
	cout<<"\nProcess No.\tProcess Size\tBlock No.\t Block Size\n";
	for(int i = 0; i < n; ++i)
	{
		cout<<i+1<<"\t\t"<<p[i]<<"\t\t";
		if(alloc[i] != -1)
			cout<<alloc[i] + 1<<"\t\t "<<b[alloc[i]]<<endl;
		else
			cout<<"Not Allocated\t -"<<endl;
	}
}

void worstFit(int b[], int m, int p[], int n)
{
	int alloc[n];
	int available[m];
	for(int i = 0; i < n; ++i)
		alloc[i] = -1;
	for(int j =0; j < m; ++j)
		available[j] = 1;
	for(int i = 0; i < n; ++i)
	{
		int wst = -1;
		for(int j = 0; j < m; ++j)
		{
			if(b[j] >= p[i] && available[j])
			{
				if((wst == -1) || (b[j] > b[wst]))
				{
					alloc[i] = j;
					wst = j;
				}
			}
		}
		available[alloc[i]] = 0;
	}
	cout<<"\nProcess No.\tProcess Size\tBlock No.\t Block Size\n";
	for(int i = 0; i < n; ++i)
	{
		cout<<i+1<<"\t\t"<<p[i]<<"\t\t";
		if(alloc[i] != -1)
			cout<<alloc[i] + 1<<"\t\t "<<b[alloc[i]]<<endl;
		else
			cout<<"Not Allocated\t -"<<endl;
	}
}

int main()
{
	int m,n,ch;
		cout<<"Enter no. of memory blocks: ";
		cin>>m;
		int	b[m];
		cout<<"Enter the sizes of the blocks (in kB): \n";
		for(int i = 0; i < m; ++i)
		{
			cout<<"Block "<<i+1<<": ";
			cin>>b[i];
		}
		cout<<"\nEnter no. of processes: ";
		cin>>n;
		int p[n];
		cout<<"Enter the sizes of the processes (in kB): \n";
		for(int i = 0; i < n; ++i)
		{
			cout<<"Process "<<i+1<<": ";
			cin>>p[i];
		}
	do
	{
		cout<<"\nMENU\n"
			<<"1.First Fit Allocation\n"
			<<"2.Best Fit Allocation\n"
			<<"3.Worst Fit Allocation\n"
			<<"4.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: firstFit(b,m,p,n);
					break;
			case 2: bestFit(b,m,p,n);
					break;
			case 3: worstFit(b,m,p,n);
					break;
			case 4: return 0;
			default:cout<<"Invalid choice!! Please choose a valid option!\n";
		}
	}while(ch != 4);
	return 0;
}