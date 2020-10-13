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

int count(string s){
  db(s);
  int counter = 0;
  while(s.size()){
    if(s.size() == 1) {
      counter++;
      break;
    }
    if(s[0] == s[1]) {
      counter++;
      int i = 1;
      while(s[0] == s[i]) i++;
      s = s.substr(i, s.size());
      continue;
    }
    int i = 1;
    for(; i < (int) s.size(); i++){
      if(s[i-1] == s[i]) break;
    }
    if(i == (int) s.size()){
      counter += (s.size() + 1) / 2;
      break;
    }
    s = s.substr(0, i) + s.substr(i, s.size());
    s.erase(s.begin());
    counter++;
  }
  return counter;
}

int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    string s;
    int t;
    cin>>t;
    cin>>s;
    cout << count(s) << endl;
  }
  return 0;
}
