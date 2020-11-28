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

int n;
ll solve(const vi &t){
  set<int> s;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if(s.count(t[i])){
      int l = t[i], r = t[i];
      db(l*1);db(r*1);
      while(l >= 1 && s.count(l) && s.count(r)){
        l--;r++;
      };
      db(l*1);db(r*1);
      if(l < 1){
        // db(s.count(r));
        if(s.count(r)){
          while(s.count(r) == 1) r++;
          // db(r);
        }
        // db(s.count(r));
        ans += abs(r - t[i]);
        if(DEBUG){ assert(s.count(r) == 0); };
        db(r);
        s.insert(r);
      }
      else{
        if(s.count(l) == 0){
          ans += abs(l - t[i]);
          if(DEBUG){ assert(s.count(l) == 0); };
          db(l);
          s.insert(l);
        }
        else if(s.count(r) == 0){
          ans += abs(r - t[i]);
          if(DEBUG){ assert(s.count(r) == 0); };
          db(r);
          s.insert(r);
        }
        else {
          while(s.count(r++));
          ans += abs(r - t[i]);
          if(DEBUG){ assert(s.count(r) == 0); };
          db(r);
          s.insert(r);
        }
      }
    }
    else {
      s.insert(t[i]);
      db(t[i]);
    }
  }
  return ans;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    cin>>n;
    vi t(n);
    REP(i,n) cin>>t[i];
    sort(all(t));
    ll ans = solve(t);
    do{
      if(rand() % 200) continue;
      ans = min(ans, solve(t));
    }while(next_permutation(all(t)));
    cout << ans << endl;
  }
  return 0;
}
