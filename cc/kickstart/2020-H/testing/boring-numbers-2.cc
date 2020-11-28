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

map<int,ll> mp;
bool isboring(int n){
  string s = to_string(n);
  bool odd = true;
  int i = 0;
  while(i < sz(s)){
    int d = (s[i] - '0') % 10;
    if(odd && (d % 2 == 0)) return false;
    if((!odd) && (d % 2 == 1)) return false;
    i++;
    odd = not odd;
  }
  return true;
}

vector<ll> break_period(ll l, ll r){
  vector<ll> v;
  v.pb(l);
  int d = ceil(log10(l));
  while(d < ceil(log10(r))){
    v.pb(pow(10,d));
    d++;
  }
  v.pb(r);
  auto ip = unique(all(v));
  v.resize(distance(v.begin(), ip));
  return v;
}

void solve(){
  ll l,r;
  cin>>l>>r;
  ll count = 0;
  if(ceil(log10(l)) == ceil(log10(r))){
    for (int i = l; i <= r; i++) {
      db(i);
      db(isboring(i));
      count += isboring(i);
    }
  }
  else{
    vector<ll> v = break_period(l,r);
    cout<<"v: "; for(int i = 0; i < sz(v) ; i++){ cout<<v[i]<<' ';}cout<<endl;
    for (int i = v[0]; i <= v[1]; i++) {
      db(i);
      db(isboring(i));
      count += isboring(i);
    }
    if(v.size() > 3)
    for (int i = 1; i <= sz(v) - 2; i++) {
      int dig = log10(v[i]);
      db(dig);
      // db(isboring(i));
      count += mp[dig];
    }
    for (int i = v[sz(v) - 2] + 1; i <= v[sz(v)-1]; i++) {
      db(i);
      db(isboring(i));
      count += isboring(i);
      db(count);
    }
  }
  cout << count;
}

ll odd_len(int d){
  ll ans = 0;
  // last dig will be odd
  ans = 5;
  d--;
  while(d){
    ans = ans * 10;
    d--;
  }
  return ans;
}

ll even_len(int d) { return odd_len(d); }

void build(){
  mp.clear();
  // mp: key -> val will be noOfDigits -> total boring nums of digit len
  for(int d = 1; d <= 18; d++){
    if(d & 1){
      mp[d] = odd_len(d);
    }
    else mp[d] = even_len(d);
  }
  // for(auto it : mp){
  //   cout << it.first << ' ' << it.second << endl;
  // }
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  build();
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" <<i<<": ";
    solve();
    cout << "\n";
  }
  return 0;
}
