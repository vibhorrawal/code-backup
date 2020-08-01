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

void count_sort(int a[], int n){
  int count0 = 0, count1 = 0, count2 = 0;
  REP(i,n) {
    if(a[i] == 0) count0++;
    if(a[i] == 1) count1++;
    if(a[i] == 2) count2++;
  }
  int i=0;
  while(count0--) a[i++] = 0;
  while(count1--) a[i++] = 1;
  while(count2--) a[i++] = 2;
  REP(i,n) cout<< a[i] << ' ';
  cout << endl;
}
int main(int argc, char const *argv[]){
  T(){
    int n;cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    count_sort(a,n);
  }
  return 0;
}
