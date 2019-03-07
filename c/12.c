#include<stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 99999
time_t t;
clock_t start = 0;
void print_clock(){
	fprintf(stderr, "------------------------------------------\n Clock ticks: %ld \t Time elapsed: %lds\n------------------------------------------\n\a", clock() - start, time(NULL) - t);
}
int main(int argc, char const *argv[])
{
	t = time(NULL), start = clock();

	srand(time(0));
	int num,n;
	scanf("%d", &n);
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
	{
		num = (rand()%5000) - (rand()%10000) ;
		printf("%d ", num);
	}
	printf("\n");
	print_clock();
	return 0;
}