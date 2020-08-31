#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void print(int a[], int n){
  for (int i = 0; i < n; i++) {
    cout << a[i];
  }
  cout<<endl;
}
// better approach would be to cout<<t and then remaining digits fill with 0
// except 1 10 input, where ans is -1
int32_t main(int argc, char const *argv[]){
  clr();
  int n,t;
  cin>>n>>t;
  int a[n] ={0};
  a[0]=1;
  if(n==1){
    if(t != 10) cout << t << endl;
    else cout << "-1" << endl;
  }
  else {
    if(t==2||t==5||t==10||t==4||t==8){
      a[0]=8;
      print(a,n);
    }
    else if(t==3||t==9||t==6){
      a[n-1]=8;
      // a[n-2]=1;

      print(a,n);
    }
    else if(t==7){
      if(n==2) cout << "70" << endl;
      else{
        a[0] = 7;
        print(a,n);
      }
    }
  }
  return 0;
}
