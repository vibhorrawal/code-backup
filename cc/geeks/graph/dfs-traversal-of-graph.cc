// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void dfsUtil(vector<int> g[], int a, vector<int> &res, bool vis[]){
  if(vis[a]) return;
  vis[a] = true;
  res.push_back(a);
    for(int i = 0; i < g[a].size(); i++){
        if(!vis[g[a][i]])
          dfsUtil(g, g[a][i], res, vis);
        }

}
vector <int> dfs(vector<int> g[], int N)
{

    // Your code here
    vector<int> res;
    bool vis[N];
    memset(vis, false, sizeof(vis));
    dfsUtil(g,0,res,vis);
    return res;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends
