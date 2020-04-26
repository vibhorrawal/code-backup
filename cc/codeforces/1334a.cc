#include<bits/stdc++.h>
using namespace std;

#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)

int main(int argc, char const *argv[]){
  T(){
    int n;
    cin>>n;
    int p[n],c[n];
    REP(i,n){
      cin>>p[i];
      cin>>c[i];
    }
    // if(DEBUG){ cout<<"p: "; for(int i = 0; i < n ; i++){ cout<<p[i]<<' ';}cout<<endl; };
    // if(DEBUG){ cout<<"c: "; for(int i = 0; i < n ; i++){ cout<<c[i]<<' ';}cout<<endl; };
    bool flag = 0;
    for (int i = 0; i < n-1; i++) {
      if(p[i] <= p[i+1] && c[i] <= c[i+1] && p[i] >= c[i] &&  p[i+1] >= c[i+1]){
        flag;
      }
      else{
        flag = 1;
      }

      if(c[i+1] > c[i]){
        if (p[i+1] > p[i]) flag;
        else flag = 1;
      }
    }
    if(n == 1){
      if(!(p[0] >= c[0])) flag = 1;
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES"<<endl;
  }
  return 0;
}
