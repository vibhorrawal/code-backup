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

void testcase(){
  int n, x;
  cin >> n >> x;
  vector<pair<int,int>> arr(n);
  for(int i = 1; i <= n; i++){
    int t;
    cin >> t;
    arr[i-1] = {t/x,i};
  }
  sort(arr.begin(), arr.end(), [](pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
      return a.second < b.second;
    return a.first < b.first;
  });
  for(int i = 0; i < n ; i++){ cout<<arr[i].second<<' ';}
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tt;
  cin>>tt;
  for(int i = 1; i <= tt; i++){
    cout<<"Case #"<<i<<": ";
    testcase();
    cout<<endl;
  }
  return 0;
}
