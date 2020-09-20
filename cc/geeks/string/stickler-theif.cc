#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int max_adj(int a[], int n){
  int incl = 0, excl = 0;
  for (int i = 0; i < n; i++) {
    int temp = incl;
    incl = max(incl, a[i] + excl);
    excl = max(excl, temp);
  }
  return max(incl, excl);
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin >> n;
    int a[n];
    REP(i,n) cin >> a[i];
    cout << max_adj(a,n) << endl;
  }
  return 0;
}
