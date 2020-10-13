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
  int n,t1,t2,k;
  cin>>n>>t1>>t2>>k;
  vector<pair<int,double>> participant(n);
  double kk = (100.0-k) / 100.0;
  REP(i,n){
    double a,b;
    cin>>a>>b;
    double growth = max(a * t1 * kk + b * t2, b * t1 * kk + a * t2);
    participant[i] = {i+1, growth};
  }
  sort(participant.begin(), participant.end(), [](pair<int,double> a, pair<int,double> b){
    if(abs(a.second - b.second) >= 0.01){
      return a.second > b.second;
    }
    return a.first < b.first;
  });

  for (int i = 0; i < n; i++) {
    cout<<participant[i].first <<' ';
    printf("%.2f\n", participant[i].second);
  }
  return 0;
}
