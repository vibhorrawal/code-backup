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
  T(){
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    int count0 = 0;
    int i = 0;
    while(s[i] == '0') i++;
    int cost = i < s.size() ? a : 0;
    for (; i < s.size(); i++) {
      if(s[i] == '0'){
        count0++;
      }else{
        if(count0 * b > a){
          cost += a;
          count0 = 0;
        }
        else{
          cost += b * count0;
          count0 = 0;
        }
        while(s[i] == '1') i++;
        i--;
      }
    }
    cout << cost << endl;
  }
  return 0;
}
