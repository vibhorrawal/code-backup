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


struct Trie {
struct Trie *child[2];
Trie(){
    child[0] = NULL;
    child[1] = NULL;
}
};

void insert(Trie *root, int a){
for(int i = 31; i >= 0; i--){
    int ind = (a >> i) & 1;
    // db(ind);
    if(!root->child[ind])
        root->child[ind] = new Trie();
    root = root->child[ind];
}
// cout << "---------------------------------------------" << endl;
}

int find(Trie *root, int q){
int res = 0;
for(int i = 31; i >= 0; i--){
    int ind = (q >> i) & 1;
    db(ind);
    if(root->child[!ind]) {
      cout << "ind--------------" << endl;
        res = res | (1 << i);
        root = root->child[!ind];
    }
    else if(root->child[ind]){
      cout << "ind" << endl;
        root = root->child[ind];
    }
    else{
        assert(false);
    }
}
return res;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n = 1;
  int q = 31;
  Trie *root = new Trie();
  for(int i : {3,10,5,25,2,8})
    insert(root,i);
  cout<<find(root,5);
  // for(int i = 0; i < 32; i++){
  //     int ind = (q >> i) & 1;
  //     cout<<(ind | 32)<<' ';
  //   }
  return 0;
}
