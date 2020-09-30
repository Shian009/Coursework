#include <iostream>
using namespace std;
#include "LinS.h"

int main(int argc,char* argv[])
{
	LL<int> a;
	while(true)
	{
		cout<<"\n1.push\n2.pop\n3.clear\n4.display\n5.exit\nEnter ur choice:\n";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:		a.enter();
						break;
			case 2:		try{
							cout<<a.pop();
						}
						catch(const char* msg)
						{
							cout<<msg;
						}
						break;
			case 3:		a.clear();
						break;
			case 4:		a.disp();
						break;
			case 5:		return 0;
			default:	cout<<"\nEnter again!\n";
		}
	}
	return 0;
}