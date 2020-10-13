// from editorial
//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  int n,m;
  cin>>n>>m;
  char a[n][m];
  REP(i,n) REP(j,m) cin>>a[i][j];
  int upperleft[n][m] = {0}, upperright[n][m] = {0}, lowerleft[n][m] = {0}, lowerright[n][m] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(i==0||j==0) upperleft[i][j] = 1;
      else{
        if(a[i][j] == a[i][j-1] && a[i][j] == a[i-1][j])
          upperleft[i][j] = 1 + min(upperleft[i-1][j],upperleft[i][j-1]);
        else
          upperleft[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = m-1; j>=0; j--) {
      if(i==0||j==m-1) upperright[i][j] = 1;
      else{
        if(a[i][j] == a[i][j+1] && a[i][j] == a[i-1][j])
          upperright[i][j] = 1 + min(upperright[i][j+1],upperright[i-1][j]);
        else
          upperright[i][j] = 1;
      }
    }
  }

  for (int i = n-1; i >=0; i--) {
    for (int j = 0; j < m; j++) {
      if(i==n-1||j==0) lowerleft[i][j] = 1;
      else{
        if(a[i][j] == a[i+1][j] && a[i][j] == a[i][j-1])
          lowerleft[i][j] = 1 + min(lowerleft[i+1][j],lowerleft[i][j-1]);
        else
          lowerleft[i][j] = 1;
      }
    }
  }

  for (int i = n-1; i >=0; i--) {
    for (int j = m-1; j >=0; j--) {
      if(i==n-1||j==m-1) lowerright[i][j] = 1;
      else{
        if(a[i][j] == a[i+1][j] && a[i][j] == a[i][j+1])
          lowerright[i][j] = 1 + min(lowerright[i+1][j], lowerright[i][j+1]);
        else
          lowerright[i][j] = 1;
      }
    }
  }

  int ans = 0;
  REP(i,n) REP(j,m) ans += min({lowerleft[i][j], lowerright[i][j], upperleft[i][j], upperright[i][j]});
  cout << ans << endl;
  return 0;
}
