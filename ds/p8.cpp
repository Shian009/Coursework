
#include<iostream>
#include "LinS.h"
using namespace std;

void inp(LL<int> &a,string s)
{
    int k,n=s.length();
    for(int i=0;i<n;i++)
    {
        // cout<<"hello";
        k=s[i]-'0';
        // cout<<k;
        a.push(k);
    }
}

void add(LL<int> &a, LL<int> &b, LL<int> &r)
{
    int c=0;
    int x,y;
    // cout<<"add";
    while(!a.empty()&&!b.empty())
    {
        x=a.pop();
        y=b.pop();
        x=x+y+c;
        c=x/10;
        x%=10;
        r.push(x);
    }
    while(!a.empty())
    {
        x=a.pop();
        x+=c;
        c=x/10;
        x%=10;
        r.push(x);
    }
    while(!b.empty())
    {
        x=b.pop();
        x+=c;
        c=x/10;
        x%=10;
        r.push(x);
    }

    if(c==1)
        r.push(c);
}

int main(int arg,char *args[])
{
    string s;
    LL<int> a,b,r;
    cout<<"\nEnter 1 no: ";
    cin>>s;
    inp(a,s);
    // cout<<a.pop();
    cout<<"\nEnter 2 no: ";
    cin>>s;
    inp(b,s);
    add(a,b,r);
    while(!r.empty())
    {
        cout<<r.pop();
    }    
    return 0;
}