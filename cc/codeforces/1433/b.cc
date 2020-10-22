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
    int n;
    cin>>n;
    vi v(n);
    REP(i,n) cin>>v[i];
    int i = 0, right = 0, left = 0;
    int count = 0;
    while(v[i] == 0) i++;
    int j = n-1;
    while(v[j] == 0) j--;
    int leftBound = i, rightBound = j;
    for(int i = leftBound; i < rightBound; i++) if(v[i] == 0) count++;
    // i = n-1;
    // while(v[i] == 0) i--;
    // for(; i >= 0; i--) if(v[i] == 0) left++;
    cout << count << endl;
  }
  return 0;
}
