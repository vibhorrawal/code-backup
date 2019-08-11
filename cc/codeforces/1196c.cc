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

void solve(){
  int n;
  cin>>n;
  int arr[n][6];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      cin>>arr[i][j];
    }
  }
  int tempx=0,tempy=0;
  for (int i = 0; i < n; i++) {
    tempx += arr[i][0];
    tempy += arr[i][1];
  }
  tempx /= n;
  tempy /= n;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    flag = 1;
    if(tempx > arr[i][0]){
      if(!arr[i][4])
        flag = false;
    }
    else{
      if(!arr[i][2])
        flag = false;
    }
    //------
    if(tempx == arr[i][0]) flag = true;

    if(!flag){
      cout<<0<<endl;
      return;
    }
    //------
    if(tempy > arr[i][1]){
      if(!arr[i][5])
        flag = false;
    }
    else
    if(!arr[i][3])
      flag = false;

    if(tempy == arr[i][1]) flag = true;
    //------
      if(!flag){
        cout<<0<<endl;
        return;
      }
  }
  cout<<1<<' '<<tempx<<' '<<tempy<<endl;
}
int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
    solve();
  }
  return 0;
}
