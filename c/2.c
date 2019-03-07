#include<stdio.h>
#include<time.h>
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 100000 * number_of_seconds; // 6 zeroes
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 
int main()
{

	for (int i = 0; i < 5; ++i)
	{
	printf("hello");

	delay(1);
	printf("[%3li%%]", 27);
	delay(1);
	printf("\rbye");
	}
return 0;
}
