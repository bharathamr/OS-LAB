#include <sys/ipc.h>
# define NULL 0
#include <sys/shm.h>
#include <sys/types.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
#include <sys/wait.h>
#include <stdio_ext.h>
// parent writing a char in shared memory and child reads it and prints it.
int main()
{
	int pid;
	char *a,*c;
	int id,n;
	id=shmget(111,50,IPC_CREAT | 00666);
	n=shmget(110,50,IPC_CREAT | 00666);
	c=shmat(n,NULL,0);
	a=shmat(id,NULL,0);
	c[0]='N';
	printf("You : ");
	scanf("%s",a);
	c[0]='Y';
	while(1)
	{
	while(c[0]=='Y');
	printf("Your Friend : %s\n",a);
		if(strcmp(a,"bye")==0)
		exit(0);
	printf("You : ");
	scanf("%s",a);
	c[0]='Y';
	}
}
