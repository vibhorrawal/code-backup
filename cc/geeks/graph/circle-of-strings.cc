#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define CHARS 26
void clr(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

class Graph{
  int V;
  list<int> *adj;
  int *in_degree;

public:
  Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    in_degree = new int[V];
    for (int i = 0; i < V; i++) {
      in_degree[i] = 0;
    }
  }
  ~Graph()   { delete [] adj; delete [] in_degree; }

  void addEdge(int u, int v){
    adj[u].push_back(v);
    in_degree[v]++;
  }

  bool isEulerianCycle();
  bool isStronglyConnected();
  void DFSUtil(int v, bool vis[]);
  Graph getTranspose();
};

bool is_circular(vector<string> s){
  Graph g(CHARS);

  for (int i = 0; i < s.size(); i++) {
    string sub = s[i];
    g.addEdge(sub[0] - 'a',sub[sub.size()-1] - 'a');
  }
  return g.isEulerianCycle();
}

//check for eulerian path
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n;
    cin >> n;
    std::vector<string> s(n);
    REP(i, n) cin >> s[i];
    cout << is_circular(s) << endl;
  }
  return 0;
}

bool Graph::isStronglyConnected(){
  bool vis[V];
  memset(vis, false, sizeof vis);
  int v;
  for(v = 0; v < V; v++){
    if(adj[v].size())
      break;
  }

  if(v == V) return true; // why????????????????????????????????

  DFSUtil(v,vis);
  for (int i = 0; i < V; i++) {
    if(!vis[i] && adj[i].size())
      return false;
  }

  Graph tr = getTranspose();
  memset(vis, false, sizeof vis);
  tr.DFSUtil(v, vis);
  for (int i = 0; i < V; i++) {
    if(!vis[i] && adj[i].size())
      return false;
  }

  return true;
}

bool Graph::isEulerianCycle(){
  if(isStronglyConnected() == false)
    return false;

  for(int i = 0; i < V; i++){
      if(adj[i].size() != in_degree[i])
        return false;
  }
  return true;
}

Graph Graph::getTranspose(){
  Graph tr(V);
  for (int v = 0; v < V; v++) {
    for (auto u: adj[v]) {
      tr.addEdge(u,v);
    }
  }
  return tr;
}

void Graph::DFSUtil(int v, bool vis[]){
  vis[v] = true;

  for(auto u: adj[v]){
    if(!vis[u])
      DFSUtil(u,vis);
  }
}
