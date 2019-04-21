#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid, pid1;
	pid = fork();

	if(pid<0) {
		fprintf(stderr, "Fork Failed!!!\n");
		return 1;
	}

	if(pid){
		pid1 = getpid();
		printf("parent: pid = %d\n", pid);
		printf("parent: getpid() = %d\n", pid1);
		wait(NULL);
	}

	else{
		pid1 = getpid();
		printf("child: pid = %d\n", pid);
		printf("child: getpid() = %d\n", pid1);
	}
	return 0;
}