#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<ll>
#define v2d  vector<vector<ll> >
#define M 1000000007
#define T() ll tc;cin>>tc;while(tc--)
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

void solve(){
  ll n, k;
  cin>>n>>k;
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    cin>>arr[i];
  }
  string out;
  ll i = 0;
  ll temp = 0, subset = 0;
  while (subset < k-1) {
    temp += arr[i]%2;
    if(temp%2 == 1){
      out += to_string(i+1); out += ' ';
      temp = 0;
      subset++;
    }
    i++;
  }
  while(i < n){
    temp += arr[i++]%2;
  }
  if(temp%2)
    cout<<"YES\n"<<out<<to_string(n)<<endl;
  else
    cout<<"NO\n";
}
int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
  solve();
}
  return 0;
}
