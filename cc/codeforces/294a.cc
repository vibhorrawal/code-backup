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
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  int n,m,x,y;
  cin>>n;
  int a[n];
  REP(i,n) cin>>a[i];
  cin>>m;
  REP(i,m){
    cin>>x>>y;
    int num = a[x-1];
    a[x-1]= 0;
    if(x>1) a[x-1-1] += y-1;
    if(y<num) a[x] += num - y;
    db(x);db(y);db(num);
  }

  REP(i,n) cout << a[i] << endl;
  return 0;
}
