#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
  int n;
  cin>>n;
  int a[n];
  REP(i,n) cin>>a[i];
  int ans=0,l,r;
  for (int i = 0; i < n; i++) {
    l=i-1;
    r=i+1;
    while(l>=0 && a[l] <= a[l+1]) l--;
    l++;
    while(r<n && a[r] <= a[r-1]) r++;
    r--;
    ans = max(ans, r-l+1);
  }
  cout << ans << endl;
}

/*
int32_t main(int argc, char const *argv[]){
  clr();
  int n;
  cin>>n;
  v1d v(n);
  REP(i,n) cin>>v[i];
  int lmax[n],rmax[n];
  int mx,it=0;
  mx=v[0];
  lmax[0]=0;
  for (int i = 1; i < n; i++) {
    if(mx <= v[i]){
      mx = v[i];
      it = i;
    }
    lmax[i] = it;
  }
  mx=v[n-1];
  rmax[n-1]=n-1;
  for (int i = n-2; i >=0; i--) {
    if(mx <= v[i]){
      mx = v[i];
      it = i;
    }
    rmax[i] = it;
  }
  int ans=0;
  for (int i = 0; i < n; i++) {
    db(i);db(lmax[i]);db(rmax[i]);db(0);
    ans = max(ans, rmax[i] - lmax[i] + 1);
  }
  cout << ans << endl;
  return 0;
}*/
