// c program
#include<sys/types.h>
#include <stdio.h>
#include<sys/wait.h> 
#include <unistd.h>
// using namespace std;
int value[2] = {5,100};
int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();
	if(!pid){
		value[0] += 15;
		printf("Child value: %d\n", value[0]);
		return 0;
	}
	else{
		wait(NULL);
		printf("Parent value: %d\n", value[0]);
		return 0;
	}
}
