#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)

void rearrange(int arr[], int n){
  // sort(a,a+n); // already sorted
  int max_index = n-1, min_index = 0;
  int max_element = arr[n-1] + 1;
  REP(i,n){
    if(i%2){ // at odd we store min
      arr[i] += (arr[min_index] % max_element) * max_element;
      min_index++;
    }
    else{
      arr[i] += (arr[max_index] % max_element) * max_element;
      max_index--;
    }
  }

  REP(i,n) arr[i] /= max_element;
  REP(i,n) cout << arr[i]<< ' ';
  cout << endl;
}

int32_t main(int argc, char const *argv[]){
  T(){
    int n;cin>>n;
    int a[n];
    REP(i,n)cin>>a[i];
    rearrange(a,n);
  }
  return 0;
}
