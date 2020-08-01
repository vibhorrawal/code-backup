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

int main(int argc, char const *argv[]){
T(){
  std::string s;
  cin>>s;
  int ans = -1;
  for (int i = 0; i < s.size(); i++) {
    if(s[i] == '1') ans = i;
  }
  cout << ans << endl;
}
  return 0;
}
