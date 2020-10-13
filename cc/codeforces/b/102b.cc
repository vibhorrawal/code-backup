#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int sum(int n){
  int res = 0;
  while(n){
    res += n % 10;
    n /= 10;
  }
  return res;
}
int sumtimes(string s){
  if(s.size() == 1)
    return 0;
    int num = 0, count = 0;
    for (int i = 0; i < s.size(); i++) {
      num += s[i] - '0';
    }
    while(num/10){
      num = sum(num);
      count++;
    }
    return count+1;
}
int32_t main(int argc, char const *argv[]){
  clr();
  string s;
  cin>>s;
  cout<<sumtimes(s)<<endl;
  return 0;
}
