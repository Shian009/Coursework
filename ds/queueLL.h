//Circular Linked List Implementation of Queue
#include<iostream>
using namespace std;
template<class T>
class QNode
{
	public:
		T info;
		QNode *next;
};
template<class T>
class Queue
{
	private:
		QNode<T> *r;
	public:
		Queue()
		{
			r = NULL;
		}
		void enqueue(T x);
		T dequeue();
		void display();
		void clear();
		bool isEmpty()
		{
			return (r == NULL);
		}
};

template<class T>
void Queue<T> :: enqueue(T x)
{
	QNode<T> *t = new QNode<T>();
	t->info = x;
	if(r == NULL)
	{	
		r = t;
		t->next = r;
		return;
	}
	t->next = r->next;
	r->next = t;
	r = t;
	return;
}

template<class T>
T Queue<T> :: dequeue()
{
	if(r == NULL)
		throw r;
	QNode<T> *t;
	if(r->next == r)
	{
		t = r;
		r = NULL;
	}
	else
	{
		t = r->next;
		r->next = t->next;
	}
	T x = t->info;
	delete t;
	return x;
}

template<class T>
void Queue<T> :: clear()
{
	if(r == NULL)
	{
		cout<<"\nQueue already cleared!\n";
		return;
	}
	QNode<T> *t = r->next;
	if(t == r)
	{
		r = NULL;
		delete t;
		cout<<"\nQueue cleared!\n";
		return;		
	}
	QNode<T> *p;
	while(r != NULL)
	{
		p = t;
		t = p->next;
		if(t == r)
			r = NULL;
		delete p;
	}
	if(t != NULL)
		delete t;
	cout<<"\nQueue cleared!\n";
}

template<class T>
void Queue<T> :: display()
{
	if(r == NULL)
	{
		cout<<"\nQueue Empty...!\n";
		return;
	}
	QNode<T> *p = r->next;
	cout<<"\nQueue\n";
	while(p != r)
	{
		cout<<p->info<<"\n";
		p = p->next;
	}
	cout<<p->info<<"\n";
}
