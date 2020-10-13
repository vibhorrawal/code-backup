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
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int count(int t, int k, std::vector<bool> &v){
  while(t){
    int s = t%10;
    t /= 10;
    if(s>k) {
      continue;
      return 0;
    }
    v[s] = true;
  }
  bool flag=1;
  REP(i,k+1) flag *= v[i];
  return flag?1:0;
}

int32_t main(int argc, char const *argv[]){
  clr();
  int n,k;
  cin>>n>>k;
  int t,ans=0;
  std::vector<bool> v(k+1);
  REP(i,n){
    cin>>t;
    // memset(v,false,k);
    fill(all(v),false);
    ans += count(t,k,v);
  }
  cout<< ans<<endl;
  return 0;
}
