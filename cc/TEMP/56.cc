#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

char plus_ = 43, x = 158;
void draw(int y, int x1, int x2, int l){
  for (int i = 0; i <= l; i++) {
    for (int j = 0; j <= l; j++) {
      if(dist(i,j) == )
    }
  }
}
int32_t main(int argc, char const *argv[]){
  char c;
  cin>>c;
  int l,w;
  scanf("%d&%d", &l, &w);
  if(c == 'S' || c == 's'){
      for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= l; j++) {
          cout<<plus_;
        }
        cout<<endl;
      }
  }
  else if(c == 'R' || c == 'r'){
    for (int i = 0; i <= l; i++) {
      for (int j = 0; j <= w; j++) {
        cout<<plus_;
      }
      for(int j = w+1; j <= l; j++) cout<<x;
      cout<<endl;
    }
  }
  else{
  //   vector<vector<char>> res(l+1, vector<char> (x, w+1));
  //   draw(w-1, l/3, 2 * l/3);
  //   for (int i = 0; i <= l; i++) {
  //     for (int j = 0; j <= l; j++) {
  //       cout<<res[i][j];
  //     }
  //   }
  }
  return 0;
}
