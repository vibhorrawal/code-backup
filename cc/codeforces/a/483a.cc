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

int main(){
  ll l,r;
  cin>>l>>r;
  if( l % 2 != 0) l++;
  if(l+2 > r) cout << "-1" << endl;
  else cout << l<<' '<<l+1<<' '<<l+2 << endl;
}
//wrong
/*int32_t main(int argc, char const *argv[]){
  clr();
  ll l,r;
  cin>>l>>r;
  ll left = l;
  while(l<r && __gcd(l,r) == 1) l++;
  if(l==r) l = left;
  while(l<r && __gcd(l,r) == 1) r--;
  if(l==r){
    cout << -1 << endl;
    return 0;
  }
  for (ll i = l; i <= r; i++) {
    if(__gcd(l,i) == 1 && __gcd(i,r) == 1){
      cout << l<<' '<<i<<' ' <<r<< endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}*/
