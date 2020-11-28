#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

bool check;

void solve(vi v){
  if(*max_element(all(v)) == 0 && *min_element)
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin>>n;
    vi v(n);
    check = false;
    REP(i,n) cin>>v[i];
    solve(v);
    cout << ( check ? "YES" : "NO" ) << endl;
  }
  return 0;
}
