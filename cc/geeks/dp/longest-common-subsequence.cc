#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

int longest_common_subsequence(string s1, string s2){
  int m = s1.size(), n= s2.size();
  int lcs[m+1][n+1];
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if(!i || !j)
        lcs[i][j] = 0;
      else if(s1[i-1] == s2[j-1])
        lcs[i][j] = lcs[i-1][j-1]+1;
      else
        lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
      ans = max(ans,lcs[i][j]);
    }
  }
  return lcs[m][n];
}

int main(int argc, char const *argv[]){
T(){
  int n;cin>>n>>n;
  string s1,s2;
  cin>>s1>>s2;
  cout << longest_common_subsequence(s1,s2) << endl;
  }
  return 0;
}
