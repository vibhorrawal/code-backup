#include<stdio.h>

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <time.h>
time_t t;
clock_t start = 0; // start = clock();
void print_clock(){
	printf("------------------------------------------\n Clock ticks: %ld \t Time elapsed: %lds\n------------------------------------------\n\a", clock() - start, time(NULL) - t);
	// printf("----------------------------------------------------------------------------\n Clock ticks: %ld\t Time taken on CPU: %.3fs\t Time elapsed: %lds\n----------------------------------------------------------------------------\n\a", clock() - start, ((double)clock() - start)/ CLOCKS_PER_SEC, time(NULL) - t);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
time_t seconds, t;
void print_time(){
	time(&seconds);
	printf("Current time is: %ld\n", seconds);
}

void print_execution_time(){
	time(&seconds);
	printf("Execution Time: %ld sec\n", seconds - t);
}
void start_timer(){
	time(&t);
}

void fun(){
	while(1){
		if(getchar() == 'f')
			break;
		print_clock();
	}
}
int main(int argc, char const *argv[])
{
	t = time(NULL);
	start = clock();

	printf("%ld\n", time(NULL));
	// printf("%d\n", start);
	// print_clock();
	int n;
	// print_clock();
	fun();
	print_clock();
	return 0;
}
