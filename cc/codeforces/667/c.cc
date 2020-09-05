#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void print_array(int n, int x, int y){
  if(n == 2){
    cout << x << ' '<< y<<endl;
    return;
  }
  if(y - x <= n){
    REP(i,n){
      cout<< y - i << ' ';
    }
    cout << endl;
    return;
  }
  int d = (y - x) / (n -1);
  int n1 = n;
  while((n1-1) * d != (y - x)){
    d++;
    d = (y-x+1)/(n1-1) * 2;
  }
  REP(i,n){
    cout << y - i * d << ' ';
  }
  cout<<endl;
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n, x, y;
    cin >> n >> x >> y;
    print_array(n,x,y);
  }
  return 0;
}
