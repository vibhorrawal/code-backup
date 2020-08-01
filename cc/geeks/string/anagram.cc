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

void anagram(string a, string b){
  if(a.size() != b.size()){
    cout << "NO" << endl;
    return;
  }
  std::map<char, int> map1;
  std::map<char, int> map2;
  for (int i = 0; i < a.size(); i++) {
    map1[a[i]]++;
  }
  for (int i = 0; i < b.size(); i++) {
    map2[b[i]]++;
  }
  for (int i = 0; i < a.size(); i++) {
    if(map1[a[i]] != map2[a[i]]){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main(int argc, char const *argv[]){
T(){
  string a,b;
  cin>>a>>b;
  anagram(a,b);
  }
  return 0;
}
