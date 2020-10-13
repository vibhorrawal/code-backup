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

int32_t main(int argc, char const *argv[]){
  fastIO;
  int xc,yc,n;
  cin>>n>>xc>>yc;
  set<double> slope;
  const int INF = 1e9 + 7;
  REP(i,n){
    int x,y;
    cin>>x>>y;
    double m = y - yc;
    if(x == xc) slope.insert(INF);
    else slope.insert(m/(x-xc));
  }
  cout << slope.size() << endl;
  return 0;
}
