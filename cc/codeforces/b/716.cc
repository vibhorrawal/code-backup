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

bool check(int count[], string &s, int pos){
  int counter = 0;
  for (int i = 0; i < 26; i++) {
    if(s[i+pos] == '?') counter++;
    if(count[i+'A']) counter++;
  }
  return counter == 26;
}
void print_check(int pos, string s, int count[]){
  string rem = "";
  for (int i = 'A'; i <= 'Z'; i++) {
    if(count[i] == 0) rem += i;
  }
  assert(rem.size() < 27);
  int k = 0;
  for(int i = pos; i < pos + 26; i++){
    if(s[i] != '?') continue;
    s[i] = rem[k++];
  }
  // if(k != rem.size())
    // return;
  for (int i = 0; i < s.size(); i++) {
    if(s[i] == '?') s[i] = 'A';
  }
  cout << s << endl;
}
/*
int32_t main(int argc, char const *argv[]){
  fastIO;
  string s;
  cin>>s;
  if(s.size() < 26){
    cout << "-1" << endl;
    return 0;
  }
  int count[512] = {0};
  for (int i = 0; i < 512; i++) {
    count[i] = 0;
  }
  for(int i = 0; i < 26; i++){
    char c = s[i];
    count[c]++;
  }
  if(check(count, s, 0)) {
    print_check(0,s, count);
    return 0;
  }
  for(int i = 26, j = 0; i < s.size(); i++, j++){
    count[s[i]]++;
    count[s[j]]--;
    if(check(count, s, j)){
      print_check(j,s, count);
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
*/

int main(){
  string s;
  cin>>s;
  int counter = 0;
  if(s.size() < 26){
    cout << "-1" << endl;
    return 0;
  }
  int cnt[27] = {0};
  for(int i = 0; i < 26; i++) {
    if(s[i] == '?') {
      counter++;
      continue;
    }
    cnt[s[i] - 'A']++;
    if(cnt[s[i]-'A'] == 1) counter++;
  }
  for(int i = 26; i < s.size(); i++){

  }
}
