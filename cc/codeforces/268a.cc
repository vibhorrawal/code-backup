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
#define pb emplace_back
#define db(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  int n;
  cin>>n;
  int h[n],g[n];
  REP(i,n) cin>>h[i]>>g[i];
  int count=0;
  REP(i,n){
    REP(j,n){
      if(g[i] == h[j]) count++;
    }
  }
  cout << count << endl;
  return 0;
}
