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

int main(){
  int n,m;
  cin>>n>>m;
  vvi b(n, vi(m, false));
  REP(i,n) REP(j,m) cin>>b[i][j];
  vvi a(n, vi(m, true));
  REP(i,n) {
    REP(j,m){
      if(b[i][j] == 0){
        REP(ii,n) a[ii][j] = 0;
        REP(jj,m) a[i][jj] = 0;
      }
    }
  }
  vvi c(n, vi(m, false));
  REP(i,n) {
    REP(j,m){
      if(a[i][j]){
        REP(ii,n) c[ii][j] = 1;
        REP(jj,m) c[i][jj] = 1;
      }
    }
  }

  REP(i,n) {
    REP(j,m){
      if(b[i][j] != c[i][j]){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  REP(i,n) {
    REP(j,m){
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
/*
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n,m;
  cin>>n>>m;
  vvi b(n, vi(m));
  REP(i,n) REP(j,m) cin>>b[i][j];
  vi row(n, true), col(m, true);
  REP(i,n){
    REP(j,m){
      row[i] &= b[i][j];
      col[j] &= b[i][j];
    }
  }
  REP(i,n) REP(j,m){
    if((row[i] || col[j]) != b[i][j]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  int countR = accumulate(all(row),0);
  int countC = accumulate(all(col),0);
  vvi a(n, vi(m));
  REP(i,n) {
    REP(j,m){
      a[i][j] =  (row[i] & col[j]);
      countC -= a[i][j];
      countR -= a[i][j];
    }
  }
  if(countR && !countC){
    REP(i,n) {
      if(row[i]) REP(j,m){
        a[i][j] = 1;
    }
    if(row[i]) countR--;
    if(countR == 0) break;
    }
  }
  if(countC && !countR){
    REP(j,m){
      if(col[j]) REP(i,n){
        a[i][j] = 1;
      }
      if(col[j]) countC--;
      if(countC == 0) break;
    }
  }
  REP(i,n){
    REP(j,m) cout<<a[i][j]<<' ';
    cout<<endl;
  }
  return 0;
}
*/
