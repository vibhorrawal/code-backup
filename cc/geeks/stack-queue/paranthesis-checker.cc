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

bool check(string s){
  stack<char> st;

  for(auto c: s){
    if(c == '{' || c == '[' || c == '(')
      st.push(c);
    else{
      if(st.size() == 0)
        return false;
      char f = st.top();
      if((c == '}' && f != '{') ||
         (c == ')' && f != '(') ||
         (c == ']' && f != '['))
        return false;
      st.pop();
    }
  }
  return st.size() == 0;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    string s;
    cin >> s;
    cout << (check(s) ? "balanced" : "not balanced") << endl;
  }
  return 0;
}
