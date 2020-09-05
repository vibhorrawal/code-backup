// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */

// return the minimum number of swaps required to sort the arra
int minSwaps(int arr[], int n){
    /*Your code here */
    int count = 0;

    vector<pair<int, int>> sorted(n);  // tle with vectors dont know why
    // pair<int, int> sorted[n];
    for (int i = 0; i < n; i++) {
      sorted[i] = {arr[i], i};
    }
    sort(sorted.begin(), sorted.end());
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++) {
      if(vis[i] || i == sorted[i].second)
        continue;

      int j = i, cycle_size = 0;
      while(!vis[j]){
        vis[j] = true;
        cycle_size++;
        j = sorted[j].second;
      }
      if(cycle_size)
        count += cycle_size - 1;
    }
    return count;
}
