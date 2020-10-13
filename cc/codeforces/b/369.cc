#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  ll n, k, l, r, sall, sk;
  cin >> n>> k>> l >> r >> sall >> sk;
  std::vector<ll> v(n, l);
  sall -= sk;
  sk -= k * l;
  int t = sk / k;
  for(int i = 0; i < k; i++){
    v[i] += t;
    sk -= t;
  }
  for (int i = 0; i < k; i++) {
    if(sk == 0) break;
    ll temp = r - v[i];
    v[i] += min(temp, sk);
    sk -= min(temp, sk);
  }
  if(n == k) goto PRINT;
  sall -= (l * (n-k));
  t = sall / (n-k);
  for(int i = k; i < n; i++){
    v[i] += t;
    sall -= t;
  }
  for (int i = k; i < n; i++) {
    if(sall == 0) break;
    ll temp = v[k-1] - v[i];
    v[i] += min(temp, sall);
    sall -= min(temp, sall);
  }
  PRINT:
  for (int i = 0; i < n; i++) {
    cout << v[i]<<' ';
  }cout << endl;
  return 0;
}
