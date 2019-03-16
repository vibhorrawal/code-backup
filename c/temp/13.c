// to check if malloc is freed after encountering }
#include<stdio.h>
#include <stdlib.h>
int* array(int n){
	int* a = malloc(n * sizeof(int));
	// inta [n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = i;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return a;
}

int main(int argc, char const *argv[])
{
	int n = 55;
	int* a = array(n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}