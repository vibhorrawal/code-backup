#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define BUFFERSIZE 25
#define READ_END 0
#define WRITE_END 1

int main(int argc, char const *argv[])
{
	char write_msg[BUFFERSIZE] = "Greetings\n";
	char read_msg[BUFFERSIZE];
	int fd[2];
	pid_t pid;
	pipe(fd);

	pid = fork();

	if(pid) //parent_process();
	{
		close(fd[READ_END]);

		write(fd[WRITE_END], write_msg, strlen(write_msg));
		close(fd[WRITE_END]);
	}
	else //child_process();
	{
		close(fd[WRITE_END]);

		read(fd[READ_END], read_msg, BUFFERSIZE);
		printf("read %s", read_msg);
		close(fd[READ_END]);
	}
	return 0;
}