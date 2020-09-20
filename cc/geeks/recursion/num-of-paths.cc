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

int dx[] = {0,1};
int dy[] = {1,0};
int num_path(int x, int y, int m, int n){
  if(x == m-1 && y == n-1)
    return 1;
  int count = 0;
  for (int i = 0; i < 2; i++) {
    int xi = x + dx[i];
    int yi = y + dy[i];
    if(xi < 0 || xi >= m || yi < 0 || yi >= n)
      continue;
    count += num_path(xi,yi,m,n);
  }
  return count;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n, m;   
    cin >> m >> n;
    cout << num_path(0,0,m,n) << endl;
  }
  return 0;
}
