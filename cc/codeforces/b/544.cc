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
  int n, k;
  cin >> n >> k;
  vector<vector<char>> map(n, vector<char> (n, 'S'));
  int count = 0;
  if(k != 0)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(i % 2){
        if(j % 2) {
          map[i][j] = 'L';
          count++;
        }
      }
      else{
        if(j % 2 == 0) {
          map[i][j] = 'L';
          count++;
        }
      }
      if(count == k) break;
    }
    if(count == k) break;
  }
  if(count != k) cout << "NO" << endl;
  else{
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout<<map[i][j];
      }
      cout<<endl;
    }
  }
  return 0;
}
