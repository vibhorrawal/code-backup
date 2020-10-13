#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int total;
int dfs(int pos, int neg, int confuse){
  total++;
  if(confuse == 0) return (pos || neg) ? 0 : 1;
  if(pos == 0 && neg == 0){
    return 0;
  }
  int count = 0;
  if(pos) count += dfs(pos-1,neg,confuse-1);
  if(neg) count += dfs(pos, neg-1, confuse-1);
  return count;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int pos = 0, confuse = 0, neg = 0;
  string s;
  cout<<fixed << showpoint << setprecision(9);
  cin>>s;
  for(char c : s){
    if(c == '+') pos++;
    if(c == '-') neg++;
  }
  cin>>s;
  for(char c : s){
    if(c == '+') pos--;
    if(c == '-') neg--;
    if(c == '?') confuse++;
  }
  double ans = 1;
  if(confuse < abs(pos + neg)){
    cout << ans << endl;
    return 0;
  }
  if(confuse == 0){
    cout<<(pos || neg ? (double) 0 : ans);
    return 0;
  }
  int final = pos + neg;
  total = -1;
  int count = dfs(pos,neg,confuse);
  db(count);
  db(total);
  // ans = pow(0.5, count);
  ans = (double) count / total;
  if(count == 0){
    cout<<(double) 0<< endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
