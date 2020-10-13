#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n,k;
  cin>>n>>k;
  vi arr(n);
  ll income = 0;
  REP(i,n) cin>>arr[i];
  if(arr[0] >= 0){
    arr[0] = arr[0] * (k % 2 ? -1 : 1);
    income = accumulate(all(arr), income);
  }
  else{
    int j = 0;
    db(j);
    while(arr[j] < 0){
      arr[j++] *= -1;
      k--;
      if(k == 0) break;
    }
    db(k);
    auto it = min_element(all(arr));
    if(k>0) *it = *it * (k % 2 ? -1 : 1);
    income = accumulate(all(arr), income);
  }
  cout << income << endl;
  return 0;
}
