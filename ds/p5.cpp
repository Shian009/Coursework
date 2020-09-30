#include <iostream>
#include <cstdlib>
#include "St.h" 
using namespace std;  

int main(int arg,char* args[])
	{

		int ch;
		Stack<int> st;
		while(true)
		{
			cout<<"\n\n\tMenu:\n\t1. Push\n\t2. Pop\n\t3. clear\n\t4. Display\n\t5. Exit";
			cout<<"\tPlease enter your choice: ";
			cin>>ch;
			try
			{
				switch(ch)
				{
					case 1: 	
									st.input();

								break;
						
					case 2: 	
									cout<<"Popped Element is:"<<st.pop();
									break;
							
					case 3: 	st.clear();
								break;
							
					case 4:		
									st.disp();
									break;
					case 5:		exit(0);
					
					default: 	cout<<"\nInvalid choice!";
				}
				
		}
		catch(const char* msg)
					{
							cout<<msg;
					}
					
			
	}
}
