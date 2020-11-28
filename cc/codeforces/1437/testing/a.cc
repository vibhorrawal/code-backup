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
  T(){
    int l,r;
    cin>>l>>r;
    int a = l - 1;
    int b = r + 1;
    if(a <= 2*l && r <= 2*a) cout << "YES" << endl;
    else if(b <= 2*l && r <= b) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
