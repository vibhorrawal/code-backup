#pragma GCC optimize ("O3")
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
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
    int n;
    cin>>n;
    int min = INT_MAX;
    int num;
    int mod = 1,div;
    if(n<10){
       cout<<n<<endl;
       continue;
     }
    for (int i = 0; i <= log10(n); i++) {
      num = 0;
      div = mod * 10;

      num = (n/div) * mod + n % mod;
      mod *= 10;

      if(num<min) min = num;
    }
    // for (int i = 0; i < log10(n); i++) {
    //   num = 0;
    //   num +=
    // }
    cout<<min<<endl;
  }
  return 0;
}
