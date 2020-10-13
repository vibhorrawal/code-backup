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

vi calc_lps(string pat){
  int m = pat.size();
  int j = 0, len = 0;
  vi lps(m,0);
  lps[j] = 0;
  j++;
  while(j < pat.size()){
    if(pat[j] == pat[len]){
      len++;
      lps[j] = len;
      j++;
    }
    else{
      if(len)
        len = lps[len-1];
      else
        lps[j++] = 0;
    }
  }
  return lps;
}
ll kmp_count(string txt, string pat){
  vector<int> lps = calc_lps(pat);
  ll count = 0;
  set<pair<int,int>> st;
  int i = 0, j = 0;
  while(i < txt.size()){
    if(txt[i] == pat[j]){
      i++,j++;
      if(j == pat.size()){
        count += (i-j+1) * (txt.size()-i+1);
        for (int ii = i-j; ii >= 0; ii--) {
          for (int jj = i; jj <= txt.size(); jj++) {
            if(st.count({ii,jj})) break;
            st.insert({ii,jj});
          }
        }
        j = lps[j-1];
      }
    }
    else{
      if(j) j = lps[j-1];
      else i++;
    }
  }
  return st.size();
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  string s;
  cin>>s;
  // cout<<kmp_count(s,"bear")<<endl;
  ll count = 0;
  for (int l = 0; l < s.size(); l++) {
    for (int r = l+3; r < s.size(); r++) {
      if(s[r] == 'r' && s[r-1] == 'a' && s[r-2] == 'e' && s[r-3] == 'b'){
        count += s.size() - r;
        break;
      }
    }
  }
  cout << count << endl;
  return 0;
}
