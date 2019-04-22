#include <stdio.h>
#include <pthread.h>
int set = 0;
int maze[9][9];
void *horizontal(void* val){
	int *value = (int*) val;
	int row = *value;
	int sum = 0;
	for (int i = 0; i < 9; ++i)
		sum += maze[row][i];

	if(sum != 45) set+= 1;
	pthread_exit(0);
}
void *vertical(void* val){
	int *value = (int*) val;
	int col = *value;
	int sum = 0;
	for (int i = 0; i < 9; ++i)
		sum += maze[i][col];

	if(sum != 45) set+= 1;
	pthread_exit(0);
}
void *block(void* val){
	int sum;
	for(int bx = 0; bx < 9;  bx += 3)
		for(int by = 0; by < 9; by += 3) 
		{
			sum = 0;
		  	for(int x = 0; x < 3; ++x)
		  		for(int y = 0; y < 3; ++y) 
		  		{
		    		sum += maze[bx + x][by + y];
  				}
 			 if(sum != 45) set+= 1;
		}
	pthread_exit(0);
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 9; ++i)
		for(int j = 0; j < 9; ++j)
			scanf("%d", &maze[i][j]);
	
	pthread_t tid[19];
	for (int i = 0; i < 19; ++i)
		tid[i] = i;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	int count = 0;
	for (int i = 0; i < 9; ++i)
	{
		pthread_create(&tid[count++], &attr, horizontal,(void*) &i);
		pthread_create(&tid[count++], &attr, vertical,(void*) &i);
	}
	int i = 0;
	pthread_create(&tid[count++], &attr, block,(void*) &i);

	for (int i = 0; i < count; ++i)
		pthread_join(tid[i],NULL);
	
	if(set == 0) printf("Valid Solution!!!\n");
	else 		printf("Invalid Solution!!!\n");
	return 0;
}
