#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n, m, x;
  cin>>n>>m>>x;
  vector<vector<char>> key(n, vector<char>(m));
  map<char, vector<pair<int,int>>> mp;
  set<pair<int,int>> shift;
  REP(i,n) REP(j,m) {
    char t;
    cin>>t;
    // key[i][j] = t;
    mp[t].push_back({i,j});
    if(t == 'S') shift.insert({i,j});
  }
  string input;
  cin>>input>>input;
  int count = 0;
  for(char inp : input)
    if(isupper(inp) && shift.size() == 0){
      cout << "-1" << endl;
      return 0;
    }
  auto calcDistance = [&](pair<int, int> pr, set<pair<int,int>> shift){
    int dis = INT_MAX;
    for(pair<int,int> it : shift){
        int i = it.first, j = it.second;
        dis = min(dis, abs((pr.first - i) * (pr.first-i) + (pr.second- j)*(pr.second - j)));
    }
   return dis;
  };
  db(x);
  for(char inp : input){
    int dis = INT_MAX;
    if(islower(inp)) {
        if(mp.count(inp) == 0)
          goto END;
        continue;
    }
    inp = tolower(inp);
    if(mp.find(inp) == mp.end())
      goto END;
    for(pair<int,int> pr : mp[inp])
      dis = min(dis, calcDistance(pr, shift));
    if(dis == -1) {
      END:
      cout << "-1" << endl;
      return 0;
    }
    db(dis);
    if(dis > x*x)
      count++;
  }
  cout<<count<<endl;
  return 0;
}
