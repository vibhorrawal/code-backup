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

int32_t main(int argc, char const *argv[]){
  iinternaut();
  int n,m,k_min;
  cin>>n>>m>>k_min;
  int graph[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = INT_MAX;
    }
  }
  int x,y,w;
  for (int i = 0; i < m; i++) {
    cin>>x>>y>>w;
    graph[x][y] = w;
    graph[y][x] = w;
  }
  int dist[n][n],i,j,k;
  for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
          dist[i][j] = graph[i][j];

          for (k = 0; k < n; k++)
          {
              // Pick all vertices as source one by one
              for (i = 0; i < n; i++)
              {
                  // Pick all vertices as destination for the
                  // above picked source
                  for (j = 0; j < n; j++)
                  {
                      // If vertex k is on the shortest path from
                      // i to j, then update the value of dist[i][j]
                      if (dist[i][k] + dist[k][j] < dist[i][j])
                          dist[i][j] = dist[i][k] + dist[k][j];
                  }
              }
          }
          int x1;
          for (int k = 0; k < n; k++)
          {
      for (int m = 0; m < n; m++)
      {
          x1 = m+1;
          for (int i = k; i < n ; i++)
          {
              for (int j = x1; j < n; j++)
              {
                  if (dist [k][m] > dist [i][j])
                      swap(dist [k][m] ,dist [i][j]);
              }
              x1=0;
          }
      }
  }
    k=0;
    // cout<<k_min<<endl;
    for(i = 0; i<n;i++){
    for(j=0;j<n;j++){
      k++;
      if(k == k_min)
      break;
    }
  }
    // cout<<i<<' '<<j;
          cout<<dist[i][j]<<endl;
  return 0;
}
