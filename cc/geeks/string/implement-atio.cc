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

int atoi(string s){
  int res=0;
  if(s[0] == '-') {
    for (int i = 1; i < s.size(); i++) {
      int n = s[i] - '0';
      if(n <0 || n > 9) return -1;
      res += n;
      res *= 10;
    }
    return -1*res/10;
  }

  for (int i = 0; i < s.size(); i++) {
    int n = s[i] - '0';
    if(n <0 || n > 9) return -1;
    res += n;
    res *= 10;
  }
  return res/10;
}
int main(int argc, char const *argv[]){
T(){
  string s;
  cin>>s;
  cout << atoi(s) << endl;

  }
  return 0;
}
