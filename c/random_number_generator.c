#include<stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 7
int main(int argc, char const *argv[])
{
	srand(time(0));
	int num;
	
	for (int i = 0; i < 5; ++i)
	{
		num = rand() % MAX;
		printf(" %d ", num);
	}
	printf("\n");
	return 0;
}