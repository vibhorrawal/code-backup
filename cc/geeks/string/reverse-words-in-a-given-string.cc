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

void swap(string& s, int i, int j){
  char t;
  while(i<j){
    t = s[i];
    s[i]=s[j];
    s[j]=t;
    i++,j--;
  }
}
string reverse(string& s){
  int i=0,start=0,n=s.size();
  while(i<s.size()){
    if(s[i]=='.'){
      swap(s,start,i-1);
      start = i+1;
    }
    i++;
  }
  swap(s,start,s.size()-1);
  swap(s,0,s.size()-1);
  return s;
}
int main(int argc, char const *argv[]){
T(){
  string s;
  cin>>s;
  cout<<reverse(s)<<endl;
  }
  return 0;
}
