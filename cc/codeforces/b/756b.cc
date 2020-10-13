#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

void decode(){
  int n; string s;
  cin>>n>>s;
  string res;
  int i = n%2?0:1, j = n-2;
  while(j >= 0){
    res += s[j--];
    j--;
  }
  while(i < n){
    res += s[i++];
    i++;
  }
  cout << res << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  decode();
  return 0;
}
