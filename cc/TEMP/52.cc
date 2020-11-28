#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

ll sum(int n){
  ll res = 0;
  for (int i = 0; i <= n; i++) {
    res += pow(2,i);
  }
  return res;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n = 747597153;
  int i = 0;
  while(sum(i) < n) i++;
  cout <<( sum(--i) )<< endl;
  return 0;
}
