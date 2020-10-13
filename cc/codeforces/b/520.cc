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

int main(int argc, char const *argv[]) {
  int n,m;
  cin>>n>>m;
  int count = 0;
  // do reverse
  if(m <= n){
    cout << n-m << endl;
  }
  else{
    while(m > n){
      if(m+1 == n){
        count++;
        break;
      }
      if(m % 2) {
        m = (m+1) /2;
        count += 2;
      }
      else {
        m /= 2;
        count++;
      }
    }
    cout << count + (n-m)<< endl;
  }
  return 0;
}
/*
// correct
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n,m;
  cin>>n>>m;
  queue<pair<int,int>> q;
  set<int> s;
  q.push({n,0});
  while(q.size()){
    auto it = q.front(); q.pop();
    if(s.count(it.first)) continue;
    if(it.first == m){
      cout << it.second << endl;
      return 0;
    }
    if(it.first * 2 < 100000) q.push({it.first * 2, it.second+1});
    if(it.first > 1) q.push({it.first - 1, it.second+1});
    s.insert(it.first);
  }
  cout<< -1;
  return 0;
}
*/
