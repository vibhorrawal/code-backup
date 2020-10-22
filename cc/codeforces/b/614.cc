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

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n; cin>>n;
  ll total0 = 0;
  string num;
  REP(i,n) {
    string t; cin>>t;
    int count1 = 0, count0 = 0, count_ = 0;
    if(t == "0") {
      cout << "0" << endl;
      return 0;
    }
    for(char c : t){
      if(c == '0') count0++;
      else if(c == '1') count1++;
      else count_++;
    }
    if(count1 <= 1 && count_ == 0){
      total0 += count0;
    }
    else num = t;
  }
  if(num == "") cout<<1;
  else cout<<num;
  REP(i,total0) cout<<0;
  cout << endl;
  return 0;
}
