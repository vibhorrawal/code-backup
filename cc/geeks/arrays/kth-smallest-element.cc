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

int smallest(int a[], int n, int k){
  sort(a,a+n);
  return a[k-1];
}
int main(int argc, char const *argv[]){
  T(){
    int n,k;
    scanf("%d", &n);
    int a[n];
    REP(i,n) scanf("%d", &a[i]);
    scanf("%d", &k);

    printf("%d\n", smallest(a,n,k));
  }
  return 0;
}
