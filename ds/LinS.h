#include <iostream>
using namespace std;
template<class T>
class Node
{	
public:
	T info;
	Node* next;
};
template<class T>
class LL{

		Node<T> *first;
	public:
		LL()
		{
			first=NULL;			
		}
		void enter()
		{
			cout<<"Enter the element u want to enter";
						T x;
						cin>>x;
						push(x);
		}
		void push(T in)
		{
			Node<T> *p =new Node<T>();
			p->info=in;
			p->next=first;
			first=p;
		}
		T pop()
		{
			Node<T> *p=first;
			if(first==NULL)
				throw "underflow occurs!";
			first=first->next;
			T x=p->info;
			delete p;
			return x;
		}
		void clear()
		{
			Node<T> *p=first;
			if(p==NULL)
			{
				cout<<"\nNothing to clear!\n";
				return;
			}
			while(p!=NULL)
			{	
				first=first->next;
				delete p;
				p=first;
			}
			cout<<"\nlist cleared prperly!\n";
		}
		void disp(){
			Node<T> *p=first;
			if(p==NULL)
				cout<<"\nNo element to display!\n";
			while(p!=NULL)
			{
				cout<<p->info<<"\n";
				p=p->next;

			}
		}
		bool empty()
		{
			if(first==NULL)
				return true;
			return false;
		}
};