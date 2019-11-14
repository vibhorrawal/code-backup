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

int32_t main(int argc, char const *argv[]){
  iinternaut();
  string s;
  cin>>s;
  int l = s.length();
  if(l==1){
    cout<<0;
    return 0;
  }
  if(l<3){
    cout<<1;
    return 0;
  }
  int flag = 0,i = s.length()-1;
  while(i>=1){
    if(s[i] == '1') flag = 1;
    i-=1;
  }
  if(s.length()%2 == 0)
    flag = 0;
    // cout<<"s: "<<s.length()<<endl;
  cout<<l/2+flag;
  return 0;
}
