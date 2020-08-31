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

void editorial(){
  int n;
  cin>>n;
  string s1,s2;
  int c1=0,c2=0;
  REP(i,n){
    string t;
    cin>>t;
    if(c2>c1){
      swap(c1,c2);
      swap(s1,s2);
    }
    if(s1 == t){
      c1++;
    }
    else if(s2 == t){
      c2++;
    }
    else{
      s2 = t;
      c2=1;
    }
  }
  if(c2>c1){
    swap(c1,c2);
    swap(s1,s2);
  }
  cout << s1 << endl;
  exit(0);
}
int32_t main(int argc, char const *argv[]){
  clr();
  editorial();
  int n;
  cin>>n;
  unordered_map<string,int> frq;
  REP(i,n){
    string t;
    cin>>t;
    frq[t]++;
  }
  int max=0;
  string ans;
  FOR(it,frq){
    if(it-> second > max){
      ans = it->first;
      max = it-> second;
    }
  }
  cout << ans << endl;
  return 0;
}
