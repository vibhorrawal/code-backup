#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

string prefix(string s[], int n){
  char c;
  for (int i = 0; i < s[0].size(); i++) {
    c = s[0][i];
    for (int j = 1; j < n; j++) {
      if(c != s[j][i]){
        if(!i) return "-1";
        return s[0].substr(0,i);
      }
    }
  }
  return s[0];
}
int main(int argc, char const *argv[]){
T(){
  int n;cin>>n;
  string a[n];
  REP(i,n) cin>>a[i];
  cout << prefix(a,n) << endl;
  }
  return 0;
}
