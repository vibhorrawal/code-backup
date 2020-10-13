#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int32_t main(int argc, char const *argv[]){
  fastIO;
  int a, x, y;
  cin >> a >> x >> y;
  int upper = ceil((double) y / a) * a;
  db(upper);
  if(upper > y && y > upper - a){
    int side = ((upper-a)/a) % 5;
    db(side);
    int num = ((upper-a)/(5 * a)) * 7;
    num += side + 1;
    db(num);
    // single for 0,1,4
    if(side == 1 || side == 0){
      if(a > x * 2 && x * 2 > -a) cout << num << endl;
      else cout << "-1" << endl;
    }else if(side == 2){
      if(a > x && x > 0) cout << num +1 << endl;
      else if(-a < x && x < 0) cout << num  << endl;
      else cout << "-1" << endl;
    }else if(side == 3){
        if(a > x * 2 && x * 2 > -a) cout << num +1 << endl;
        else cout << "-1" << endl;
      }
      else if(side == 4){
        if(a > x && x > 0) cout << num +2<< endl;
        else if(-a < x && x < 0) cout << num +1<< endl;
        else cout << "-1" << endl;
      }
    }
  else{
    cout << "-1" << endl;
  }
  return 0;
}
