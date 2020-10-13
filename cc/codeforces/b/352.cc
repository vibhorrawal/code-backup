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

int difference(vi &it, bool &notPossible){
  int diff = it[1] - it[0];
  for (int i = 0; i < it.size()-1; i++) {
    if(it[i+1] - it[i] != diff)
      notPossible = true;
  }
  return diff;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n;
  cin>>n;
  vi arr(n);
  REP(i,n) cin>>arr[i];
  map<int,vector<int>> index;
  for (int i = 0; i < n; i++) {
    index[arr[i]].push_back(i+1);
  }
  vi first, second;
  bool notPossible = false;
  for(auto it : index){
    notPossible = false;
    if(it.second.size() == 1){
      first.pb(it.first);
      second.pb(0);
      continue;
    }
    int diff = difference(it.second, notPossible);
    if(notPossible) continue;
    first.pb(it.first);
    second.pb(diff);
  }

  // if(notPossible){
  //   cout << "0" << endl;
  // }
  // else{
    cout << first.size() << endl;
    for (int i = 0; i < first.size(); i++) {
      cout<<first[i]<<' '<<second[i]<<endl;
    }
  // }

  return 0;
}
