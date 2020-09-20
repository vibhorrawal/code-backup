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

void sort_print(vi &v, int n){
  map<int, int> mp;
  for(auto i: v) mp[i]++;
  //rest is same ab below
}
/*
void sort_print(vi &v, int n){
  vi freq(60);
  for(int a: v) freq[a]++;
  vector<pair<int,int>> vp;
  for(int i = 0; i < 60; i++){
    if(freq[i] == 0)
      continue;
    vp.push_back({freq[i],i});
  }
  sort(all(vp), [](const pair<int, int> a, const pair<int, int> b){
    if(a.first != b.first)
      return a.first > b.first;
    return a.second < b.second;
  });
  for(auto a: vp)
    REP(i,a.first) cout<<a.second<<' ';
    cout<<endl;
}*/
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin >> n;
    vi v(n);
    REP(i,n) cin >> v[i];
    sort_print(v,n);
  }
  return 0;
}
