#include<omp.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("Serial\n");
	#pragma omp parallel
	{
		printf("Parallel:1\n");
		printf("Parallel:2\n");
		printf("Parallel:3\n");
		printf("Parallel:4\n");
		printf("Parallel:5\n");
		printf("Parallel:6\n");
		for (int i = 0; i < 100; ++i)
		{
			printf("%d\t", i);
		}
	}
	printf("Serial again\n");
	return 0;
}