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
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
  string s;
  cin>>s;
  if(s == "0") {
    cout << "0" << endl;
    exit(0);
  }
  int ans = s.size()-1;
  int i=1;
  while(i < s.size() && s[i] == '0') i++;
  if(i != s.size()) ans++;
  cout <<  ceil(ans/2.0) << endl;
  return 0;
}
/*
int32_t main(int argc, char const *argv[]){
  clr();
  string s;
  cin>>s;
  db(std::bitset<64>(s).to_ullong());
  db(s.size());
  int ans = s.size() /2;
  db(ans);
  int i=1;
  while(i < s.size() && s[i] == '0') i++;
  if(i != s.size()) ans++;
  cout <<  ans << endl;
  return 0;
}
*/
