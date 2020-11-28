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
  int n, d;
  cin>>n>>d;
  vector<pair<int,int>> p(n); // money, friendship factor
  REP(i,n){
    cin>>p[i].first>>p[i].second;
  }
  sort(all(p));
  ll i = 0, j = 0, factor = 0, maxfactor = 0;
  while(j < n){
    while(j < n && p[j].first - p[i].first < d){
      db(j);
      factor += p[j].second;
      j++;
    }
    db(factor);
    maxfactor = max(factor, maxfactor);
    factor -= p[i++].second;
    // db(i);db(j);cout << "---" << endl;
  }
  cout << maxfactor << endl;
  return 0;
}
