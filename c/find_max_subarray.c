// using divide and conquer and kadane
#include<stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
time_t t;
clock_t start = 0;
void print_clock(){
	printf("------------------------------------------\n Clock ticks: %ld \t Time elapsed: %lds\n------------------------------------------\n\a", clock() - start, time(NULL) - t);
}
int* find_maximum_subarray(int* A, int low, int high);
int* find_maximum_crossing_subarray(int* A, int low, int mid, int high);
int* kadane(int* A, int low, int high);

int main(int argc, char const *argv[])
{
	t = time(NULL), start = clock();
	int n; 
	scanf("%d",&n);
	int* A = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);

	int* res = malloc(3*sizeof(int));

	// start = clock();
	// res = find_maximum_subarray(A, 0, n);
	// printf("%d %d %d\n", res[0], res[1], res[2]);
	print_clock();

	start = clock();
	res = kadane(A, 0, n);
	printf("%d %d %d\n", res[0], res[1], res[2]);
	print_clock();
	return 0;
}

int* find_maximum_subarray(int* A, int low, int high){
	if(high == low){
		int* ans = malloc(3*sizeof(int));
		ans[0] = low, ans[1] = high, ans[2] = A[low]; // low, high, sum
		return ans;
	}
	// else 
	int mid = (low + high) / 2;
	int *left, *right, *cross;
	left = find_maximum_subarray(A, low, mid);
	right = find_maximum_subarray(A, mid+1, high);
	cross = find_maximum_crossing_subarray(A, low, mid, high);

	if(left[2] >= right[2] && left[2] >= cross[2])
		return left;
	else if(right[2] > left[2] && right[2] > cross[2])
		return right;
	else return cross;
}

int* find_maximum_crossing_subarray(int* A, int low, int mid, int high)
{
	int sum = 0, left_sum = INT_MIN, right_sum = INT_MIN;
	int left_max, right_max;
	for (int i = mid; i >= low; --i)
	{
		sum += A[i];
		if(sum > left_sum){
			left_sum = sum;
			left_max = i;
		}
	}
	sum = 0;
	for (int j = mid + 1; j <= high; j++)
	{
		sum += A[j];
		if(sum > right_sum){
			right_sum = sum;
			right_max = j;
		}
	}
	int* ans = malloc(3*sizeof(int));
	ans[0] = left_max, ans[1] = right_max, ans[2] = left_sum + right_sum;
	return ans;
}

int* kadane(int* A, int low, int high){
	int max_ending_here = 0, max_so_far = INT_MIN, start = 0, end = 0, s = 0;
	for (int i = low; i <= high; ++i)
	{
		max_ending_here += A[i];

		if(max_so_far < max_ending_here){
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}

		if(max_ending_here < 0){
			max_ending_here = 0;
			s = i + 1;
		}

	}
	int* ans = malloc(3*sizeof(int));
	ans[0] = start, ans[1] = end, ans[2] =max_so_far;
	return ans;
}