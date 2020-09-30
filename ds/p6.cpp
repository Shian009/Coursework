#include <iostream>
#include <cstdlib>
#include "CQ.h"
using namespace std;

int main(int arg,char* args[])
	{

		int ch;
		Queue<int> st;
		while(true)
		{
			cout<<"\n\n\tMenu:\n\t1. Enqueue\n\t2. Dequeue\n\t3. show\n\t4.Exit";
			cout<<"\tPlease enter your choice: ";
			cin>>ch;
			try
			{
				switch(ch)
				{
					case 1: 	st.input();
								break;
						
					case 2: 	cout<<"Popped Element is:"<<st.dequeue();
			 					break;

					case 3:		st.show();
								break;
					case 4:		exit(0);
					
					default: 	cout<<"\nInvalid choice!";
				}
			}
			catch(const char* msg)
			{
				cout<<msg;
			}
		}
	}
