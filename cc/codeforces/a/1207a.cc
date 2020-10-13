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
    int b,p,f,h,c;
    cin>>b>>p>>f>>h>>c;
    int sum = 0;
    b = b/2;

    if(h>c){
      while(b>0 && p>0){
        sum += h;
        b--;
        p--;
      }
      while(b>0 && f>0){
        sum += c;
        b--;
        f--;
      }
    }
    else{
      while(b>0 && f>0){
        sum += c;
        b--;
        f--;
      }
      while(b>0 && p>0){
        sum += h;
        b--;
        p--;
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}
