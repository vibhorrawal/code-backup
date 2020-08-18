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

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  int n,m,sx,sy;
  cin>>n>>m>>sx>>sy;
  int l=sx,r=sx+1,u=sy,d=sy+1;
  int i = n*m;
  while(i>0){
    // if(l < 0 || r > m+1 || u < 0 || d > n+1) break;
    for(sx=l;sx<=r;sx++) i--,cout << sx << ' '<< sy << endl;
    l--; sy++;
    // if(l < 0 || r > m+1 || u < 0 || d > n+1) break;
    if(!i) break;
    for(sy=u;sy<=d;sy++) i--,cout << sx << 'b'<< sy << endl;
    u--;
    // if(l < 0 || r > m+1 || u < 0 || d > n+1) break;
    if(!i) break;

    for(sy=r;sy>l;sy--) i--,cout << sx << ' '<< sy << endl;
    r++;
    // if(l < 0 || r > m+1 || u < 0 || d > n+1) break;
    if(!i) break;

    for(sx=d;sx>u;sx--) i--,cout << sx << ' '<< sy << endl;
    d++;
    // if(l < 0 || r > m+1 || u < 0 || d > n+1) break;
  }
  return 0;
}
