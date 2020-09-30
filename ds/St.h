#include <iostream>
#include <cstdlib>
using namespace std;  
 
template<class T>
class Stack
{
	
	int tos;
	int n;
	T *values;
	public:	
	Stack()
	{
		tos=-1;
		cout<<"\nEnter the size of the stack you want to create:";
		cin>>n;
		values=new T[n];
	}
	
	int returntos()
	{
		return tos;
	}
	
	void push(T num)
	{
		++tos;
		if(tos==n)
		{
			--tos;
			throw "Overflow Occurs!";
		}
		else
			values[tos]=num;
	}
	
	int pop()
	{
		if(tos<0)
			throw "Underflow Occurs!";
		return values[tos--];
	}
	
	void clear()
	{
		if(tos!=-1)
		{	
			cout<<"\nList Cleared Succesfully";
			tos=-1;
		}	
		else
			cout<<"\nNothing To clear";
		
	}
	void input()
	{
		T x;
		cout<<"\nEnter ur input:\n";
		cin>>x;
		push(x);
	}
	void disp()
	{
		if(tos==-1)
			throw "\nList is Empty\n";
		for(int i=tos;i>=0;i--)
			cout<<values[i]<<"\n";

	}
	~Stack()
	{
		delete []values;
	}
};