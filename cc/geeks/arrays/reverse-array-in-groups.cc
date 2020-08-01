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

void reverse(int a[], int n, int k){
  for (int i = 0; i < n; i+=k) {
    int left = i;
    int right = min(i+k-1, n-1);
    while(left<right)swap(a[left++], a[right--]);
  }
  for(int i = 0; i < n ; i++){ cout<<a[i]<<' ';}cout<<endl;
}
int main(int argc, char const *argv[]){
  T(){
    int n,k;cin>>n>>k;
    int a[n];
    REP(i,n) cin>>a[i];
    reverse(a,n,k);
  }
  return 0;
}
