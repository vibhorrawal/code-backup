//#pragma GCC optimize ("O3")
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
    // freopen("output.txt","w",stdout);
    // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    int xorval = 0;
    REP(i,n) {
      cin>>a[i];
      sum += a[i];
      xorval ^= a[i];
    }
    int val =  sum - 2 * xorval;

    int count = 0,v = abs(val);
    while(v){
      if(DEBUG){ cout << "v: "<<v << endl;}
      if(v & 1) count++;
      v=v>>1;
    }
    if(DEBUG){ cout << "count: "<<count << endl; }
    if(val == 0) {
      cout << "0\n" << endl;
      goto finish;
    }

    finish:
    ;
  }
  return 0;
}
