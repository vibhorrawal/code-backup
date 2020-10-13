#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n;
  cin>>n;
  vi arr(n);
  REP(i,n) cin>>arr[i];
  ll cut = 0, prev = -1;
  for (int i = 0; i < n; i++) {
    if(arr[i] == 1){
      if(prev == -1){
        cut = 1;
      }
      else{
        cut *= i - prev;
      }
      prev = i;
    }
  }
  cout << cut << endl;
  /*
  if(accumulate(all(arr), 0) == 1){
    cout << "1" << endl;
    return 0;
  }
  int i = 0;
  int count0 = 0;
  while(i < n){
    cut += count0;
    count0 = 0;
    while(i < n && arr[i] == 0){
      i++;
      count0++;
    }
    if(i < n) cut += count0;
    // if(count0)
      // cut += pow(2, count0);
      count0 = 0;
    while(i < n && arr[i] == 1){
      i++;
      count0++;
    }
  }
  */
  return 0;
}
