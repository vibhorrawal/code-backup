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
  if((n/2)%2 ){
    cout<<"NO"<<endl;
    continue;
  }
  else{
    cout<<"YES"<<endl;
    for (int i = 1; i <= n/2; i++) {
      cout<<2*i<<' ';
    }
    for (int i = 0; i < n/2-1; i++) {
      cout<<2*i+1<<' ';
    }
    cout<<n/2+n-1;
    cout<<endl;
  }
  /*
  // n = n/2;
  int pow = 1, num = 2;
  bool flag = 0;
  if(n==2){
    flag=1;
  }else
  while(1){
    if(num == n) break;
    pow++;
    num = num<<1;
    if(num > 200000+1){
      flag = 1;
      break;
    }
  }

  if(flag) cout<<"NO"<<endl;
  else{
    cout<<"YES"<<endl;
    for (int i = 1; i <= n/2; i++) {
      cout<<2*i<<' ';
    }
    for (int i = 0; i <= n/2-1; i+=2) {
      cout << i+1 << ' ';
    }cout<<n/2+n-1<<endl;
  }
  */
}
  return 0;
}
