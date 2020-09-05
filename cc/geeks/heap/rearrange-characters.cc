#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define sz(x) (int) x.size()

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool check_no_adjacent(string s){
  priority_queue<pair<int, char>> pq;
  int freq[256] = {0};
  for(auto c: s) freq[c]++;
  REP(i,256) if(freq[i]) pq.push({freq[i], i});
  string res = "";
  pair<int, char> prev = {0, '#'};
  while(pq.size() != 0){
    auto t = pq.top();
    res += (char) t.second;
    pq.pop();
    if(prev.first)
      pq.push(prev);
    prev = t;
    prev.first--;
  }
  return s.length() == res.length();
}

int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    string s;
    cin >> s;
    cout << (int) check_no_adjacent(s) << endl;
  }
  return 0;
}
