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
  int a;
  int standing=INT_MAX;
  bool non_increasing=true, rank_same=true;
  REP(i,n){
    int t;
    cin>>t;
    a = t;
    if(standing>=t){
      standing = t;
    }
    else{
      non_increasing = false;
    }
    cin>>t;
    if(t == a){
      ;
    }
    else rank_same = false;
    // b[i] = t;
  }
  if(non_increasing && rank_same) cout << "maybe" << endl;
  else if(rank_same && !non_increasing) cout << "unrated" << endl;
  else cout << "rated" << endl;
  return 0;
}
