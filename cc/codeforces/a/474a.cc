#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  clr();
  string s[3];
  s[0] = "qwertyuiop";
  s[1] = "asdfghjkl;";
  s[2] = "zxcvbnm,./";
  string in;
  char c;
  cin>>c;
  cin>>in;
  if(c=='L'){
    for(auto ch: in){
      for (int i = 0; i < 3; i++) {
        auto it = s[i].find(ch) ;
        if(it != -1){
          cout <<char(s[i][++it]);
          break;
        }
      }
    }
  }
  else{
    for(auto ch: in){
      for (int i = 0; i < 3; i++) {
        auto it = s[i].find(ch) ;
        if(it != -1){
          cout <<char(s[i][--it]);
          break;
        }
      }
    }
  }
  return 0;
}
