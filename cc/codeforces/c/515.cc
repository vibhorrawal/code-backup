#include<bits/stdc++.h>
using namespace std;
#define ll long long
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

string transform(int n){
  switch (n) {
    case 0: case 1: return "";
    case 2: return "2";
    case 3: return "3";
    case 4: return "322";
    case 5: return "5";
    case 6: return "53";
    case 7: return "7";
    case 8: return "7222";
    case 9: return "7332";
    default: assert(false);
  }
  return "";
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n;
  cin>>n;
  string s;
  cin>>s;
  string ans;

  for(char c : s){
    ans += transform(c - '0');
  }
  sort(ans.rbegin(), ans.rend());
  cout << ans << endl;
  return 0;
}
