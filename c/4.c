#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
	int status;
	char * command, *parameters;
	while(1){
		type_prompt();
		read_command(command, parameters);
		if(fork() != 0)
		{
			printf("In parent\n");
			waitpid(-1,&status,0);
		}
		else{
			printf("In child\n");
			execve(command,parameters,0);
		}
	}
	return 0;
}