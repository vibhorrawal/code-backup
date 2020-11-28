#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

string multiply(string &a, string &b){
  if(sz(b) > sz(a)) swap(a,b);
  string res = string(5000, '0');
  reverse(all(a));
  reverse(all(b));
  for (int i = 0; i < sz(b); i++) {
    int n = b[i] - '0', c = 0, s = 0;
    for (int j = 0; j < sz(a); j++) {
      s = (n * (a[j] - '0')) + c + (res[i+j] - '0');
      c = s / 10;
      s %= 10;
      res[i + j] = s + '0';
      db(res.substr(0,20));
    }
    // int k = sz(a);
    // while(c){
    //   int t = res[i+k] - '0';
    //   s = c + t;
    //   c = s / 10;
    //   res[i+k++] = s + '0';
    // }
    if(c) res[i+sz(a)] += c ;
  }
  reverse(all(res));
  int i = 0;
  while(res[i] == '0') i++;
  res.erase(0,i);
  if(res == "") res = "0";
  return res;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  string a,b;
  while(cin>>a>>b){
    cout << multiply(a,b) << endl;
  }
  return 0;
}
