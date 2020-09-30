//Linked List implementation of Stack
#include<iostream>
using namespace std;
template<class T>
class Node
{
	public:
		T info;
		Node *next;
};
template<class T>
class Stack
{
	private:
		Node<T> *first;
	public:
		Stack()
		{
			first=NULL;
		}
		void push(T val)
		{
			Node<T> *p=new Node<T>();
			p->info=val;
			p->next=first;
			first=p;
		}
		T pop()
		{
			Node<T> *p=first;
			if(p==NULL)
				throw p;
			first=first->next;
			T value=p->info;
			delete p;
			return value;
		}
		void display()
		{
			Node<T> *p=first;
			if(p==NULL)
				cout<<"\nStack Empty\n";
			else
			{
				cout<<"\nThe elements are:\n";
				while(p!=NULL)
				{
					cout<<p->info<<"\n";
					p=p->next;
				}
			}
		}
		void clear()
		{
			Node<T> *p;
			if(first==NULL)
				throw first;
			else
			{
				while(first!=NULL)
				{
					p=first;
					first=first->next;
					delete p;
				}
			}
		}
		bool isEmpty()
		{
			return (first == NULL);
		}
		T stackTop()
		{
			return first->info;
		}
		Node<T>* returnFirst()
		{
			return first;
		}
};
