#include<bits/stdc++.h>
#include <semaphore.h>
#include <pthread.h>
using namespace std;
#define N 5

sem_t chopstick[N];

void *philosopher(void *arg){
	int i = int((long)arg);
	cout<<"\n\n";
	cout<<"THINKING: "<<i<<endl;
	sem_wait(&chopstick[i]);
	sem_wait(&chopstick[(i+1) % N]);
	cout<<"EATING with "<<i<<" and "<<(i+1)%N<<endl;
	sem_post(&chopstick[i]);
	sem_post(&chopstick[(i+1) % N]);
	cout<<"\n\n";
}
void *last_philosopher(void *arg){
	int i = int((long)arg);
	cout<<"\n\n";
	cout<<"THINKING: "<<i<<endl;
	sem_wait(&chopstick[(i+1) % N]);
	sem_wait(&chopstick[i]);
	
	cout<<"EATING with "<<(i+1)%N<<" and "<<i<<endl;
	sem_post(&chopstick[i]);
	sem_post(&chopstick[(i+1) % N]);
	cout<<"\n\n";
}
int main(int argc, char const *argv[])
{
	// cin>>N;
	pthread_t tid[N];

	for (int i = 0; i < N; ++i)
		sem_init(&chopstick[i],0,1);

	for (int i = 0; i < N-1; ++i)
		pthread_create(&tid[i], NULL, philosopher, (void*)i);

	pthread_create(&tid[N-1], NULL, last_philosopher, (void*)N-1);
	for (int i = 0; i < N; ++i)
		pthread_join(tid[i],NULL);

	for (int i = 0; i < N; ++i)
		sem_destroy(&chopstick[i]);
	return 0;
}