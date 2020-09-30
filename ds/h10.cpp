#include <iostream>
using namespace std;

template <class T>
class Node
{
	public:
		T info;
		Node *next;
};

template <class T>
class LL
{
	private:
		Node<T> *first,*last;
		
	public:
		LL()
		{
			first=last=NULL;
		}
		
		void insertLast(T x)
		{
			Node<T> *t=new Node<T>;
			t->info=x;
			t->next=NULL;
			
			if(first==NULL)
			{
				first=last=t;
				return;
			}
			
			last->next=t;
			last=t;
			return;
		}
		
		bool insertAfter(T x, T target)
		{
			Node<T> *t=new Node<T>;
			Node<T> *p=first;
			t->info=x;
			
			if(first==NULL)
			{
				t->next=NULL;
				first=last=t;
				return true;
			}
			
			while(p!=last)
			{
				if(p->info==target)
				{
					t->next=p->next;
					p->next=t;
					return true;
				}
				p=p->next;
			}
			
			if(last->info==target)
			{
				t->next=NULL;
				last->next=t;
				last=t;
				return true;
			}
			
			return false;
		}
		
		bool insertBefore(T x, T target)
		{
			Node<T> *t=new Node<T>;
			Node<T> *p=first;
			t->info=x;
			
			if(first==NULL)
			{
				t->next=NULL;
				first=last=t;
				return true;
			}
			
			if(first->info==target)
			{
				t->next=first;
				first=t;
				return true;
			}
			
			while(p!=last)
			{
				if((p->next)->info==target)
				{
					t->next=p->next;
					p->next=t;
					return true;
				}
				p=p->next;
			}
			
			return false;
		}
		
		bool search(T target, int &index)
		{
			Node<T> *p=first;
			
			while(p!=NULL)
			{
				if(p->info==target)
				{
					return true;
				}
				p=p->next;
				index++;
			}
				
			return false;
		}
		
		void reverse()
		{
			Node<T> *p,*q,*t;
			p=NULL;
			q=first;
			last=first;
			
			if(first!=NULL)
			{
				p=first->next;
				first->next=NULL;
			}
			
			while(p!=NULL)
			{
				t=p->next;
				p->next=q;
				q=p;
				p=t;
			}
			
			first=q;
			return;
		}
		
		void concat(LL &p2)
		{
			Node<T> *t=p2.first;
			
			while(t!=NULL)
			{
				this->insertLast(t->info);
				t=t->next;
			}
			
			while(p2.first!=NULL)
			{
				t=p2.first;
				p2.first=p2.first->next;
				delete t;
			}
			return;
		}
		
		void operator+(LL &p2)
		{
			Node<T> *t=p2.first;
			
			while(t!=NULL)
			{
				this->insertLast(t->info);
				t=t->next;
			}
			
			while(p2.first!=NULL)
			{
				t=p2.first;
				p2.first=p2.first->next;
				delete t;
			}
			return;
		}
		
		void deleteFirst()
		{
			Node<T> *t=first;
			
			if(first==NULL)
				throw "UNDERFLOW";
				
			if(first==last)
				first=last=NULL;
			else
				first=first->next;
			delete t;
			return;
		}
		
		bool deleteTarget(T target)
		{
			Node<T> *t=first;
		
			if(first==NULL)
				throw "UNDERFLOW";
			
			Node<T> *p=first->next;
			if(first->info==target)
			{
				if(first==last)
					first=last=NULL;
				else
					first=first->next;
				delete t;
				return true;
			}
			
			while(p!=last)
			{
				if(p->info==target)
				{
					t->next=p->next;
					delete p;
					return true;
				}
				t=t->next;
				p=p->next;
			}
			
			if(last->info==target)
			{
				last=t;
				delete p;
				return true;
			}
			
			return false;
		}
		
		void display()
		{
			Node<T> *t=first;
			if(first==NULL)
			{
				cout<<"Empty!";
				return;
			}
			
			while(t!=NULL)
			{
				cout<<t->info<<" ";
				t=t->next;
			}
			return;
		}
};

int main()
{
	int ch,index;
	char n;
	Node<int> *t;
	LL<int> L1,L2;
	int data,target;
	bool f;
	
	while(1)
	{
		index=0;
		cout<<"\n\n\tMENU:\n\t1. InsertLast\n\t2. InsertAfter\n\t3. InsertBefore\n\t4. Search\n\t5. Reverse\n\t6. Concatenate";
		cout<<"\n\t7. Operator+ Concatenate\n\t8. DeleteFirst\n\t9. DeleteTarget\n\t10. Display\n\t11. Exit\n\nEnter your choice: ";
		cin>>ch;
		try{
				switch(ch)
				{
					case 1: cout<<"\nEnter element to be inserted: ";
						cin>>data;
						L1.insertLast(data);
						cout<<"\nInsertion successful!";
						break;
					
					case 2: cout<<"\nEnter element to be inserted: ";
						cin>>data;
						cout<<"\nEnter the target: ";
						cin>>target;
						f=L1.insertAfter(data,target);
						
						if(f==true)
							cout<<"\nInsertion successful!";
						else
							cout<<"\nTarget not found. Insertion unsuccessful!";
						break;
						
					case 3: cout<<"\nEnter element to be inserted: ";
						cin>>data;
						cout<<"\nEnter the target: ";
						cin>>target;
						f=L1.insertBefore(data,target);
						
						if(f==true)
							cout<<"\nInsertion successful!";
						else
							cout<<"\nTarget not found. Insertion unsuccessful!";
						break;
						
					case 4: cout<<"\nEnter element to be searched: ";
						cin>>data;
						f=L1.search(data,index);
						if(f==false)
							cout<<"\nElement NOT found!";
						else
							cout<<"\nElement found! Index location: "<<index;	
						break;
						
					case 5: L1.reverse();
						cout<<"\nList reversed successfully!";
						break;
						
					case 6: do
						{
							cout<<"\nEnter element to be enqueued in second list: ";
							cin>>data;
							L2.insertLast(data);
							cout<<"\nEnter more?(Y/N) ";
							cin>>n;
						}
						while(n=='Y'||n=='y');
						
						cout<<"\nSecond list is: ";
						L2.display();
						
						L1.concat(L2);
						
						cout<<"\nConcatenation successful!";
						break;
						
					case 7: do
						{
							cout<<"\nEnter element to be enqueued in second list: ";
							cin>>data;
							L2.insertLast(data);
							cout<<"\nDo you want to enter more?(Y/N) ";
							cin>>n;
						}
						while(n=='Y'||n=='y');
						
						cout<<"\nSecond list is: ";
						L2.display();
						
						L1+(L2);
						
						cout<<"\nConcatenation successful!";
						break;
					
					case 8: 
							L1.deleteFirst();
							cout<<"\nFirst element deleted.";
						break;
						
					case 9: 
							cout<<"\nEnter target to be deleted: ";
							cin>>data;
							f=L1.deleteTarget(data);
							if(f==true)
								cout<<"\nElement was found and deleted.";
							else
								cout<<"\nElement NOT found!";
						
						break;
						
					case 10: cout<<"\nLinked list is: ";
						L1.display();
						break;
						
					case 11: return 0;
					
					default: cout<<"\nInvalid choice!";
				}
		}
		catch(const char* e)
				{
					cout<<<<e;
				}
	}
}
