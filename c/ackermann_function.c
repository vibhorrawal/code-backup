#include<stdio.h>
#define SIZE 5

unsigned long long int ackermann(unsigned long long int m, unsigned long long int n){
	if(m == 0)
		return (unsigned long long int) n+1;
	if(m > 0)
	{
		if(n == 0)
			return (unsigned long long int) ackermann(m-1,1);
		if(n > 0)
			return (unsigned long long int) ackermann(m-1,ackermann(m,n-1));
	}
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < i; ++j)
			printf("Ackermann of (%d, %d) is %llu\n", i, j, ackermann(i,j));

	return 0;
}