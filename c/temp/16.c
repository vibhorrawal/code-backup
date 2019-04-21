#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();

	if(pid<0) {
		fprintf(stderr, "Fork Failed!!!\n");
		return 1;
	}

	if(pid){
		wait(NULL);
		printf("Child Complete\n");
	}
	else{
		execlp("/bin/pwd", "pwd", NULL);
		printf("I am here.\n");
	}
	return 0;
}