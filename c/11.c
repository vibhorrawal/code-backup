#include<stdio.h>
#include <time.h>
#define SIZE 5
clock_t start; // start = clock();
void print_clock(){
	printf("Clock ticks: %ld and time taken on CPU: %f\n", clock(), ((double)clock() - start)/ CLOCKS_PER_SEC );
}


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
	start = clock();
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < i; ++j){
			printf("Ackermann of (%d, %d) is %llu\n", i, j, ackermann(i,j));
			print_clock();
		}

	return 0;
}