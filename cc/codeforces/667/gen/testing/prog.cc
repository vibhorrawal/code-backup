#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int sum(string n){
  int ans = 0;
  for (int i = 0; i < n.size(); i++) {
    ans += n[i] - '0';
  }
  return ans;
}

void decrease(string &n, string &res, int pos){
  if(n[pos] == '0'){
    res += '0';
  }
  else{
    char c = n[pos];
    n[pos] = '0';
    res += char(10 - (c - '0') + '0');
    if(pos) n[pos-1]++;
  }
}

string moves(string n, int s){
  string res = "";

  for(int i = n.size()-1; i >=0 ; i--){
    if(sum(n) > s)
      decrease(n,res,i);
    db(n);
    db(res);
  }
  reverse(all(res));
  int i = 0;
  while(res[i] == '0') i++;
  db(res);
  return res.size() == 0 ? "0": res.substr(i);
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    string n;
    int s;
    cin >> n >> s;
    cout << moves(n, s) << endl;
  }
  return 0;
}
