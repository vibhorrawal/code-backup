#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  string s;
  cin>>s;
  reverse(s.begin(), s.end());
  string n = "4";
  int count = 1;
  while(n != s){
    int i = 0;
    while(i < n.size() && n[i] == '7') i++;
    if(i == n.size()){
      for (int i = 0; i < n.size(); i++) n[i] = '4';
      n += "4";
    }
    else {
      n[i] = '7';
      for (int j = i-1; j >= 0; j--) n[j] = '4';

      }
    // db(n);
    count++;
  }
  cout << count << endl;
  return 0;
}
