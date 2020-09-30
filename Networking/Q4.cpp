#include<iostream>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
using namespace std;
class timer
{
    public:
    int begtime;
    void start()
    {
        begtime=clock();
    }
    bool isTimeout(double sec)
    {
        return sec<=begtime-clock();
    }
};
int main()
{
 int sf,ws;
 timer t;
 cout<<"Enter the number of frames : ";
 cin>>sf;
 cout<<"Enter the Window Size : ";
 cin>>ws;
 int sn=1;
 cout<<"Sender\t\t\t\t\tReciever\n";
 while(sn<=sf)
 {
     int x=0;
    for(int j=sn;j<sn+ws && j<=sf;j++)
     {
        t.start();
         cout<<"Sent Frame "<<j<<endl;
     }
     for(int j=sn;j<sn+ws && j<=sf;j++)
     {
        
         bool f=t.isTimeout(5);
         int flag =rand()%2;
         if(!flag&&!f)
             {
                 cout<<"\t\t\t\t\tRecieved frame "<<j<<endl;
                 
                 	cout<<"Acknowledgment for Frame "<<j<<endl;
                 	x++;
                    sleep(3);
             }
         else
             {   cout<<"\t\tFrame "<<j<<" Lost\t\t----"<<endl;
             	 cout<<"Timeout\n";
                 cout<<"Resending window\n";
                 sleep(3);
                 break;
             }
     }
     cout<<endl;
     sn+=x;
 }
 return 0;
}
