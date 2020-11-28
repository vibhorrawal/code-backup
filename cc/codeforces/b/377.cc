#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(b > a){
    swap(a,b);
    swap(c,d);
  }
  int num = b*c - a*d, den = c;
  db(num); db(den);
  
  int x = __gcd(num,den);
  cout << num/x <<'/'<<den/x << endl;
  return 0;
}
