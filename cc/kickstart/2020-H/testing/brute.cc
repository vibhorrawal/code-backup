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
void solve(){
  ll l,r;
  cin>>l>>r;
  ll count = 0;
  for (int i = l; i <= r; i++) {
    db(i);
    db(isboring(i));
    count += isboring(i);
  }
  cout << count;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" <<i<<": ";
    solve();
    cout << "\n";
  }
  return 0;
}
