#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)

int main(int argc, char const *argv[]){
  T(){
    int n;
    cin>>n;
    int a[n-1];
    REP(i,n-1) cin>> a[i];
    int res = 0;
    REP(i,n) res ^= (i + 1);
    REP(i,n-1) res ^= a[i];
    cout << res << endl;
  }
  return 0;
}
