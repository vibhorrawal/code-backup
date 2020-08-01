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

void stock(int a[], int n){
  int min=0, max=0;
  int i = 0;
  bool any_answer = false;
  while(i<n-1){
    while(i<n-1 && a[i] >= a[i+1]){
      i++;
    }
    min = i;
    if(i==n-1) break;
    i++;

    while(i<n && a[i] >= a[i-1]){
      i++;
    }
    max = i-1;
    cout<<"("<<min<<' '<<max<<") ";
    any_answer = true;
  }
  if(!any_answer) cout << "No Profit";
  cout << endl;
}
int main(int argc, char const *argv[]){
T(){
  int n;cin>>n;
  int a[n];
  REP(i,n) cin>>a[i];
  stock(a,n);
}
  return 0;
}
