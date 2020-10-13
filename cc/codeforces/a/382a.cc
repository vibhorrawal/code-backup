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

int32_t main(int argc, char const *argv[]){
  clr();
  string s;
  cin>>s;
  int del;
  for(int i=0;i<s.size();i++){
    if(s[i] == '|') del = i;
  }
  int r = s.size() - del-1;
  int l = del;
  string n;
  cin>>n;
  int len = l + r + n.size();
  if(len % 2 == 0 && (l <=len/2 && r<= len/2)) {
    cout << s.substr(0,l);
    int i = len/2 - l;
    cout <<  n.substr(0,i);
    cout<<'|';
    cout<<s.substr(l+1);
    cout<<n.substr(i);
  }
  else cout << "Impossible" << endl;
  return 0;
}
