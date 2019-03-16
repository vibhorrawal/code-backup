#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int a[10];

	memset(a,2,5*sizeof(int));
	for (int i = 0; i < 10; ++i)
		printf("%d ", a[i]);
	
	return 0;
}