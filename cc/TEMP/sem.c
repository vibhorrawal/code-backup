#include<stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t semaphore;
void * fun(int * arg){
	printf("%d\n", 2);
}
int main(int argc, char const *argv[])
{
	sem_init(&semaphore,0,1);
	pthread_t p1,p2;
	pthread_create(&p1,NULL, fun, 1);
	pthread_join(p1,NULL);
	pthread_create(&p2,NULL, fun, 1);
	pthread_join(p2,NULL);
	return 0;
}