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

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n, m;
  cin >> n >> m;
  vvi v(n+1);
  REP(i,m){
    int a, b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 0; i < v.size(); i++) {
    for(int y : v[i]){
      for(int z : v[y]){
        if(i == z) continue;
        if(std::find(v[i].begin(), v[i].end(), z) == v[i].end()){
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
