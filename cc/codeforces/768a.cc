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
  set<int> s;
  int min=INT_MAX,minc,max=INT_MIN,maxc=0;
  REP(i,n){
    int t;
    cin>>t;
    if(min>t){
      min = t;
      minc=1;
    }
    else if(min==t) minc++;
    if(max<t){
      max = t;
      maxc = 1;
    }
    else if(max==t) maxc++;
  }
  if(n<3) cout << "0" << endl;
  else cout << std::max(n-maxc-minc,0 )<< endl;
  return 0;
}
