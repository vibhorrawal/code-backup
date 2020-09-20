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

int getSpecialSubstring(string s, int k, string charValue){
  set<char> normal;
  for(int i = 0; i < 26; i++){
    if(charValue[i] == '0')
      normal.insert(i + 'a');
  }

  int normal_count = 0, length = 0, max_length = 0;
  int i = 0, j = 0;
  while(j < s.size()){
    if(normal.find(s[j]) != normal.end())
      normal_count++;

    while(normal_count > k){
      if(normal.find(s[i]) != normal.end())
        normal_count--;
        i++;
    }
    max_length = max(j - i + 1, max_length);
    j++;
  }
  return max_length;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  string c = "10101111111111111111111111";
  string s = "abcde";
  cout << getSpecialSubstring(s,1,c) << endl;
  return 0;
}
