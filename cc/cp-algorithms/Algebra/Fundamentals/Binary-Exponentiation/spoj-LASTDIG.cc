#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int binpow(int a, int b){
  int res = 1;
  while(b > 0){
    if(b & 1) res = (res * a) % 10;
    a = (a * a) % 10;
    b = b >> 1;
  }
  return res;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int a,b;
    cin>> a >> b;
    cout << binpow(a,b) << endl;
  }
  return 0;
}
