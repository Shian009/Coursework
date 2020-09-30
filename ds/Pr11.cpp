#include <iostream>
#include<cstdlib>
#include"DoubllyLL.h"
using namespace std;


int main()
{
    int choice, element, position;
    DoublyLL <int>dl;
    while (1)
    {
        cout<<endl<<"--------MENU-------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;     
        cout<<"1- Insert an element"<<endl;
        cout<<"2- Delete an element"<<endl;
        cout<<"3- Display"<<endl;
        cout<<"4- Search an element"<<endl;
        cout<<"5- Reverse the Doublly linked list"<<endl;
        cout<<"6- Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

		switch ( choice )
        {

			case 1:
				cout<<"Enter the element to be inserted: ";
				cin>>element;
				dl.insert(element);
				cout<<endl;
				break;
           		 case 2:
				try
				{
				element=dl.Delete();
                		cout<<"Deleted element: "<<element;
                		}catch(...)
                		{
                			cout<<"No element present in the queue to be removed\n";
					cout<<"UNDERFLOW CONDITION!!!!\n";
                		}
				cout<<endl;
				break;
			case 3:
				try
				{
				dl.display();
				cout<<endl;
				}catch(...)
				{
					cout<<"No element present in the list to be displayed\n";
				}
				break;   
            		case 4:
				cout<<"Enter the element to be searched ";
				cin>>element;
				try
				{
				position = dl.search(element);
				if(position==-1)
				{
				    cout<<"Element not found\n";
				}
				else
				cout<<"Elemet found at position: "<<position<<"\n";
				}catch(...)
				{
					cout<<"No element present in the list\n";
				}	
				break;
			case 5:
				try
				{
				dl.reverse();
				cout<<endl;
				}catch(...)
				{
				cout<<"Noe list present to be reversed\n";
				}
				break;
			case 6: 
					exit(0);
					break;
			default:
				cout<<"Wrong choice"<<endl;
                		cout<<"Enter valid choice"<<endl;
        }
    }
    return 0;
}
