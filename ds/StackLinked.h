#include <iostream>
using namespace std;
template <class T>
class Node
{
	public :
		T info;
		Node<T> *next;
};
template <class T>
class Stack
{
	
	public :
	Node<T> *first;
	Stack()
	{
		first=NULL;
	}
	void push(T x)
	{
		Node<T> *p=new Node<T>;
		if(p==NULL)
			throw "Empty List";
		p->info=x;
		p->next=first;
		first=p;
	}
	T pop()
	{
		if(first==NULL)
		{	
			throw "empty list";
		}
		Node<T> *p=first;
		first=first->next;
		T x=p->info;
		delete p;
		return x;
		
	}
	bool empty()
	{
		if(first==NULL)
			return true;
		return false;
	}
	void display()
	{
		Node<T> *p;
		cout<<"The stack contains : ";
		for(p=first;p!=NULL;p=p->next)
			cout<<(p->info)<<" ";
		cout<<endl;
	}
};
