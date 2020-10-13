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
  T(){
    int n,a,s;
    cin>>n>>a>>s;
    // int count = 0, m = 1;
    bool flag = 0;
    while(n > (n>>1) + 10){
      if(a){
        n = (n>>1) + 10;
        a--;
        // cout<<"a: "<<a<<' '<<n<<endl;
      }
      else break;
    }
    while(n>0){
      if(s){
        n = n - 10;
        s--;
        // cout<<"s: "<<s<<' '<<n<<endl;

      }
      else{
        flag = 1;
        break;
      }
    }
    if(!flag) cout<<"YES\n";
    else cout<<"NO\n";
    /*while(n > m ){
      m = m<<1;
      count++;
    }
    if(n == 1) count = 1;
    // cout<<count<<endl;
    if(count <= a && count <= s) cout<<"YES\n";
    else if(count < a && s) cout<<"YES\n";
    else cout<<"NO\n";
    */
  }
  return 0;
}
