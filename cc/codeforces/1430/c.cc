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

string res;
int solve(int n){
  set<int> odd,even;
  for (int i = 1; i <= n; i++) {
    if(i & 1) odd.insert(i);
    else even.insert(i);
  }
  while(1){
    while(even.size() > 1){
      auto ita = even.end();
      int a = *(--ita), b = *(--ita);
      int temp = a + b;
      res += to_string(a);
      res += ' ';
      res += to_string(b);
      res += '\n';
      temp /= 2;
      auto it = even.end();
      even.erase(--it);
      it = even.end();
      even.erase(--it);

      if(temp & 1)
        odd.insert(temp);
      else
        even.insert(temp);
    }

    while(odd.size() > 1){
      auto ita = odd.end();
      int a = *(--ita), b = *(--ita);
      db(a);db(b);
      int temp = a + b;
      res += to_string(a);
      res += ' ';
      res += to_string(b);
      res += '\n';
      temp /= 2;
      auto it = odd.end();
      odd.erase(--it);
      it = odd.end();
      odd.erase(--it);
      if(temp & 1)
        odd.insert(temp);
      else
        even.insert(temp);
    }
    if(odd.size() < 2 && even.size() < 2) break;
  }
  if(odd.size() && even.size()){
    res += to_string(*odd.begin());
    res += ' ';
    res += to_string(*even.begin());
    res += '\n';
    return (*odd.begin() + *even.begin() + 1) / 2;
  }
  if(odd.size()) return *odd.begin();
  if(even.size()) return *even.begin();
  return -1;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin>> n;
    res = "";
    cout << solve(n) << endl;
    cout << res;
  }
  return 0;
}
