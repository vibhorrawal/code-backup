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
  int n=4;
  int mat[n][n];
  char c;
  REP(i,n) REP(j,n) {
    cin>>c;
    mat[i][j] = (c=='.'? 1 : 0);
  }
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-1; j++) {
      int val = mat[i][j] + mat[i][j+1] + mat[i+1][j] + mat[i+1][j+1];
      if(val >=3 || val <= 1) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
