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
  string s, t;
  cin>>s>>t;
  std::map<char, int> cs, ct;
  for(char c : s) cs[c]++;
  for(char c : t) ct[c]++;
  if(s.size() == t.size()){
    bool same = true;
    for(auto it : cs){
      if(ct[it.first] != it.second) same = false;
    }
    cout << (same ? "array" : "need tree") << endl;
  }
  else{
    bool alwaysLess = true;
    for(auto it : ct){
      db(cs.count(it.first));
      if(cs[it.first] < it.second) alwaysLess = false;
    }
    if(!alwaysLess) cout << "need tree" << endl;
    else{
      int i = 0, j = 0;
      while(j < t.size() && i < s.size()){
        if(s[i] == t[j]) j++;
        i++;
      }
      if(j == t.size()) cout << "automaton" << endl;
      else cout << "both" << endl;
    }
  }
  return 0;
}
