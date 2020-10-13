#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void check();
int n,m;
bool A[50][50];
bool B[50][50] = {0};
int32_t main(int argc, char const *argv[]){
  iinternaut();
  cin>>n>>m;
  REP(i,n)
    REP(j,m)
        cin>>A[i][j];

  check();
  return 0;
}
void check(){
  string out;
  int count = 0;
REP(i,n-1) REP(j,m-1)
  if(A[i][j] && A[i][j+1] && A[i+1][j] && A[i+1][j+1]){
    count++;
    out += to_string(i+1) +' '+to_string(j+1)+'\n';
    B[i][j] = B[i][j+1] = B[i+1][j] = B[i+1][j+1] = 1;
  }
  bool flag = 0;
  REP(i,n) REP(j,m)
  if(A[i][j] != B[i][j])
    flag = 1;

  if(flag) cout<<-1;
  else cout<<count<<endl<<out;
}
