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

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int romanToInt(string s){
  int result=0;
  for (int i = 0; i < s.size(); i++) {
    int s1=value(s[i]);
    if(i+1<s.size()){
      int s2 = value(s[i+1]);
      if(s1>=s2) result += s1;
      else {
        result += s2-s1;
        i++;
      }
    }
    else result += s1;
  }
  return result;
}
int main(int argc, char const *argv[]){
T(){
  string s;
  cin>>s;
  cout << romanToInt(s) << endl;
  }
  return 0;
}
