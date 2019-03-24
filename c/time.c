#include<stdio.h>
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <time.h>
time_t t;
clock_t start = 0; // start = clock();
void print_clock(){
	fprintf(stderr, "------------------------------------------\n Clock ticks: %ld \t Time elapsed: %lds\n------------------------------------------\n\a", clock() - start, time(NULL) - t);
	// printf("----------------------------------------------------------------------------\n Clock ticks: %ld\t Time taken on CPU: %.3fs\t Time elapsed: %lds\n----------------------------------------------------------------------------\n\a", clock() - start, ((double)clock() - start)/ CLOCKS_PER_SEC, time(NULL) - t);
}
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000000 * number_of_seconds; // 6 zeroes
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
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

//-------------------------------------------------- MAIN -------------------------------------------------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
	t = time(NULL);	start = clock();

	printf("%ld\n", time(NULL));
	for (int i = 0; i < 2; ++i)
	{
		delay(1);
		printf("%d seconds\n", i);
	}
	int n;
	// print_clock();
	fun();
	print_clock();
	return 0;
}
