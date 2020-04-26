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


int32_t main(int argc, char const *argv[]){
  T(){
    int n;
    cin>>n;
    int val = 2;
    int k = 1,x=0;
    while(1){
      k++;
      val = val<<1;
      x = n / (val-1);
      // cout<<"test: "<<n<<r<<(val-1)<<endl;
      if(x * (val-1) == n) break;
    }
    cout<<x<<endl;
  }
  return 0;
}
