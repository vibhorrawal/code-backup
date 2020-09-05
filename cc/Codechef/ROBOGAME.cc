#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
string check(string s);

int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
    string s;
    cin>>s;
    cout<<check(s)<<endl;
  }
  return 0;
}

string check(string s){
  bool flag = false;
  for (int i = 0; i < s.length(); i++) {
    int j = i + 1;
    if(s[i] != '.'){
      while(s[j] == '.')
      j++;

      if(s[j] - '0' + s[i] - '0' >= j - i){
        flag = true;
        break;
      }

    }
  }

  if(flag == true){
    return "unsafe";
  }
  else
  return "safe";
}
