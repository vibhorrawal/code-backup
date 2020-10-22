#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n, l, r, x;
  cin >> n >> l >> r >> x;
  vi a(n);
  REP(i,n) cin >> a[i];
  int total = 1<<n;
  int res = 0;
  db(total);
  for (int bit = 0; bit < total; bit++) {
    int sum = 0, minp = INT_MAX, maxp = INT_MIN;
    for(int i = 0; i < n; i++){
      if(bit>>i & 1){
        sum += a[i];
        minp = min(minp, a[i]);
        maxp = max(maxp, a[i]);
      }
    }

    if(l <= sum && sum <= r && (maxp - minp) >= x) {
      res++;
      db(sum);db(maxp);db(minp);
    }
  }
  cout << res << endl;
  return 0;
}
