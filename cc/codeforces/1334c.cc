//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 0
#define pb(a) push_back(a)

int32_t main(int argc, char const *argv[]){
  T(){
    int n;
    cin>>n;
    int a[n], b[n];
    bool kill[n] = {0};
    REP(i,n){
      cin>>a[i]>>b[i];
    }
    int small_i, check;
    int small = INT_MAX;
    int count = 0;

    while(1){
      check = 1;
      REP(i,n){
        check *= kill[i];
      }
      if(check) break;
      small = INT_MAX;
      REP(i,n){
        if(!kill[i] && small > a[i]){
          small_i = i,small = a[i];
        }
      }
      if(DEBUG){ cout<<"a: "; for(int i = 0; i < n ; i++){ cout<<a[i]<<'\t';}cout<<endl;cout<<"b: "; for(int i = 0; i < n ; i++){ cout<<b[i]<<'\t';}cout<<endl;cout << "i: "<<small_i << endl; };
      count += a[small_i];
      a[small_i] = INT_MAX;
      kill[small_i] = 1;
      a[(small_i+1) % n] -= b[small_i];
      while(a[(small_i + 1) % n] < 0){
        kill[++small_i%n] = 1;
        a[(small_i+1) % n] -= b[small_i%n];
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
