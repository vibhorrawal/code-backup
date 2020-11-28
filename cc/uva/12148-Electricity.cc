// WA
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

const int d = 0, m = 1, y = 2, c = 3;


inline bool leap(const int &yr){
  return yr % 400 == 0 or (yr % 4 == 0 and yr % 100 != 0);
}

inline bool lastday(int mm, int dd){
  if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
    return dd == 31;
  return dd == 30;
}
inline bool nextDay(const vi &curr, const vi &prev){
  return (
    (curr[y] == prev[y] && curr[m] == prev[m] && (curr[d] == prev[d] + 1)) ||
    (curr[y] == prev[y] && prev[m] == 2 && prev[d] == 28 &&
      ( (leap(curr[y]) && curr[d] == 29 && curr[m] == 2) || (not leap(curr[y]) && curr[d] == 1 && curr[m] == 3)) ) ||
    (curr[d] == 1 && curr[m] == 1 && prev[d] == 31 && prev[m] == 12 && (curr[y] == prev[y] + 1)) ||
    (prev[m] != 2 && (curr[m] == prev[m] + 1) && curr[y] == prev[y] && curr[d] == 1 && lastday(prev[m], prev[d]))
  );
}

// int toDay(const vi &v){
//
// }
int32_t main(int argc, char const *argv[]){
  fastIO;
  while(1){
    int n;
    cin>>n;
    vvi v(n, vi(4)); // d, m, y, c
    if(n == 0) break;
    REP(i,n) cin>>v[i][d]>>v[i][m]>>v[i][y]>>v[i][c];
    ll cost = 0, day = 0;
    for (int j = 1; j < n; j++) {
      if(nextDay(v[j], v[j-1])){
        cost += v[j][c] - v[j-1][c];
        day++;
      }
    }
    cout <<day << ' ' << cost << endl;
  }
  return 0;
}
