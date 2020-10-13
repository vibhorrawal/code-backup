#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int n;
  cin>>n;
  vi v(n);
  REP(i,n) cin>>v[i];
  sort(all(v));
  int start = 0;
  int len = n;
  for (int i = 1; i < n; i++) {
    while(start < i && v[start] * 2 < v[i]) start++;
    len = min(n - (i - start + 1), len);
  }
  cout << len << endl;
  return 0;
}
