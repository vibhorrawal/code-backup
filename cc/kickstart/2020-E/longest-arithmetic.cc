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

int test_case(v1d &v){
  int n = v.size();
  if(n == 2){
    return 2;
  }
  std::vector<long long int> diff(n-1);
  for (int i = 0; i < n-1; i++) {
    diff[i] = v[i+1] - v[i];
  }
  ll d = diff[0], count=2, ans=2;
  for (int i = 1; i < n-1; i++) {
    if(diff[i] == d){
      count++;
      ans = max(count,ans);
    }
    else{
      d = diff[i];
      count=2;
    }
  }
  return ans;
}
int32_t main(int argc, char const *argv[]){
  clr();
  int T;
  cin>>T;
  REP(i,T){
    int n;
    cin>>n;
    v1d v(n);
    REP(j,n) cin>>v[j];
    cout<<"Case #"<<i+1<<": "<<test_case(v)<<endl;
  }
  return 0;
}
