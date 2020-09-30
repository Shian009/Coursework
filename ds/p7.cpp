#include "LinQ.h"
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
	LL a;
	int b;
	while(true)
	{
		cout<<"\n1.enqueue\n2.dequeue\n3.show\n4.exit\nEnter ur choice:\n";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:		cout<<"\nEnter input: ";
						cin>>b;
						a.enq(b);
						break;
			case 2:		try{
							cout<<"Deleted Element: "<<a.deq();
						}
						catch(const char* msg)
						{
							cout<<msg;
						}
						break;
			case 3:		try{
							a.show();
						}
						catch(const char* msg)
						{
							cout<<msg;
						}
						break;
			case 4:		return 0;
			default:	cout<<"\nEnter again!\n";
		}
	}
	return 0;
}