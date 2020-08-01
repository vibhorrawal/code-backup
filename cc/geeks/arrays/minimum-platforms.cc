#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

bool compare(pair<int,int> a, pair<int,int> b){
  return a.first < b.first;
}
int platforms(int a[], int d[], int n){
  pair<int,int> arr[n];
  REP(i,n) arr[i] = mp(a[i],d[i]);
  sort(arr,arr+n,compare);
  int ans = 0;
  REP(i,n){

  }
  return ans;
}

int minPlatforms(int a[], int d[], int n){
  //time given on a day 2359 or 0 to 2360
  int platforms[2361]={0};
  int ans = 1;
  REP(i,n){
    ++platforms[a[i]];
    --platforms[d[i]+1];
  }
  for (int i = 1; i < 2361; i++) {
    platforms[i] += platforms[i-1];
    ans = max(ans,platforms[i]);
  }
  return ans;
}

int main(int argc, char const *argv[]){
  T(){
    int n;cin>>n;
    int a[n],d[n];
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>d[i];
    cout<< minPlatforms(a,d,n)<<endl;
  }
  return 0;
}
