#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG false
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
set < string , greater <string> > strSet;
int wowFactor(string s);
void subsequence(string s);
string change(string s);
int32_t main(int argc, char const *argv[]){
  string s1;
  cin>>s1;
  cout<<wowFactor(s1);
  return 0;
}
string change(string s){
  string output;
  bool lastv = false;
  int count = 0;
  int n = s.length();

  REP(i,n){
    if(DEBUG){ cout<<"i: "<<i<<endl; };
    if(s[i] == 'v'){
      if(DEBUG){ cout<<"current is v"<<endl; };
      count++;

      lastv = true;
    }
    else
    {
      if(DEBUG){ cout << "current is not v" << endl; };
      if(lastv){
        if(DEBUG){ cout << "last was v" << endl; };
          REP(j,count-1){
            output += 'w';
          }
          count = 0;
          output += s[i];
      }
      else // last was not v
        {
          output += s[i];
          cout << "last was not v" << endl;
        }
      lastv = false;
    }

    // last element
    if(i == n-1){
      REP(j,count-1){
        output += 'w';
      }
    }
  }
  return output;
}
void subsequence(string s){
  for (int i = 0; i < s.length(); i++) {

    for (int j = s.length(); j > i; j--) {
      string substr = s.substr(i,j);

      if(substr == "wow"){
        strSet.insert( to_string(i) + to_string(j) );
        // cout<<"haha\n";
        }
      for(int k = 1; k < substr.length(); k++){
        string newstr = substr;
        newstr.erase(newstr.begin() + k);
        subsequence(newstr);
      }
    }
  }
}
int wowFactor(string s){
  string output = change(s);
  subsequence(output);
  int count = 0;
  FOR(i,strSet)
    count++;
  return count;
}
