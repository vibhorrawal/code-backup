#include<sys/types.h>
#include <stdio.h>
#include<sys/wait.h> 
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("getppid() = %d\n", getppid());
	printf("getpid() = %d\n", getpid());
	sleep(10);
	return 0;
}
