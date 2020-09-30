#include <iostream>
using namespace std;

template<class T>
class Queue
{
	
	int f,l,n;
	T *values;
	public:	
	Queue()
	{
		f=l=-1;
		cout<<"\nEnter the size of the array:\n";
		cin>>n;
		values=new T[n];
	}

	void enqueue(T num)

	{
		if(f==-1)
		{
			f=l=0;
			values[l]=num;
		}	
		else 
			if(f==(l+1)%n)
				throw "\noverflow occurs!\n";
			else
			{
				l=(l+1)%n;
				values[l]=num;
			}
		
	}
	
	T dequeue()
	{
		T x;
		if(f==-1)
			throw "\nUnderflow Exception\n";
		else 
			if(f==l)
			{
				x=values[f];
				f=l=-1;
			}
			else
			{
				x=values[f];
				f=(f+1)%n;
			}
		return x;

	}
	
	void input()
	{
		T x;
		cout<<"\nEnter ur input:\n";
		cin>>x;
		enqueue(x);
	}
	void show()
	{
		if(f==-1||l==-1)
		{
			cout<<"\nNothing to display!\n";
			return;
		}
		int k=f,j=l;
		while(k!=j)
		{
			cout<<values[k]<<"\n";
			k=(k+1)%n;
		}
		cout<<values[k];
	}
};