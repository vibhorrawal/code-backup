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

void solve(){
  int n; cin>>n;
  vi v(n);
  REP(i,n) cin>>v[i];
  int pot = v[0];
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if(pot != v[i]) flag = true;
  }
  if(!flag) cout << "-1" << endl;
  else{
    int mx = *max_element(all(v));
    for (int i = 0; i < n; i++) {
      if(v[i] == mx && i && v[i] > v[i-1]) {
        cout << i+1 << endl;
        return;
      }
      if(v[i] == mx && i < n-1 && v[i] > v[i+1]) {
        cout << i+1 << endl;
        return;
      }
    }
    assert(false);
  }
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    solve();
  }
  return 0;
}
