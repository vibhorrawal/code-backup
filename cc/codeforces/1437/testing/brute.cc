#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
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

int32_t main(int argc, char const *argv[]){
  T(){
    int l,r;
    cin>>l>>r;
    bool possible = true;
    int a;
    for ( a = 2; a < 2*r; a++) {
      possible = true;
      for (int i = l; i <= r; i++) {
        if(i % a >= a/2.0) continue;
        else possible = false;
      }
      if(possible) break;
    }
    cerr<<a<<endl;
    cout << (possible ? "YES" : "NO") << endl;
  }
  return 0;
}
