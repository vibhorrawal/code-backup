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

const int ROW = 5, COL = 6;

int min_dice_throws(vi &board){
  int last = ROW * COL - 1;
  queue<pair<int, int>> q;
  q.push({0,0});
  while(!q.empty()){
    auto curr = q.front();
    q.pop();
    if(curr.first == last)
      return curr.second;
    for (int i = 1; i <= 6; i++) {
      if(curr.first + i > last)
        continue;
      if(board[curr.first + i])
        q.push({board[curr.first + i], curr.second + 1});
      else
        q.push({curr.first + i, curr.second + 1});
    }
  }
  return -1;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin >> n;
    // vvi grid(ROW, vi (COL, 0));
    vi board(ROW * COL, 0);
    REP(i,n){
      int a,b;
      cin >> a >> b;
      board[a-1] = b-1;
    }
    cout << min_dice_throws(board) << endl;
  }
  return 0;
}
