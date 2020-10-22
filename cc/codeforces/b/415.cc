#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int divisibleBy(int num, int a, int b){
  ll res = (ll) num * a;
  res = res % b;
  return res / a;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n, a, b;
  cin>>n>>a>>b;
  REP(i,n){
    int t; cin>>t;
    cout<<divisibleBy(t,a,b)<<' ';
  }
  return 0;
}
