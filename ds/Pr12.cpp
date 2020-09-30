#include <iostream>
#include<cstdlib>
using namespace std;

template <class T>
class node
{
	public:
	T info;
	node *next;

};

template <class T>
class CircularLL
{
	private: node <T> *last;
	public:
        void reverse();
    	int search(T ele);
        void add_end(T value);
        void add_begin(T value);
        void add_after(T value, int position);
        bool delete_element(T value);
        void display_list();
		CircularLL()
        {
            last = NULL;           
        }
};
	template <class T>
	void CircularLL<T>::add_end(T elem)
	{
	   node<T> *temp= new node<T>();
			temp->info=elem;
			temp->next=NULL;
	    if (last == NULL)
	    {
		last = temp;
		temp->next = last;   
	    }
	    else
	    {
		temp->next = last->next; 
		last->next = temp;
		last = temp;
	    }
	}
	template <class T>
	void CircularLL<T>::add_begin(T elem)
	{
	    		node<T> *temp= new node<T>();
			temp->info=elem;
			temp->next=NULL;
			    if (last == NULL)
			    {   
				last = temp;
				temp->next = last;   
			    }else
			    {
				temp->next = last->next;
				last->next = temp;
			    }
	}
	template <class T>
	void CircularLL<T>::add_after(T elem, int pos)
	{
		node<T> *temp= new node<T>();
			temp->info=elem;
			temp->next=NULL;
		if(last== NULL&& pos!=0)
		{
		    cout<<"first create the linked list\n";
		    return;
		}
		if (last == NULL&& pos==0)
		{   
		    last = temp;
		    temp->next = last;   
		    return;
		}
	     node<T> *s;
	     s = last->next;

		for (int i = 0;i < pos-1;i++)
	   	{
		s = s->next;
		if (s == last->next)
		{
		    cout<<"There are less than ";
		    cout<<pos<<" in the list"<<endl;
		    return;
		}
	       }
	       if(pos==0)
	       {
	       	this->add_begin(elem);
	       	return;
	       }
	    temp->next = s->next;
	    s->next = temp;
		if (s == last)
	    { 
		last=temp;
	    }
	}
	template <class T>
	int CircularLL<T>:: search(T ele)
	{
	
		int count=0;
	    	node<T> *t;
		t=last->next;
		if(last == NULL)
		{
			throw last;
		}
		while(t!=last)
		{
			count++;
			if(t->info==ele)
			{	
				return count;
			}
			t=t->next;
		}
		if(t==last &&t->info==ele)
		{
		   return count++;
		}

		 return -1;
	}
	template <class T>
	void CircularLL<T>::display_list()
	{
	     node<T> *s;
	    if (last == NULL)
	    {
		throw last;
	    }
	    s = last->next;
	     while (s != last)
	    {
		cout<<s->info<<"->";
		s = s->next;
	    }
	    cout<<s->info<<endl;
	}

	template <class T>
	bool CircularLL<T>::delete_element(T value)
	{
	    node<T> *temp, *s;
	    s = last->next;
	    if(last == NULL)
	    {
	    	return temp;
	    }
	    if (last->next == last && last->info == value)  
	    {
		temp = last;
		last = NULL;
		delete(temp);
		return true;
	    }
	    if (s->info == value)  
	    {
		temp = s;
		last->next = s->next;
		delete (temp);
		return true;
	    }

		while (s->next != last)
	    	{
			if (s->next->info == value)    
			{
			    temp = s->next;
			    s->next = temp->next;
			    delete(temp);
			    return true;
			}
			s = s->next;
	    	}

		if (s->next->info == value)    
	   	 {
			temp = s->next;
			s->next = last->next;
			delete(temp);		
			last = s;
			return true;
	    	}
	return false;
	}

	template <class T>
	void CircularLL<T>:: reverse()
	{
	   if(last==NULL)
	   {
	   return;
	   }
	   node<T> *p,*q,*t;
	   p=t=last->next;
	   q=last;
	   while(t!=last)
	   {
		   p=p->next;
		   t->next=q;
		   q=t;
		   t=p;
	   }
	   p->next=q;
	   last=p;
	   cout<<"Linked list is reversed\n";
	}
int main()
{
    int choice, element, position,ele;
    bool ch;
  CircularLL <int>cl;
    while(true){
    	cout<<"\n----Menu----";     
        cout<<"\n1.Add at end";
        cout<<"\n2.Add at beginning";
        cout<<"\n3.Add after";
        cout<<"\n4.Delete";
        cout<<"\n5.search";
    	cout<<"\n6.reverse";
    	cout<<"\n7.display";
    	cout<<"\n8.exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;

		switch(choice)
        {
			case 1:
				cout<<"\nEnter the element: ";
				cin>>element;
				cl.add_end(element);
				cout<<endl;
				break;
			case 2:
				cout<<"\nEnter the element: ";
				cin>>element;
				cl.add_begin(element);
				cout<<endl;
				break;
			case 3:
				cout<<"\nEnter the element: ";
				cin>>element;
				cout<<"\nInsert element after position: ";
				cin>>position;
				cl.add_after(element, position);
				cout<<endl;
				break;
			case 4:
				cout<<"\nEnter the element for deletion: ";
				cin>>element;
				try{
				ch=cl.delete_element(element);
				if(ch)
				cout<<"Element deleted\n";
				else
				cout<<"Element not deleted\n";
				cout<<endl;
				}catch(...)
				{
                			cout<<"No element present in the queue to be removed\n";
					cout<<"UNDERFLOW CONDITION!!!!\n";
				}
				break;
			case 5:
				cout<<"Enter the elemeent to be searched ";
				cin>>ele;
				try
				{
				position=cl.search(ele);
				if(position==-1)
				{
				    cout<<"Element not found\n";
				}else
				cout<<"Element found at position: "<<position<<"\n";
				}catch(...)
				{
					cout<<"No element present in the list\n";
				}
				break;
			case 6:  
		        	try
		        	{
		        	cl.reverse();
		        	}catch(...)
		        	{
		        		cout<<"Noe list present to be reversed\n";
		        	}
		        	break;
			case 7:		
		        	try
		        	{
		        	cl.display_list();
		        	}
		        	catch(...)
		        	{
		        		cout<<"No element present in the list to be displayed\n";
		        	}
				break;
		    	case 8: 
		        	exit(0);
		       		break;
		    default: 
		        cout<<"Wrong choice\n";
		        cout<<"Please enter valid choise\n";
        }
    }
    return 0;
}




