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
  vi owe(n+1,0);
  REP(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    owe[a] += c;
    owe[b] -= c;
  }
  ll total = 0;
  for (int i = 1; i <= n; i++) {
    if(owe[i] > 0)
      total += owe[i];
  }
  cout << total << endl;
  return 0;
}
/*
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n, m;
  cin>>n>>m;
  vector<vector<pair<int,int>>> graph(n+1);
  REP(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    graph[a].push_back({b,c});
  }
  for (int i = 0; i <= n; i++) {
    for(int j = 0; j < graph[i].size(); j++){
      for(int k = 0; k < graph[graph[i][j].first].size(); k++){
        if(graph[j][k].second <= graph[i][j].second){
          graph[i][j].second -= graph[j][k].second;
          graph[i].push_back({graph[j][k].first, graph[j][k].second});
          graph[j][k].second = 0;
          // graph[j].erase(graph[j].begin() + k);
        }
      }
    }
  }
  ll res = 0;
  for(int i = 1; i <= n; i++)
    for (int j = 0; j < graph[i].size(); j++) {
      res += graph[i][j].second;
    }
  cout << res << endl;
  return 0;
}
*/
