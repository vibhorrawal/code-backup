#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)

void subarray(int arr[], int n, int sum){
  int start = 0, temp_sum=arr[0];

  for (int i = 1; i <= n; i++) {
    while(sum<temp_sum && start < i-1){
      temp_sum -= arr[start];
      start++;
    }
    if(sum==temp_sum){
      cout << start+1 <<' ' << i << endl;
      return;
    }
    if(i<n) temp_sum += arr[i];
  }

  cout << -1 << endl;
}

int main(int argc, char const *argv[]){
  T(){
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    REP(i,n)cin>>arr[i];
    subarray(arr,n,sum);
  }
  return 0;
}
