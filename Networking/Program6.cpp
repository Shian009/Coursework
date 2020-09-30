#include<iostream>
#include<cstring>
using namespace std;
class Address{
	int a[4],r[32];
	char x[16];
	public:
		void input(){
			for(int i=0;i<4;i++)
				a[i]=0;
			cout<<"\n IP Address in Dotted Decimal Notation: ";
			cin>>x;
		}
		void convert(){
		    int h=3,g;
		    for(int i=0;i<strlen(x);i++){
				g=0;
				if(isdigit(x[i])){
					g=(int)x[i]-'0';
				    a[h]=a[h]*10+g;
				}
				else
					h--;
			}
		}	
		int output(){
			int k=0;
			cout<<"\n Binary notation: "; 
			for(int i=0;i<32;i++)
				r[i]=0;
			for(int i=0;i<4;i++){
				binary(a[i],k);
				k+=8;
			}
			for(int i=31;i>=0;i--){
				if((i+1)%8!=0|| i==31)
					cout<<r[i];
				else
					cout<<"."<<r[i];
			}
		}
		int valid(){
			for(int i=0;i<4;i++){
				if(a[i]>255){
					cout<<"\n Invalid IP Address!!"<<endl;
					return 0;
				}
			}	
			return 1;
		}
		void binary(int n,int k){    
			while(n>0){
				r[k]=n%2;
				n=n/2;
				k++;
			}
		}
		void classes(){
			if(r[31]==0)
				cout<<"\n CLASS A \n";
			else if(r[30]==0)
				cout<<"\n CLASS B \n";
			else if(r[29]==0)
				cout<<"\n CLASS C \n";
			else if(r[28]==0)
				cout<<"\n CLASS D \n";
			else
				cout<<"\n CLASS E \n";
		} 
};
int main(){
	Address a;
	a.input();
	a.convert();
	int x=a.valid();
	if(x){
    	a.output();
    	a.classes();
	}
	return 0;
}
