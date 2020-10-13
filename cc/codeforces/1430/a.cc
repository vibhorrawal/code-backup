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

void rooms(int n){
  const int MAX = 200;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      for (int k = 0; k < MAX; k++) {
        if(i * 3 + j * 5 + 7 * k == n){
          cout << i << ' ' << j << ' ' << k << endl;
          return;
        }
      }
    }
  }
  cout << "-1" << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin>>n;
    // cout << rooms(n) << endl;
    rooms(n);
  }
  return 0;
}
