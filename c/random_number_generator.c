#include<stdlib.h>
#include <stdio.h>
#define MAX 99999
int main(int argc, char const *argv[])
{
	srand(time(0));
	int num,n;
	scanf("%d", &n);
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
	{
		num = rand() % MAX;
		printf("%d ", num);
	}
	printf("\n");
	return 0;
}