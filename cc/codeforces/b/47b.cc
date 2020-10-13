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

void topological(vector<vector<int>> &graph){
  std::vector<int> inedge(3,0);
  for(auto u : graph){
    for(auto v : u){
      inedge[v]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < 3; i++) {
    if(inedge[i] == 0) q.push(i);
  }
  string res;
  while(!q.empty()){
    int i = q.front(); q.pop();
    res += i + 'A';
    for(int v : graph[i]){
      if(--inedge[v] == 0){
        q.push(v);
      }
    }
  }
  if(res.size() == 3) cout << res << endl;
  else cout<<"Impossible"<<endl;
}
void weight(){
  string s[3];
  REP(i,3) {
    string temp;
    cin>>temp;
    s[i] = temp;
  }
  REP(i,3) if(s[i][1] == '>') reverse(s[i].begin(), s[i].end());
  // use all A<B
  vector<vector<int>> graph(3);
  REP(i,3) graph[s[i][0]-'A'].push_back(s[i][2]-'A');
  topological(graph);
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  weight();
  return 0;
}
