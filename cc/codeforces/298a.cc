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
  int n;
  cin>>n;
  string s;
  cin>>s;
  int i=0;
  while(s[i]=='.') i++;
  if(s[i] == 'R'){
    int j=i;
    // cout << i+1 << ' ';
    while(s[i] == 'R') i++;
    if(s[i] == '.') cout << i<<' '<<i+ 1<< endl;
    else cout << j+1<<' '<<i<< endl;
  }
  else{
    int j = i;
    i=n-1;
    while(s[i] == '.') i--;
    cout << i+1 << ' '<<j << endl;
  }
  return 0;
}
