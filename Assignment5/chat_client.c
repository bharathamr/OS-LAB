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
	id=shmget(111,50,0);
	n=shmget(110,50,0);
	c=shmat(n,NULL,0);
	a=shmat(id,NULL,0);
	while(1)
	{
	while(c[0]=='N');
	printf("Your Friend : %s\n",a);
	printf("You : ");
	scanf("\n%s",a);
	c[0]='N';
	if(strcmp(a,"bye")==0)
		exit(0);
	}
	shmctl(id, IPC_RMID,NULL);
	shmctl(n, IPC_RMID,NULL);
}
