//#pragma GCC optimize ("O3")
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
#define pb(a) push_back(a)

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  // iinternaut();
  T(){
    string s;
    cin>>s;
    // auto it = s.find('0');
    if(s.find('0') == string::npos){
      REP(i,s.size()) cout<<1;
      // continue;
    }
    else if(s.find('1') ==string::npos) REP(i,s.size()) cout<<0;
    else{
      REP(i,s.size()) cout<<10;
    }
    cout<<endl;
    
  }
  return 0;
}
