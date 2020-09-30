#include<iostream>
using namespace std;
void TOH(int n,char A,char C,char B)
{
	if(n==1)
	{
		cout<<n<<"\ndisc moved from "<<A<<" to "<<B<<"\n";
		return;
	}
	else
	{
		TOH(n-1,'A','C','B');
		cout<<n<<"\ndisc moved from "<<A<<" to "<<C<<"\n";
		TOH(n-1,'A','B','C');
	}

}
int main(int arg,char* ar[])
{
	int n;
	cout<<"\nEnter no. of dscs\n";
	cin>>n;
	TOH(n,'A','C','B');
	return 0;
}