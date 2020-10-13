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

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n,m,k,t;
  cin>>n>>m>>k>>t;
  vector<pair<int,int>> field(k);
  REP(tt,k){
    int i,j;
    cin>>i>>j;
    field[tt] = {i-1,j-1};
  }
  auto J = [&](int i, int j){
    int waste = 0;
    for (int ii = 0; ii < k; ii++) {
      if(field[ii].first < i) waste++;
      if(field[ii].first == i && field[ii].second <= j) waste++;
    }
    return waste;
  };
  REP(tt,t){
    int i, j;
    cin>>i>>j;
    i--,j--;
    if(find(field.begin(), field.end(), make_pair(i,j)) != field.end()){
      cout << "Waste" << endl;
    }
    else{
      int f = (i)*m+j - J(i,j);
      if(f % 3 == 0) cout << "Carrots" << endl;
      if(f % 3 == 1) cout << "Kiwis" << endl;
      if(f % 3 == 2) cout << "Grapes" << endl;
    }
  }
  return 0;
}
