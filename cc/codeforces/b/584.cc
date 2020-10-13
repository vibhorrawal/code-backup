#include<bits/stdc++.h>
using namespace std;
// #define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
typedef long long int ll;
const int MOD = 1e9+7;

ll power(ll A, ll B){
  ll result = 1;
  while(B){
    if(B & 1) result = (result * A) % MOD;
    A = (A * A) % MOD;
    B /= 2;
  }
  return result;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n;
  cin>>n;
  ll res = power(3,3 * n) - power(7,n) % MOD;
  if(res < 0) res += MOD;
  cout << res << endl;
  return 0;
}
