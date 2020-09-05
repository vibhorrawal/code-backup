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

int sum(ll n){
  int res = 0;
  while(n){
    res += n % 10;
    n /= 10;
  }
  return res;
}

int32_t main(int argc, char const *argv[]){
  clr();
  T(){
      ll n,c=0;
      int s;
      cin>>n;
      cin>>s;
      while(n != 0 && sum(n) > s) {
        n++;
        c++;
      }
      cout << c+1 << endl;
  }
  return 0;
}
