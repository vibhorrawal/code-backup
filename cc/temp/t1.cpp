// banker's Algo
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int M,N;
	// M is number of resources and N is no of processes
	scanf("%d", &M);
	scanf("%d", &N);

	int total[M];
	int max[N][M];
	int allocation[N][M];
	int need[N][M];

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

	int sum_alloc[M] = {0};
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			need[i][j] = max[i][j] - allocation[i][j];
			sum_alloc[j] += allocation[i][j];
		}

	int current_available[M];
	for (int i = 0; i < M; ++i)
		current_available[i] = total[i] - sum_alloc[i];

	printf("Current Available\n");
	for (int i = 0; i < M; ++i){
		// printf("here\n");
		printf("%d ", current_available[i]);
	
	}

	printf("Now Safe Sequence");
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
				// printf("Here\n");
				printf("-> %d ", i);
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