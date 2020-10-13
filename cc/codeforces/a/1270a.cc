// #pragma GCC optimize ("O3")
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
  iinternaut();
  T(){
    int n, k1, k2;
    cin>>n>>k1>>k2;
    bool win1 = false;
    int val;
    REP(i,k1){
      cin>>val;
      if(val == n) win1 = true;
    }
    REP(i,k2){
      cin>>val;
      if(val == n) win1 = false;
    }
    if(win1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
