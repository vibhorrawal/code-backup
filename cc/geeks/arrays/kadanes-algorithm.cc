#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)

int maxsubarray(int a[], int n){
  int max_ = 0, max_so_far = INT_MIN;
  REP(i,n){
    max_ += a[i];
    if(max_<0) max_ = 0;
    max_so_far = max(max_,max_so_far);
  }
  return max_so_far;
}

int max_subarray_sum(int a[], int n){
  int max_so_far = a[0], current_max = a[0];
  for (int i = 1; i < n; i++) {
    current_max = max(a[i], current_max + a[i]);
    max_so_far = max(max_so_far, current_max);
  }
  return max_so_far;
}

int main(int argc, char const *argv[]){
  T(){
    int n;
    cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    cout<< max_subarray_sum(a,n)<< endl;
  }
  return 0;
}
