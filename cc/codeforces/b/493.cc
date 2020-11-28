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
  int n;
  cin>>n;
  vi first, second;
  int x;
  REP(i,n){
    cin>>x;
    if(x>0) first.pb(x);
    else second.pb(-x);
  }
  ll f = accumulate(all(first), 0LL), s = accumulate(all(second), 0LL);
  if(f == s){
    int i = 0;
    while(i < min(sz(first),sz(second)) && first[i] == second[i])
      i++;
    db(i);
    if(i < min(sz(first), sz(second))){
      if(first[i] > second[i]) cout << "first" << endl;
      else cout << "second" << endl;
    }
    else if(i < sz(first)) cout << "first" << endl;
    else if(i < sz(second)) cout << "second" << endl;
    else{
      if(x > 0) cout << "first" << endl;
      else cout << "second" << endl;
    }
  }
  else if(f > s) cout << "first" << endl;
  else if(f < s) cout << "second" << endl;
  else assert(false);
  return 0;
}
