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

int32_t main(int argc, char const *argv[]){
  fastIO;
  string s, t;
  cin>>s>>t;
  ll res = 0;
  for (int i = 0; i <= sz(t) - sz(s); i++) {
    for (int j = 0; j < sz(s); j++) {
      // db(s[j] - '0');
      // db((t[i + j] - '0'));
      res += (t[i + j] - '0') ^ (s[j] - '0');
    }
  }
  cout << res << endl;
  return 0;
}
