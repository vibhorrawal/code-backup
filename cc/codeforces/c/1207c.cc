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
  T(){
    ll n,a,b;
    cin>>n>>a>>b;
    bool s[n] = {0};
    string str;
    cin>>str;
    REP(i,n) s[i] = str[i] - '0';
    // if(DEBUG){ cout<<"s: "; REP(i,n) cout<<s[i]; cout<<endl;};
    ll cost = 0;
    //cost of pipeline
    int prev = 0;
    cost += a;
    for (ll i = 1; i < n; i++) {
      if(prev != s[i])
       cost += 2*a;
      else cost += 1*a;
      prev = s[i];
    }
    //cost of pillar
    cost += b;
    REP(i,n) cost += (s[i] + 1)*b;

    cout<<cost<<endl;
  }
  return 0;
}
