//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb emplace_back
#define db(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  int n;
  cin>>n;
  int a[n];
  REP(i,n) cin>>a[i];
  int i=0, j = n-1;
  int s=0,d=0;
  bool f = true;
  while(i<=j){
    if(a[i] > a[j]){
      if(f) s += a[i];
      else d += a[i];
      i++;
    }
    else{
      if(f) s += a[j];
      else d += a[j];
      j--;
    }
    f = !f;
  }
  cout << s << ' '<< d << endl;
  return 0;
}
