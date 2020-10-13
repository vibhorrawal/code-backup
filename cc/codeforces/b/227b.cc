#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

void linearSearch(){
  int n;
  cin>>n;
  map<int,int> mp;
  REP(i,n){
    int temp; cin>>temp;
    mp[temp] = i+1;
  }
  long long int c1 = 0,c2 = 0;
  int m;
  cin>>m;
  while(m--){
    int val; cin>>val;
    c1 += mp[val];
    c2 += n - mp[val]+1;
  }
  cout << c1 <<' '<<c2 << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  linearSearch();
  return 0;
}
