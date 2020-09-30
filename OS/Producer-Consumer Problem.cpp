#include<iostream>
#include <stdlib.h>
using namespace std;
		
#define BUFFER_SIZE 5
int in = 0,out = 0;
int buffer[BUFFER_SIZE];

void producer()
{
	int nextProduced;
	cout<<"\nProducer: ";
	if(((in+1) % BUFFER_SIZE) == out)
	{
		cout<<"Buffer is Full\n";
	}
	else
	{
		cout<<"Enter the Item Produced: ";
		cin>>nextProduced; 
		buffer[in] = nextProduced;
		in = (in+1) % BUFFER_SIZE;
	}
}

void consumer()
{
	int nextConsumed;
	cout<<"\nConsumer: ";
	if(in == out)
	{
		cout<<"Buffer is Empty\n";	
	}
	else
	{
		nextConsumed = buffer[out];
		out = (out+1) % BUFFER_SIZE;
		cout<<"Consumed Item: "<<nextConsumed<<endl;
	}
}

int main()
{
    int opt;
    do
    {
		opt = rand()%2;
		if(opt == 0)
		{
			producer();
		}
		else 
		{
			consumer();
		}
    }while(1);
    return 0;
}
