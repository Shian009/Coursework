#include<iostream>    
#include<stdio.h>
using namespace std;

#define max 20
int stack[max];
int top;
void DFS(int arr[max][max],int n,int root)
{
    int i,j;
    bool change=false;

    int visited[n];
    for(i=0;i<n;i++)
        visited[i]=0;

    top=0;
    stack[top]=root;
    cout<<root;
    visited[root]=1;
    while(top>=0){
        change=false;
        i=stack[top];
        for(j=0;j<n;j++){
            if(visited[j]==0 && arr[i][j]==1){

                visited[j]=1;
                top++;
                stack[top]=j;
                cout<<"->"<<j;
                change=true;
                break;
            }
        }
        if(change==false){
            top--;
        }
    }
}

int main()
{
    int adjMatrix[][max]={      {0,1,1,1,0,0,0,0},
                                {1,0,0,0,1,1,0,0},
                                {1,0,0,0,0,0,0,0},
                                {1,0,0,0,0,0,0,0},
                                {0,1,0,0,0,0,0,0},
                                {0,1,0,0,0,0,1,0},
                                {0,0,0,0,0,1,0,1},
                                {0,0,0,0,0,0,1,0}
                             };
    int n=8,source=0;

    DFS(adjMatrix,n,source);
    return 0;

}

