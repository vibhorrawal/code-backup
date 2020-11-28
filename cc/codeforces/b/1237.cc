#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n;
  cin>>n;
  vi a(n), b(n);
  REP(i,n) cin>>a[i];
  REP(i,n) cin>>b[i];
  set<int> s;
  int i = 0, j = 0;
  while(i < n && j < n){
    if(s.count(a[i])){
      i++;
      continue;
    }
    if(a[i] == b[j]) {
      i++,j++;
      continue;
    }
    s.insert(b[j]);
    j++;
  }
  cout << sz(s) << endl;
  return 0;
}
