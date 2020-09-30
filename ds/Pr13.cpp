#include <iostream>
using namespace std;
template <class T1,class T2>
class Node
{
	public :
	T1 coeff;
	T2 exp;
	Node *next;
};
template <class T1,class T2>
class LLP
{
	
	Node<T1,T2> *first;
	public :
	LLP()
	{
		first=NULL;
	}
	LLP add(LLP b)
	{
		LLP result;
		Node<T1,T2> *p=first;
		Node<T1,T2> *q=b.first;
		Node<T1,T2> *r,*t;
		result.first=new Node<T1,T2>();
		r=result.first;
		while(p!=NULL && q!=NULL)
		{
			t=new Node<T1,T2>();
			if(p->exp==q->exp)
			{
				t->coeff=p->coeff+q->coeff;
				t->exp=p->exp;
				r->next=t;
				r=t;
				p=p->next;
				q=q->next;
			}
			else if(p->exp < q->exp)
			{
				t->coeff=q->coeff;
				t->exp=q->exp;
				r->next=t;
				r=t;
				q=q->next;
			}
			else
			{
				t->coeff=p->coeff;
				t->exp=p->exp;
				r->next=t;
				r=t;
				p=p->next;
			}
		}
		while(p!=NULL)
		{
			t=new Node<T1,T2>();
			t->coeff=p->coeff;
			t->exp=p->exp;
			r->next=t;
			r=t;
			p=p->next;
		}
		while(q!=NULL)
		{
			t=new Node<T1,T2>();
			t->coeff=q->coeff;
			t->exp=q->exp;
			r->next=t;
			r=t;
			q=q->next;
		}
		Node<T1,T2> *x=result.first;
		result.first=result.first->next;
		delete x;
		return result;
	}
	void insertinorder(T1 x,T2 y)
	{
		Node<T1,T2> *t=new Node<T1,T2>();
		t->coeff=x;
		t->exp=y;
		t->next=NULL;
		if(first==NULL)
			first=t;
		else
		{
			Node<T1,T2> *p,*q;
			int f=0,c=0;
			for(p=first;p!=NULL;p=p->next)
			{
				if((p->exp)==y)
				{
					p->coeff=p->coeff+x;
					c=1;
				}
				else
				{
					if((p->exp)<y)
					{
						if(p==first)
						{
							t->next=p;
							first=t;
						}
						else
						{
							t->next=p;
							q->next=t;
						}
						f=1;
						c=1;
					}
					q=p;
				}
				if(c==1)
					break;
			}
			if(f==0)
				q->next=t;
		}
	}
	void display()
	{
		Node<T1,T2> *p;
		cout<<"The polynomial is : ";
		for(p=first;p!=NULL;p=p->next)
		{
			
			
			{
			if(p->next==NULL)
				cout<<"("<<(p->coeff)<<"*x^"<<(p->exp)<<")";
			else
				cout<<"("<<(p->coeff)<<"*x^"<<(p->exp)<<")+";
			}
		}
		cout<<endl;
	}
};
int main()
{
	LLP<double,int> n1,n2,result;
	cout<<"Enter 1st polynomial"<<endl;
	int ch1;
	do
	{
		cout<<"Enter your coefficient and exponent rescectively :"<<endl;
		double a;
		int b;
		cin>>a;
		cin>>b;
		n1.insertinorder(a,b);
		cout<<"Enter 0 to exit else any number to continue entering"<<endl;
		cin>>ch1;
	}while(ch1!=0);
	n1.display();
	cout<<"Enter 2nd polynomial"<<endl; 
	int ch2;
	do
	{
		cout<<"Enter your coefficient and exponent rescectively :"<<endl;
		double a;
		int b;
		cin>>a;
		cin>>b;
		n2.insertinorder(a,b);
		cout<<"Enter 0 to exit else any number to continue entering :"<<endl;
		cin>>ch2;
	}while(ch2!=0);
	n2.display();
	result=n1.add(n2);
	cout<<"After adding polynomials : "<<endl;
	result.display();
}
