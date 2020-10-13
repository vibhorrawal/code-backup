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

bool intersect(vector<pair<int,int>> &pp, vector<pair<int,int>>& qq, int t){
  for (int i = 0; i < pp.size(); i++) {
    for (int j = 0; j < qq.size(); j++) {
      if(pp[i].first <= qq[j].first+t && qq[j].first+t <= pp[i].second ||
        qq[j].first+t <= pp[i].first && pp[i].first <= qq[j].second+t)
          return 1;
    }
  }
  return 0;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int p,q,l,r;
  cin>>p>>q>>l>>r;
  vector<pair<int,int>> pp(p),qq(q);
  REP(i,p){
    int a,b;
    cin>>a>>b;
    pp[i] = {a,b};
  }
  REP(i,q){
    int c,d;
    cin>>c>>d;
    qq[i] = {c,d};
  }
  sort(pp.begin(), pp.end());
  sort(qq.begin(), qq.end());
  int count = 0;
  for (int t = l; t <= r; t++) {
    count += intersect(pp,qq,t);
  }
  cout << count << endl;
  return 0;
}
