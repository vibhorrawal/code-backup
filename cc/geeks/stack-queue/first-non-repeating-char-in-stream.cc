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

void print_non_repeating(vector<char> &v, int n){
  int freq[256] = {0};
  list<char> li;
  for(auto c: v){
    freq[c]++;
    if(freq[c] < 2)
      li.push_back(c);
    auto it = li.begin();
    while(freq[*it] > 1){
      li.erase(it);
      it = li.begin();
    }
    if(li.size())
      cout << *li.begin() << ' ';
    else
      cout << -1 << ' ';
  }
  cout << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin >> n;
    vector<char> v(n);
    REP(i, n) cin >> v[i];
    print_non_repeating(v,n);
  }
  return 0;
}
