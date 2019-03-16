#include<iostream>
using namespace std;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <ctime>
time_t t = time(NULL);
clock_t start = clock(); 
void print_clock(){
	fprintf(stderr, "------------------------------------------\n Clock ticks: %ld \t Time elapsed: %lds\n------------------------------------------\n\a", clock() - start, time(NULL) - t);
	// fprintf(stderr, "----------------------------------------------------------------------------\n Clock ticks: %ld\t Time taken on CPU: %.3fs\t Time elapsed: %lds\n----------------------------------------------------------------------------\n\a", clock() - start, ((double)clock() - start)/ CLOCKS_PER_SEC, time(NULL) - t);
}
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = CLOCKS_PER_SEC * number_of_seconds; // 6 zeroes
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void fun(){
	while(1){
		if(getchar() == 'f')
			break;
		print_clock();
		if(getchar() == '\n')
			continue;
		
	}
}

//-------------------------------------------------- MAIN -------------------------------------------------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
	// t = time(NULL);	start = clock();

	// printf("%ld\n", time(NULL));
	for (int i = 0; i < 5; ++i)
	{
		delay(1);
		printf("%d seconds\n", i+1);
	}
	int n;
	// print_clock();
	fun();
	print_clock();
	return 0;
}
