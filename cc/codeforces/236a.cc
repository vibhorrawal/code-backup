//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb emplace_back
#define db(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'
#define CHAR 256
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  string y = "CHAT WITH HER!", n = "IGNORE HIM!";
  bool present[CHAR] = {0};
  string inp;
  cin>>inp;
  for(char i: inp) present[i] = true;
  int count=0;
  REP(i,CHAR) if(present[i]) count++;
  if(count%2) cout << n << endl;
  else cout << y << endl;
  return 0;
}
