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

bool calculate(int a[], int n){
  set<int> s;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      s.insert(a[i]*a[i] + a[j]*a[j]);
    }
  }
  REP(i,n){
    if(s.find(a[i]*a[i]) != s.end()) return true;
  }
  return false;
}

bool meet_in_the_middle(int a[], int n){
  if(n<3) return false;
  sort(a,a+n);
  REP(i,n) a[i] = a[i] * a[i];
  int low,high;
  for (int i = 2; i < n; i++) {
    low = 0, high = i-1;
    while(low<high){
      if(a[i] == a[low] + a[high]) return true;
      if(a[i] > a[low] + a[high]) low++;
      else high--;
    }
  }
  return false;
}
int main(int argc, char const *argv[]){
  T(){
    int n;cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    cout<<(meet_in_the_middle(a,n)?"Yes":"No")<<endl;
  }
  return 0;
}
