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

int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    string s;
    cin>>n>>s;
    int count = 0;
    bool prev = false;
    for (int i = 0; i < n; i++) {
      if(s[i] == '1' && prev){
        count++;
      }
      else if(s[i] == '1') prev = true;
      else prev = false;
    }
    int count0 = 0;
    prev = false;
    for (int i = 0; i < n; i++) {
      if(s[i] == '0' && prev){
        count0++;
      }
      else if(s[i] == '0') prev = true;
      else prev = false;
    }
    // db(count0)
    cout << max(count, count0) << endl;
  }
  return 0;
}
