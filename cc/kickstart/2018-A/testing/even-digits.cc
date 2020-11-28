#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

vi digit(int n){
  vi v;
  while(n){
    int s = n % 10;
    v.pb(s);
    n /= 10;
  }
  reverse(all(v));
  return v;
}
ll num(vi v){
  ll n = 0, i = 0;
  while(i < sz(v)){
    n = (n * 10) + v[i];
    i++;
  }
  return n;
}
void dec(vi &v){
  int i = 0;
  while(i < sz(v) && (v[i] % 2 == 0)){
    i++;
  }
  if(i < sz(v)) v[i]--;
  for (int j = i+1; j < sz(v); j++) {
    v[j] = 8;
  }
}

void inc(vi &v){
  int i = 0;
  while(i < sz(v) && (v[i] % 2 == 0)){
    i++;
  }
  if(i == sz(v)) return;

  for (int j = i+1; j < sz(v); j++) {
    v[j] = 0;
  }
  if(v[i] != 9){
    v[i]++;
    return;
  }
  v[i] = 0;
  i--;
  while(i >= 0 && v[i] == 8){
    v[i] = 0;
    i--;
  }
  if(i == -1){
    reverse(all(v));
    v.pb(2);
    reverse(all(v));
    return;
  }
  v[i] += 2;
}
ll solve(ll n){
  vi less = digit(n);
  vi more = digit(n);
  dec(less);
  inc(more);
  db(num(less));
  db(num(more));
  return min(n - num(less), num(more) - n);
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    ll n; cin>>n;
    cout<<"Case #"<<i<<": "<<solve(n)<<"\n";
  }
  return 0;
}
