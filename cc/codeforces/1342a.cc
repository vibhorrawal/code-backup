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
#define pb(a) push_back(a)

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  // iinternaut();
  T(){
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    ll minval = min(abs(x),abs(y)), diff = abs(abs(x)-abs(y));
    ll abssum = abs(abs(x)+abs(y));
    cout << min(abssum*a, (diff*a)+(minval*b*2)) << endl;

  }
  return 0;
}
