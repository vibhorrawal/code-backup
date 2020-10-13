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

void print(string &res){
  cout<<res.size()<<' ';
  if(res.size() > 10){
    cout<<res[0]<<res[1]<<res[2]<<res[3]<<res[4]<<"..."<<res[res.size()-2]<<res[res.size()-1]<<endl;
  }
  else{
    cout<<res<<endl;
  }
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  string s;
  cin>>s;
  vi incl(s.size()+1,0);
  int k = 1;
  for(int i = s.size()-2; i >= 0; i-= 2){
    if(s[i] == s[i+1]){
      incl[i] = incl[i+1] = k++;
    }
  }
  for(int i = 0; i < s.size(); i++){
    string res;
    for(int j = i; j < s.size(); j++){
      if(incl[j] && incl[j] == incl[j+1]){
        j++;
        continue;
      }
      res += s[j];
    }
    print(res);
  }
  return 0;
}
