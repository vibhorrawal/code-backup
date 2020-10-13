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
const ll M = 1e9 + 7;
ll sum(ll a, ll b){
  ll ans = a % M;
  b = b % M;
  ans = ans + b;
  return ans % M;
}

struct trie {
  struct trie *child[10];
  bool isEnd;
  trie(){
    for (int i = 0; i < 10; i++) {
      child[i] = NULL;
    }
    isEnd = false;
  }
};

void insert(trie *root, string &s, int pos){
  trie *crawl = root;
  for(int i = 0; i <= pos; i++){
    int ind = s[i] - '0';
    if(!crawl->child[ind])
      crawl->child[ind] = new trie();
    crawl = crawl->child[ind];
  }
  crawl->isEnd = true;
}
void suffix(trie *root, string &s){
  for(int i = 1; i < s.size(); i++){
    insert(root, s, i);
  }
}
void calculate(trie *root, ll &res){
  trie *crawl = root;
  for(int i = 0; i < 10; ++i){
    if(crawl->child[i]){
      res = sum(0, sum(res, i));
      calculate(crawl->child[i], res);
    }
  }
}
void sum(string &s, int i, int j, ll &res){
  ll ans = 0;
  for (int k = 0; k < i; k++) {
    ans = (ans*10 + s[k] - '0') % M;
  }
  // res = (res + ans) % M;
  // ans = 0;
  for (int k = j; k < s.size(); k++) {
    ans = (ans*10 + s[k] - '0') % M;
  }
  res = (res + ans) % M;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  string s;
  cin>>s;
  // trie *root = new trie();
  // suffix(root, s);
  // calculate(root, res);
  ll res = 0;
  for(int i = 0; i < s.size(); i++){
    for(int j = i+1; j <= s.size(); j++){
      sum(s, i, j, res);
    }
  }
  cout<<res<<endl;
  return 0;
}
