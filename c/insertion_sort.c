#include<stdio.h>
#define N 5

void insertion_sort(int* a){
	int key, j;
	for (int i = 1; i < N; ++i)
	{
		key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {5,2,4,6,1,3};
	insertion_sort(a);
	for (int i = 0; i < N; ++i)
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}