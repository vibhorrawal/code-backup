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
  int n, m;
  cin>>n>>m;
  vector<vector<int>> graph(n+1);
  REP(i,m){
    int a, b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int count = 0;
  while(1){
    set<int> vis;
    for(int i = 0; i <= n; i++){
      if(graph[i].size() == 1)
      vis.insert(i);
    }
    if(vis.size() == 0)
      break;
    for(int i : vis){
      for(int u = 0; u <= n; u++){
        auto it = find(graph[u].begin(), graph[u].end(), i);
        if(it != graph[u].end())
          graph[u].erase(it);
      }
      graph[i].clear();
    }
    count++;
  }
  cout << count << endl;
  return 0;
}
