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

bool compare(string x, string y){
  string xy = x.append(y);
  string yx = y.append(x);
  return xy.compare(yx)>0?true:false;
}
void number(string a[], int n){
  sort(a,a+n, compare);
  REP(i,n) cout << a[i];
  cout << endl;
}
int main(int argc, char const *argv[]){
T(){
  int n;cin>>n;
  string a[n];
  REP(i,n) cin>>a[i];
  number(a,n);
}
  return 0;
}
