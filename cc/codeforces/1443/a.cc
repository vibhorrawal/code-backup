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

int32_t main(int argc, char const *argv[]){
  fastIO;
  // map<int, bool> mp;
  // for(int i = 4; i <= 1200; i += 2) mp[i] = true;
  // for(int i = 2; i <= 400; i += 2) mp[3*i] = true;
  // for(auto it : mp){
  //   int x = it.first;
  //   for(int i = 2; i*x <= 1200; i++){
  //     int t = i * x;
  //     if(mp.count(t)) mp[t] = false;
  //   }
  // }
  // vi v;
  // for (int i = 0; i < v.size(); i++) {
  //   for (int j = 0; j < v.size(); j++) {
  //     int t = __gcd(v[i], v[j]);
  //     if(i!=j) assert(t!= 1 || t != v[i] || t != v[j]);
  //   }
  // }
  // for(auto it : mp) if(it.second) v.pb(it.first);
  // db(v.size());
  // db(v.back());
  T(){
    int n;
    cin>>n;
    for (int i = n * 4, count = 0; count < n; i -= 2, count++) {
      cout << i << ' ';
    }
    cout<<endl;
  }
  return 0;
}
