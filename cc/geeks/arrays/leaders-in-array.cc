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

void leaders(int a[], int n){
  int rightmax[n];
  int max_so_far = a[n-1];
  for (int i =n-1; i >=0; i--) {
    max_so_far = max(max_so_far, a[i]);
    rightmax[i] = max_so_far;
  }
  REP(i,n){
    if(a[i] == rightmax[i]) cout << a[i]<<" " ;
  }
  cout<< endl;
}
int main(int argc, char const *argv[]){
  T(){
    int n;cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    leaders(a,n);
  }
  return 0;
}
