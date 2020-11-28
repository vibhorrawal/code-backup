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
  set<int> s;
  vector<int> v;
  for(int i = 0, j = n; i <= n; i++,j--){
    int x = (i + i) % n;
    v.pb(x);
    s.insert(x);
  }
  if(sz(s) != n){
    cout << "-1" << endl;
  }
  else{
    for (int i = 0; i < n; i++) cout<<i<<' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout<<i<<' ';
    cout << endl;
    // for (int i = n-1; i >= 0; i--) cout<<i<<' ';
    // cout << endl;
    for(int i = 0; i < n; i++) cout<<v[i]<<' ';
    cout << endl;
  }
  return 0;
}
