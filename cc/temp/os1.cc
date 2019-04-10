// banker's Algo
#include <iostream>
#include<exception>
using namespace std;


int main(int argc, char const *argv[]) try
{
	int M,N;
	// M is number of resources and N is no of processes
	scanf("%d", &M);
	scanf("%d", &N);

	int total[M];
	int max[N][M];
	int allocation[N][M];
	int need[N][M];
	int sum_alloc[M] = {0};
	int current_available[M];

	printf("Input Total matrix:\n");
	for (int i = 0; i < M; ++i)
		scanf("%d", &total[i]);
	
	printf("Input Allocation matrix:\n");
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
				scanf("%d", &allocation[i][j]);

	printf("Input Maximum matrix:\n");
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
				scanf("%d", &max[i][j]);

	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			need[i][j] = max[i][j] - allocation[i][j];
			sum_alloc[j] += allocation[i][j];
		}

	
	for (int i = 0; i < M; ++i)
		current_available[i] = total[i] - sum_alloc[i];

	// printf("Current Available\n");
	fflush(stdout);
	fflush(stdin);
	for (int i = 0; i < M; ++i){
		// printf("here\n");
		printf(" %d", current_available[i]);
	
	}

	cout<<endl<<"Now Safe Sequence"<<endl;
	bool printed[N] = {0};
	bool flag;
	int count = 0;
	// printf("Here\n");
	while(count < N)
	{
		// printf("count = %d\n", count);
		for (int i = 0; i < N; ++i)
		{
			if(printed[i])
				continue;

			flag = true;

			for (int j = 0; j < M; ++j)
				if(current_available[j] < need[i][j])
					flag = false;
			
			if(flag == true && printed[i] == false)
			{
				cout<<endl<<"Here"<<endl;
				cout<<i;
				printed[i] = true;
				count++;

				// for new sum_alloc matrix
				for (int k = 0; k < M; ++k)
					sum_alloc[k] = 0;

				// new sum_alloc
				for (int k = 0; k < N; ++k)
					for (int l = 0; l < M; ++l)
					{
						if(printed[k])
							continue;

						sum_alloc[l] += allocation[k][l];
					}
				for (int k = 0; k < M; ++k)
					current_available[i] = total[i] - sum_alloc[i];
			
							
			}
		}
	}


	return 0;
}
catch(exception e){
    cout<<e.what();
}