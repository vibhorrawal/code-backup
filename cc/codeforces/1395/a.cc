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
#define DEBUG true
#define pb emplace_back
#define db(x) cout<<#x<<": "<<x<<endl;

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
    int r,b,g,w;
    cin>>r>>b>>g>>w;
    ll sum=r%2 + g%2 + b%2 + w%2;

    int minc = min({r,b,g});
    r -= minc;
    b -= minc;
    g -= minc;
    r %=2;
    b %=2;
    g %=2;
    if(sum%2==0){
      if(!r%2 && !b%2 && !g%2) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    else{
      if((r && !g && !b) || (g && !r && !b) || (b && !r && !g) || (!r && !b && !g)) cout << "Yes" << endl;
      else cout << "No" << endl;


    }
  }
  return 0;
}
