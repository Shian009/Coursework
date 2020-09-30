#include<iostream>
#include<math.h>
using namespace std;
 int page_size,memory_size,no_of_frames;
  int arr[1000][3];
 void allocate(int pid ,int process_size)
  {
         int i,j,nf=0;
        for(i=0;i<no_of_frames;i++)
         {
            if(arr[i][1]==-1)
              nf=nf+1;//no of free frames
           
         }
        int no_of_pages;
        if(process_size%page_size==0)
          no_of_pages = process_size/page_size;
        else
          no_of_pages = (process_size/page_size)+1;

          if(no_of_pages<=nf)
            {
                 
               for(i=0;i<no_of_frames;i++)
                 {
                     for(j=1;j<3;j++)
                      {
                           if(arr[i][j]==-1&&no_of_pages!=0)
                             {
                                   
                                 arr[i][1]=pid;
                                 arr[i][2]=no_of_pages;
                                 no_of_pages--;
                                   break;//----_
                             }
                       }//break===
                     if(no_of_pages==0)
                        break;
                  }
                   cout<<"Process "<<pid<<" Allotted Memory Successfully \n";
              }
          else
            {
                cout<<"PROCESS SIZE TOO BIG :: MEMORY FULL \n";
             }
      }

 void deallocate(int pid)
   {
      int i,j;
       for(i=0;i<no_of_frames;i++)
         {
                 if(arr[i][1]==pid)
                   {
                      arr[i][1]=-1;
                      arr[i][2]=-1;
                       
                    }
               }
          
       cout<<"Process "<<pid<<" Deallocated Successfully \n";
    }
 void displayFrame(int pid)
  {
     int i;
      for(i=0;i<no_of_frames;i++)
       {
          if(arr[i][1]==pid)
           cout<<"FRAME NO : "<<arr[i][0]<<" PID : "<<arr[i][1]<<" PAGE NO : "<<arr[i][2]<<endl;
        }
   }
  void displayFrame1(int pid,int page)
  {
       int i;
     for(i=0;i<no_of_frames;i++)
       {
          if(arr[i][1]==pid)
           {
              if(arr[i][2]==page){
               cout<<"FRAME NO : "<<arr[i][0]<<endl;
                 break;
              }
        }
 }
}

  void display()
   {
      int i,j;
      cout<<"FrameNo\tPID\tPage No \n";
     for(i=0;i<no_of_frames;i++)
      {
        for(j=0;j<3;j++)
          cout<<arr[i][j]<<"\t";
       cout<<endl;
      }
   }

   int main()          
     {
         
        int process_size,choice,i,j,f=1,pid,pn;
        cout<<"ENTER THE PAGE SIZE : ";
        cin>>page_size;
        cout<<"ENTER THE PHYSICAL MEMORY SIZE : ";
        cin>>memory_size;
        
         no_of_frames=memory_size/page_size;
         for(i=0;i<no_of_frames;i++)
          {
             for(j=0;j<3;j++)
              {
                  if(j==0){
                    arr[i][j]=f;
                       f++;
                      }
                    else
                       {
                           arr[i][j]=-1;
                     }
                  }
            }


         
         
          do{
            cout<<"PRESS 1 TO ALLOCATE PROCESS \n";
         cout<<"PRESS 2 TO DEALLOCATE PROCESS \n";
         cout<<"PRESS 3 TO DISPLAY FRAME NO BY PID ONLY \n";
         cout<<"PRESS 4 TO DISPLAY FRAME NO BY PID , PAGE NO \n";
         cout<<"PRESS 5 TO DISPLAY FRAME TABLE \n";
          cout<<"PRESS 6 TO EXIT \n";
           cout<<"ENTER YOUR CHOICE \n";
         cin>>choice;
         switch(choice)
          {
              case 1:
                       cout<<"Enter the process id : ";
                       cin>>pid;
                       cout<<"Enter the process size : ";
                       cin>>process_size;
                       allocate(pid,process_size);
                       break;
             case 2:
                      cout<<"Enter the process id : ";
                      cin>>pid;
                       deallocate(pid);
                       break;
             case 5: display();
                      break;
             case 3:cout<<"ENTER THE PID \n";
                    cin>>pid;
                       displayFrame(pid);
                         break;
               case 4:cout<<"ENTER THE PID \n";
                    cin>>pid;
                       cout<<"ENTER THE PAGE NO \n";
                         cin>>pn;
                       displayFrame1(pid,pn);
                         break;
                  case 6:return 0;
           }
         }while(choice!=6);
     return 0;
     }
