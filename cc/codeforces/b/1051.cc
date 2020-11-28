#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  ll l, r;
  cin>>l>>r;
  ll d = (l + r)/2;
  cout << "YES" << endl;
  if(l == r-1) {
    cout << l << ' '<<r << endl;
    return 0;
  }
  for (ll i = l; i +1<= r; i+= 2) {
    cout << i <<' '<< i + 1 << endl;
    // assert(__gcd(i,i+1) == 1);
  }
  return 0;
}
