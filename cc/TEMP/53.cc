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

int check1(string s){
  int ans = 0;
  while(s.size() > 2){
    ans++;
    string t;
    int i = 0;
    while(i < sz(s)){
      if(i+1 < sz(s) && s[i] == '0' && s[i+1] == '1'){
        i += 2;
      }
      else t += s[i++];
    }
    if(s == t){
      ans += s.size();
      break;
    }
    s = t;
  }
  return ans + !s.empty();
}

int check2(string s){
  int ans = 0;
  while(s.size() > 2){
    ans++;
    string t;
    int i = 0;
    while(i < sz(s)){
      if(i+1 < sz(s) && s[i] == '1' && s[i+1] == '0'){
        i += 2;
      }
      else t += s[i++];
    }
    if(s == t){
      ans += s.size();
      break;
    }
    s = t;
  }
  return ans + !s.empty();
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    string s;
    int n;
    cin >> n;
    cin>> s;
    cout<<min(check1(s), check2(s))<<endl;
  }
  return 0;
}
