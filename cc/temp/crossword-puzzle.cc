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

vector<string> grid;
map<string, bool> mp;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool check(string toPlace, int y, int x, int dx, int dy){
    for(int i = 0; i < toPlace.size(); i++){
        int xx = x + (i * dx);
        int yy = y + (i * dy);
        if(xx < 0 || xx >= grid[0].size() || yy < 0 || yy >= grid.size()) return false;
        if(grid[yy][xx] == toPlace[i] || grid[yy][xx] == '-') continue;
        else return false;
    }
    return true;
}

void place(string toPlace, int y, int x, int dx, int dy){
    for(int i = 0; i < toPlace.size(); i++){
        int xx = x + (i * dx);
        int yy = y + (i * dy);
        grid[yy][xx] = toPlace[i];
    }
}

bool isComplete(){
    for(int i =0; i < grid.size(); i++)
    for(int j = 0; j < grid[0].size(); j++)
        if(grid[i][j] == '-') return false;
    return true;
}

void recur(){
    for(int i =0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            for(auto it : mp){
                for(int k = 0; k < 4; k++){
                    if(it.second == false && check(it.first, i, j, dx[k], dy[k])){
                        vector<string> temp(grid.begin(), grid.end());
                        it.second = true;
                        place(it.first, i, j, dx[k], dy[k]);
                        recur();
                        if(isComplete()) return;
                        it.second = false;
                        grid = temp;
                    }
                }
            }
        }
    }
}
// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    grid = crossword;
    mp.clear();
    stringstream ss(words);
    string t;
    while(getline(ss, t, ';')) mp[t] = false;
    for(int i =0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            for(auto it : mp){
                for(int k = 0; k < 4; k++){
                    if(it.second == false && check(it.first, i, j, dx[k], dy[k])){
                        vector<string> temp(grid.begin(), grid.end());
                        it.second = true;
                        place(it.first, i, j, dx[k], dy[k]);
                        recur();
                        if(isComplete()) return grid;
                        it.second = false;
                        grid = temp;
                    }
                }
            }
        }
    }
    assert(false);
    return grid;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n;
  cin>>n;
  vector<string> v(n);
  REP(i,n) cin>>v[i];
  string inp;
  cin>>inp;
  vector<string> res = crosswordPuzzle(v, inp);
  for (int i = 0; i < n; i++) {
    cout << res[i] << endl;
  }
  return 0;
}
