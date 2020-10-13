#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  clr();
  ll n,k;
  cin>>n>>k;
  ll ans;
  if(k>ceil(n/2.0)){
    db(n/2.0);
    ans = (k-ceil(n/2.0));
    db(ans);
    ans =ans<<1;
    db(ans);
  }
  else{
    db(k);
    ans = (k<<1);
    db(ans);
    ans--;
    db(ans);
  }
  cout << ans << endl;
  return 0;
}
