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

void check(string a, std::string b){
  string c = a.substr(2,a.size()) + a.substr(0,2);
  string d = a.substr(a.size()-2,a.size()) + a.substr(0,a.size()-2);
  if(c==b||d==b) cout << "1" << endl;
  else cout << "0" << endl;
}
int main(int argc, char const *argv[]){
T(){
  string a,b;
  cin>>a>>b;
  check(a,b);
  }
  return 0;
}
