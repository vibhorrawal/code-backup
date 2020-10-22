#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

ll w, n;

void wrapUp(int &a){
  a++;
  a = ((a - 1) % n) + 1;
}

void wrapDown(int &a){
  a--;
  a = ((a - 1) % n) + 1;
  if(a < 1) a += n;
}

ll calc(ll a, ll b){
  ll res = abs(a - b);
  return min(res, (n - res));
}
ll solve(){
  cin>>w>>n;
  vi v(w);
  REP(i,w) cin>>v[i];
  ll minDist = INT_MAX, dist = 0;

  for (int i = 1; i <= n; i++) {
    int selected = i;
    dist = 0;
    for (int j = 0; j < w; j++) {
      dist += calc(selected, v[j]);
    }
    minDist = min(dist, minDist);
  }
  return minDist;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i<<": "<<solve();
    cout<<endl;
  }
//
// int a = 2;
// n = 3;
//   for (int i = 0; i < 10; i++) {
//      wrapDown(a);
//     cout <<a << endl;
//   }
  return 0;
}
