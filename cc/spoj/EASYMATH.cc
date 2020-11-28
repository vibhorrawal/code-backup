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

int32_t main(int argc, char const *argv[]){
  fastIO;
  ll n,m,a,d;
  T(){
    cin>>n>>m>>a>>d;
    set<ll> s;
    for(ll j = 0; j <= 4; j++){
      ll div = a + j * d;
      ll t = ceil( (double) n / div );
      t = t * div;
      for(ll i = t; i <= m; i+= div){
        s.insert(i);
      }
    }
    cout << (m-n+1 - s.size()) << endl;
  }

  return 0;
}
