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

vector<int> computeLPS(string s){
    int m = s.size(), len = 0;
    vector<int> lps(m);
    lps[0] = 0;
    int i = 1;
    while(i < m){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}
void kmp(string txt, string pat, vector<bool> &toFill){
    int n = txt.size(), m = pat.size();
    vector<int> lps = computeLPS(pat);
    int i = 0, j = 0;
    while(i < n){
        if(pat[j] == txt[i])
            i++,j++;
        if(j == m){
          toFill[i-j] = true;
          j = lps[j-1];
        }
        if(i < n && pat[j] != txt[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
}
ll solve(){
  string s;
  cin>>s;
  vector<bool> kick(s.size()), start(s.size());
  kmp(s, "KICK", kick);
  kmp(s, "START", start);
  vector<int> countStart(s.size());

  countStart[s.size()-1] = start[s.size()-1];
  for(int i = start.size()-2; i >= 0; i--){
    countStart[i] = countStart[i+1] + start[i];
  }

  ll res = 0;
  for(int i = 0; i < s.size(); i++){
    if(kick[i]){
      res += countStart[i];
    }
  }
  return res;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i<<": "<<solve();
    cout<<endl;
  }
  return 0;
}
