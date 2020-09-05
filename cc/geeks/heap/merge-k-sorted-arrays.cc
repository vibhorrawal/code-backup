// { Driver Code Starts
#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends


// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
#define ppi pair<int, pair<int, int>>
int *mergeKArrays(int arr[][N], int k)
{
  int *ans = new int[k * k];
  priority_queue<ppi, vector<ppi>, greater<ppi>> pq; // elem, array, index

  for (int i = 0; i < k; i++) {
    pq.push({arr[i][0], {i,0}});
  }
  int it = 0;
  while(!pq.empty()){
    auto t = pq.top();
    pq.pop();
    ans[it++] = t.first;
    if(t.second.second < k)
      pq.push({arr[t.second.first][t.second.second + 1], {t.second.first, t.second.second + 1}});
  }
  return ans;
}
