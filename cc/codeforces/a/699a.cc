#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  clr();
  int n;
  cin>>n;
  char dir[n];
  REP(i,n) cin>>dir[i];
  int pos[n];
  REP(i,n) cin>>pos[i];
  int t=INT_MAX;
  for (int i = 1; i < n; i++) {
    if(dir[i] =='L' && dir[i-1] == 'R'){
      t = min(pos[i] - pos[i-1], t);
    }
  }
  cout << (t!=INT_MAX?t/2:-1) << endl;
  return 0;
}
