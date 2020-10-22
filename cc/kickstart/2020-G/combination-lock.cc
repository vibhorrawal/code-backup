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

int w, n;

void wrapUp(int &a){
  a++;
  a = ((a - 1) % n) + 1;
}

void wrapDown(int &a){
  a--;
  a = ((a - 1) % n) + 1;
  if(a < 1) a += n;
}
class Arr {
public:
  int a[1005];
  Arr(){
  }
  bool operator< (const Arr &other) const{
    for (int i = 0; i < w; i++) {
      if(a[i] == other.a[i]) continue;
      return a[i] < other.a[i];
    }
    return false;
  }
};
bool check(Arr &v){
  int a = v.a[0];
  for (int i = 0; i < w; i++) {
    if(v.a[i]!= a) return false;
  }
  return true;
}
ll solve(){
  cin>>w>>n;
  Arr v = Arr();
  REP(i,w) cin>>v.a[i];
  queue<pair<Arr, ll>> q;
  set<Arr> used;
  q.push({v,0});
  used.insert(v);
  while(!q.empty()){
    auto it = q.front(); q.pop();
    v = it.first;
    if(check(v)) return it.second;
    for (int i = 0; i < w; i++) {
      wrapUp(v.a[i]);
      if(used.count(v)) {
        wrapDown(v.a[i]);
        continue;
      }
      used.insert(v);
      q.push({v, it.second + 1});
      wrapDown(v.a[i]);
    }
    for (int i = 0; i < w; i++) {
      wrapDown(v.a[i]);
      if(used.count(v)) {
        wrapUp(v.a[i]);
        continue;
      }
      used.insert(v);
      q.push({v, it.second + 1});
      wrapUp(v.a[i]);
    }
  }
  return -1;
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
