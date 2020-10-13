#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n,m;
  cin>>n>>m;
  int sx,sy,fx,fy;
  cin>>sx>>sy>>fx>>fy;
  set<int> instant;
  vector<vector<pair<int,int>>> graph(n*n);
  
  REP(i,m){
    int x,y; cin>>x>>y;
    instant.insert((x + 1) + y * n);
  }
  int start = sx + 1 + sy * n;
  int end = fx + 1 + fy * n;

  return 0;
}
