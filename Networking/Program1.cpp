#include<iostream>
#include<cstdlib>
using namespace std;
class Message{
	int n,size,*m,*g,*t;
	public:
		void input(){
			cout<<"\n No. of Message Bits: ";
			cin>>n;
	 		cout<<"\n No. of Generator Bits: ";
	 		cin>>size;
	 		g=new int[size];
	 		m=new int[n+size-1];
	 		cout<<"\n Message: ";
			for(int i=0;i<n;i++)
     			cin>>m[i];
	 		cout<<"\n Generator: ";
	 		for(int i=0;i<size;i++)
     			cin>>g[i];
	    	t=new int[n+size-1];
	    }
	    void divide(){
			for(int i=0;i<n;i++){
				if(g[0]==t[i]){
					for(int j=0,k=i;j<size;j++,k++)
	               		t[k]=t[k]^g[j];
				} 
    		}
	 	} 	
 		void transmit(){
	 		for(int i=0;i<size-1;i++)
	 			m[n+i]=0;
	 		for(int i=0;i<n+size-1;i++)
	 			t[i]=m[i];
	 		divide();
	 		cout<<"\n Redundant Bits: ";
	 		for(int i=0;i<size-1;i++){
	   			cout<<t[n+i]<<" ";
	   		  	m[n+i]=t[n+i];
	 		}
	 		cout<<"\n Transmitted Message: ";
	 		for(int i=0;i<n+size-1;i++)
	 			cout<<m[i]<<" ";
	 		cout<<"\n";
 		}
 		void recieve(){w
	 		cout<<"\n Received Message: ";
	 		for(int i=0;i<n+size-1;i++){
	 			m[i]=rand()%2;
     			cout<<m[i]<<" ";
     			t[i]=m[i];
 			}
 			cout<<"\n";     		
 		}
 		void errdetect(){
 			divide();
	 		for(int i=0;i<size-1;i++){
	 		   	if(t[n+i]){
 		   	     	cout<<"\n Error!!";
 		   	     	return;
	 		   	} 
	 		}
	 		cout<<"\n No Error!!";
 		}			
};		

int main(){
	Message x;
	char ch;
	do{
		cout<<"\n At Sender's Site: \n";
		x.input();
		x.transmit();
		cout<<"\n At Reciever's Site: \n";
		x.recieve();
		x.errdetect();
		cout<<"\n Want to check again? (y/n) ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}
