// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

void printSolution(vector <int> dist, int n)
{

   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);

}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;

        vector<vector<int>> g(V);

        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }

        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }

        int s;
        cin>>s;

        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
int min_index(vector<int> &dis, vector<int> &vis){
  int mini, minv = INT_MAX;
  for (int i = 0; i < dis.size(); i++) {
    if(!vis[i] && minv > dis[i]){
      mini = i;
      minv = dis[i];
    }
  }
  return mini;
}
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int> dis(V, INT_MAX), vis(V,0);
    dis[src] = 0;
    for (int ii = 0; ii < V-1; ii++) {
        int u = min_index(dis,vis);
        vis[u] = true;
        for (int i = 0; i < V; i++) {
          if(!vis[i] && g[u][i] && dis[u] != INT_MAX &&
            dis[u] + g[u][i] < dis[i])
            dis[i] = dis[u] + g[u][i];
        }
    }
    return dis;
}
