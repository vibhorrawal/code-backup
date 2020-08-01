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

string removeDuplicates(string s){
  string output="";
  unordered_set<char> ss;
  for (int i = 0; i < s.size(); i++) {
    if(ss.find(s[i]) == ss.end()){
      output += s[i];
      ss.insert(s[i]);
    }
  }
  ss.clear();
  return output;
}
int main(int argc, char const *argv[]){
T(){
  string s;
  getline(cin,s); if(s=="") getline(cin,s);
  cout << removeDuplicates(s) << endl;
  }
  return 0;
}
