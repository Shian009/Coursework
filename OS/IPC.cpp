//IPC using Pipes
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<iostream>
using namespace std;
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
	char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE];
	cout<<"Enter a message: ";
	cin>>write_msg;
	int fd[2];
	pid_t pid;
	if(pipe(fd) == -1)
	{
		cerr<<"Pipe failed";
		return 1;
	}
	pid = fork();
	if(pid < 0)
	{
		cout<<"Fork failed";
		return 1;
	}
	if(pid > 0)
	{
		close(fd[READ_END]);
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
		close(fd[WRITE_END]);
	}
	else
	{
		close(fd[WRITE_END]);
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		cout<<read_msg;
		close(fd[READ_END]);
	}
	cout<<endl;
	return 0;
}
