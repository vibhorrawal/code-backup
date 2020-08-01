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

// giving wrong answers
int countDistinctChar(string str){
  unordered_set<char> s;
  int start=0,size=0,smax=0;
  for (int i = 0; i < str.size(); i++) {
    if(s.find(str[i]) == s.end()){
      size++;
      s.insert(str[i]);
    }
    else{
      if(str[i]==str[start]) start++;
      else while(str[i] != str[start]){
        start++;
        s.erase(str[start]);
      }
      start++;
      s.erase(str[start]);
      size = i - start + 1;
      smax=max(smax,size);
      s.insert(str[i]);
    }
    if (DEBUG) {
      cout << "current: "<< str[i] << endl;
      cout<<"curr max: "; for(int j = start; j < size+start ; j++){ cout<<str[j]<<' ';}cout<<endl;
    }
  }
  return smax;
}

int longestUniqueSubstr(string s){
  std::vector<int> last_index(256,-1);
  int i=0,res=0;
  for (int j = 0; j < s.size(); j++) {
    i = max(i,last_index[s[j]]+1);
    res=max(res,j-i+1);
    last_index[s[j]] = j;
  }
  return res;
}
int main(int argc, char const *argv[]){
T(){
  string s;cin>>s;
  cout << longestUniqueSubstr(s) << endl;
  }
  return 0;
}
