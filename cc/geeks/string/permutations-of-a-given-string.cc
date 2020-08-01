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

void permute(string s, int l, int r){
  if(l==r) {
    cout << s << ' ';
  }
    for (int i = l; i <= r; i++) {
        swap(s[l],s[i]);
        permute(s,l+1,r);
        swap(s[l],s[i]);
    }
}

int main(int argc, char const *argv[]){
T(){
  string s;
  cin>>s;
  permute(s,0,s.size()-1);
  cout << endl;
  }
  return 0;
}
