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
bool prime(int num){
  for (int i = 2; i <= num/2; i++) {
    if(num % i == 0) return false;
  }
  return true;
}
int32_t main(int argc, char const *argv[]){
  clr();
  int n,m;
  cin>>n>>m;
  for (int i = n+1; i <m; i++) {
    if(prime(i)){
      cout << "NO" << endl;
      return 0;
    }
  }
  if(prime(m)) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
