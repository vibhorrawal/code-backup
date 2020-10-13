//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]\n";
#define endl '\n'

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int DEBUG = 0;
int32_t main(int argc, char const *argv[]){
  // if(argc > 2) DEBUG = 1;
  iinternaut();
  int k,r;
  cin>>k>>r;
  // k = k%10;
  int m=0,t=9, k2=k,c=0;
  while(t--){
    c++;
    m = k2 / 10;
    db(9-t);db(k2);db(m);

    if((k2 -r) % 10 == 0 || k2 % 10 == 0) {
      cout << c << endl;
      exit(0);
    }
    k2 += k;

  }
  cout << 10 << endl;
  return 0;
}
