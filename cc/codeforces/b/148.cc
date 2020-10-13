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
  double vp,vd,t,f,c;
  cin>>vp>>vd>>t>>f>>c;
  int count = 0;
  double time = (vp == vd ? 0 : vp * t / (vd - vp));
  if(vd > vp){
    double dist = vp * time;
    while(c > dist){
      count++;
      double delTime = f + 2 * (dist / vd);
      time += delTime;
      time += vp * delTime / (vd - vp);
      dist = vp * time;
    }
  }
  cout << count << endl;
  return 0;
}
