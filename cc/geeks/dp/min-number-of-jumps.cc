#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int jumps(v1d &a){

}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n; cin>>n;
    v1d a(n);
    REP(i,n) cin>>a[i];
    cout<<jumps(a)<<endl;
  }
  return 0;
}
