#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl 'n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int N;
set < string > strSet;
void solve(string s);
void subsequence(string s);
bool palindrome(string s);

int32_t main(int argc, char const *argv[]){
  iinternaut();
  string s;
  cin>>s;
  N = s.length();
  // cout<<palindrome(s);
  solve(s);
  return 0;
}
void solve(string s){
  subsequence(s);
  FOR(i,strSet){
    if(palindrome(*i)){
      cout<<*i;
      exit(0);
    }
  }
  cout<<"IMPOSSIBLE";
}
bool palindrome(string s){
  int i = 0, j = s.length()-1;
  while (i<=j) {
    if(s[i] != s[j])
    return false;
    i++, j--;
  }
  return true;
}
void subsequence(string s){
  for (int i = 0; i < s.length(); i++) {

    for (size_t j = s.length(); j > i; j--) {
      string substr = s.substr(i,j);

      if(substr.length() < N/2)
        return;

      strSet.insert(substr);

      for(int k = 1; k < substr.length(); k++){
        string newstr = substr;
        newstr.erase(newstr.begin() + k);
        subsequence(newstr);
      }
    }
  }
}
