#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>


	



int fi(int x){

	int a0=0;
	int a1=1;
	int a=0;

	while (a<x)
	{
		a=a1+a0;
		a0=a1;
		a1=a;
	}
	if (a==x)
		return 0;
	return 1;

}




int main (int argc, char *argv[]){

	int i;
	int check;
	pid_t pid;

	for (i=1; i<argc; i++){
	
		pid= fork();

		if (pid<0)
		{
			

			printf("fork: cannot create a new process");
			exit(0);
				
		}
		else if (pid==0)
		{
			//printf("\nI'm childrent\n");

			if (fi(atoi(argv[i])) == 0)
			printf("\n\n%d is a Fibonacci member\n",atoi(argv[i]));
			else printf("\n\n%d is not a Fibonacci member\n",atoi(argv[i]));


			printf("process in PID: %d\n", getpid());	

			return 0;	
		}
		else if (pid>0)
		{
			//return 0;  // control 2 processes by choosing where returning this function,
		}
		

	
	}
	return 0;


}

