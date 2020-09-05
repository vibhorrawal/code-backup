#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll min_product(int a, int b, int x, int y, int n){
  // if(y < x){
  //   swap(a,b);
  //   swap(x,y);
  // }
  int n_a = min(a - x, n);
  a -= n_a;
  b -= min(n - n_a, b - y);
  ll ans = a;

  return ans * b;
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    cout << min(min_product(a,b,x,y,n), min_product(b,a,y,x,n)) << endl;
  }
  return 0;
}
