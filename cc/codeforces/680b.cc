#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  clr();
  int n;
  int a;
  cin>>n>>a;
  int city[n];
  a--;
  REP(i,n) cin>>city[i];
  int count=city[a];
  int l=a-1,r=a+1;
  while(l>=0 && r<n){
    if(city[l] == city[r] && city[l]==1){
      count+=2;
    }
    l--,r++;
  }
  db(count);
  while(l>=0){
    if(city[l] == 1) count++;
    l--;
  }
  while(r<n) {
    if(city[r] == 1) count++;
    r++;
  }
  cout << count << endl;
  return 0;
}
