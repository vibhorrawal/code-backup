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
  string s, ans;
  cin>>s;
  int count = 0;
  for(char c : s){
    if(c == '1') count++;
    else ans += c;
  }
  int pos = 0;
  while(pos < ans.size() && ans[pos] == '0') pos++;
  ans.insert(pos, string(count, '1'));
  cout << ans << endl;
  return 0;
}
