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
#define DEBUG 0
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
  int i=0;
  bool start=true;
  while(i < s.size()){
    db(i);
    if(i +2< (s.size()) && s[i]=='W' && s[i+1] == 'U' && s[i+2] == 'B'){
      i += 3;
      if(!start) cout << ' ';
      start = true;
    }
    else {
      start=false;
      cout << s[i];
      i++;
    }
  }
  return 0;
}
