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
  T(){
    int n; cin>>n;
    vector<tuple<int,int,int>> v(n);
    map<int,int> mp;
    REP(i,n) {
      int t; cin>>t;
      mp[t]++;
      v[i] = {mp[t],t,i+1};
    }
    sort(all(v)); reverse(all(v));
    // count, val, index
    int prevcount = get<0>(v[0]), prevVal = get<1>(v[0]), prevIdx = get<2>(v[0]);
    auto toDelete = v[0];
    string s;
    bool flag = 0;
    for (int count = 0; count < n-1; count++) {
      flag = false;
      for (int i = 0; i < v.size(); i++) {
        if(get<1>(v[i]) != prevVal){
          s += to_string(prevIdx) + " "  + to_string(get<2>(v[i])) + "\n";
          prevVal = get<1>(v[i]);
          prevIdx = get<2>(v[i]);
          auto temp = toDelete;
          toDelete = v[i];
          v.erase(find(all(v), temp));
          flag = true;
          break;
        }
      }
      if(!flag) goto NO;
      // cout<<"v[i]: "; for(int i = 0; i < v.size() ; i++){ cout<<get<2>(v[i])<<' ';}cout<<endl;
    }
    db(v.size());
    if(v.size() <= 1){
      cout << "YES\n"<< s;
    }
    else NO:cout << "NO" << endl;
  }
  return 0;
}
