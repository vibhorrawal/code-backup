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
  int n;
  cin>>n;
  ll res = 0;
  multiset<ll> lft,rt;
  REP(i,n){
    int a,b;
    cin>>a>>b;
    if(lft.count(a-b)){
      res+= lft.count(a-b);
    }
    if(rt.count(a+b)) res+= rt.count(a+b);
    lft.insert(a-b);
    rt.insert(a+b);
  }
  // for(auto it : lft){
  //   db(it);
  //   db(lft.count(it));
  //   res += max(0LL, (ll) lft.count(it)-1);
  //   // res += max(0LL, (ll) rt.count(it) - 1);
  //   // db(res);
  //   // cout << lft.count(it) << endl;
  // }
  // ll res2 = 0;
  // for(auto it : rt){
  //   db(it);
  //   db(rt.count(it));
  //   // res2 += max(0LL, (ll) lft.count(it)- 1);
  //   res += max(0LL, (ll) rt.count(it)-1);
  //   // db(res);
  //   // cout << lft.count(it) << endl;
  // }
  cout << res << endl;
  // cout << res2 << endl;
  return 0;
}
