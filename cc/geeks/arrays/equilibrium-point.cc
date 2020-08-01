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

int point(int a[], int n){
  int left[n], right[n];
  int count = 0;
  REP(i,n){
    count += a[i];
    left[i] = count;
  }
  count = 0;
  for (int i=n-1; i >= 0 ; i--) {
    count += a[i];
    right[i] = count;
  }
  REP(i,n){
    if(left[i] == right[i]) return i+1;
  }
  return -1;
}
int main(int argc, char const *argv[]){
  T(){
    int n;cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    cout << point(a,n)<<endl;
  }
  return 0;
}
