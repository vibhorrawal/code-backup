#include <stdio.h>
#include <pthread.h>
int set = 0;
int maze[9][9];
void *block(void* val);
void *horizontal(void* val);
void *vertical(void* val);

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 9; ++i)
		for(int j = 0; j < 9; ++j)
			scanf("%d", &maze[i][j]);
	
	pthread_t tid[11];
	for (int i = 0; i < 11; ++i)
		tid[i] = i;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	int count = 0;
	for (int i = 0; i < 9; ++i)
		pthread_create(&tid[count++], &attr, block,(void*) &i);

	pthread_create(&tid[count++], &attr, horizontal, NULL);
	pthread_create(&tid[count++], &attr, vertical, NULL);

	for (int i = 0; i < count; ++i)
		pthread_join(tid[i],NULL);
	
	if(set == 0) printf("Valid Solution!!!\n");
	else 		printf("Invalid Solution!!!\n");
	return 0;
}

void *horizontal(void* val){
	int sum = 0;
	for (int i = 0; i < 9; ++i)
	{
		sum = 0;
		for(int j = 0; j < 9; ++j)
			sum += maze[i][j];

		if(sum != 45) set+= 1;
		
	}
	pthread_exit(0);
}

void *vertical(void* val){
	int sum = 0;
	for (int i = 0; i < 9; ++i)
	{
		sum = 0;
		for(int j = 0; j < 9; ++j)
			sum += maze[j][i];

		if(sum != 45) set+= 1;
	}
	pthread_exit(0);
}
void *block(void* val){
	int *value = (int*) val;
	int blk = *value;
	int sum = 0;
	int ival = 0, jval = 0;
	
	// printf("%d***\n", blk);
	switch(blk)
	{
		case 1: jval += 3;
		case 2: jval += 3;	break;

		case 3:	ival += 3;
		case 4:	ival += 3;	break;

		case 5:	jval += 3;	ival += 3;
		case 6:	jval += 3;	ival += 3;	break;

		case 7:	ival += 3;	jval += 6;	break;
	
		case 8:	jval += 3;	ival += 6;	break;

		default: break;
	}
	for (int i = ival; i < ival+3; ++i)
		for(int j = jval; j < jval+3; ++j)
					sum += maze[i][j];
	if(sum != 45) set+= 1;	
	// printf("%d\n", sum);		
	pthread_exit(0);
}
