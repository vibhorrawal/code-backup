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

void zigzag(int a[], int n){
  bool flag = 0;
  for (int i = 0; i < n-1; i++) {
    if(a[i] < a[i+1]){
      if(flag) swap(a[i], a[i+1]);
    }
    else{
      if(!flag) swap(a[i], a[i+1]);
    }
    flag = !flag;
  }
  for(int i = 0; i < n ; i++){ cout<<a[i]<<' ';}cout<<endl;
}
int main(int argc, char const *argv[]){
T(){
  int n;cin>>n;
  int a[n];
  REP(i,n) cin>>a[i];
  zigzag(a,n);
}
  return 0;
}
