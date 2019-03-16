#include <time.h> 
#include<stdio.h>

void delay(float number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000000 * number_of_seconds; // 6 zeroes
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 
int main()
{
	  int i; 
	  printf("i\r");
    for (i = 0; i < 4; i++) { 
        // delay of one second 
        delay(0.3); 
        printf("\r %d", i); 
    } 
     printf("\ryo\n");
             printf("\b"); 

    return 0; 
}
