#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl 'n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int OR(int arr[], int incl[], int n){
  int val = 0;
  for (int i = 0; i < n; i++) {
    if(!incl[i]) val |= arr[i];
  }
  return val;
}
int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
    int n;
    cin>>n;
    int arr[n];
    bool incl[n] = {0};
    FOR(i,arr) cin>>arr[i];

    int maxx = INT_MAX;
    int happiness = OR(arr,incl,n);
    for (int i = 0; i < n; i++) {
      if(!incl[i]){
        incl[i] = 1;
        maxx = (OR(arr,incl,n));

        if()
      }
    }
  }
  return 0;
}
