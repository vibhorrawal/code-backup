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

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n,m,k;
  vector<int> r1,p1,p2;
  cin>>n;
  REP(i,n) {
    int t; cin>>t;
    r1.pb(t);
  }
  cin>>m;
  REP(i,m) {
    int t; cin>>t;
    p1.pb(t);
  }
  cin>>k;
  REP(i,k) {
    int t; cin>>t;
    p2.pb(t);
  }
  int A,B; cin>>A>>B;
  double ratio = B/A;
  double ans = 0;
  int i = r1.size()-1, j = p1.size()-1, kk = 0;
  // for(int i = 0; i < r1.size(); i++){
  //   for(int j = 0; j < p1.size(); j++){
  //     for(int k = 0; k < p2.size(); k++){
        double r2 = (double) p1[j] * r1[i] * r1[i] * B / (B * p1[j] + A * p2[kk]);
        r2 = pow(r2, 0.5);
  //       if(r2 < r1[i]){
  //         ans = max(ans, r2);
  //       }
  //     }
  //   }
  // }
  printf("%.9f\n", r2);
  return 0;
}
