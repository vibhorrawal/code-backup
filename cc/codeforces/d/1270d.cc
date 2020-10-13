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
  iinternaut();
    int n,k,a=0,b=0,ap,bp;
    cin>>n>>k;
    bool flag = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= k+1; j++) {
        cout<<"? ";
        for (int ii = 1; ii <= k+1; ii++) {
          if(j == ii) continue;
          cout<<n+ii<<" ";
        }
        cout<<endl;
        cout.flush();
        cin>>a>>b;
        // cout<<"A: "<<a<<" b: "<<b<<endl;
        if(flag && ap != a && bp != b){
          cout<<"! "<<n+j-1<<endl;
          exit(0);
        }
        flag = 1;
        ap = a;
        bp = b;
      }
    }

  return 0;
}
