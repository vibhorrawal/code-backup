#include <pthread.h>
#include <stdio.h>
int test = 0;

void *foo(void* param);
int main(int argc, char const *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	// int x = 10;
	pthread_create(&tid, &attr, foo, NULL);
	int signal;
	pthread_join(tid,&signal);
	// sleep(1);
	printf("Signal: %d\n", signal);
	printf("I am in parent thread %d\n", test);
	pthread_cancel(tid);
	for (int i = 0; i < 200; ++i)
	{
		printf("\a");

	}
	
	// pthread_join(tid,NULL);

	return 0;
}

void *foo(void* param){
	pthread_testcancel();
	printf("I am in child thread %d and param = %d\n", --test, 12);
	pthread_exit(11220);
}