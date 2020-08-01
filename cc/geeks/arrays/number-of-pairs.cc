#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

// x ^ Y[i] > Y[i] ^ x
int count(int x, int y[], int n, int NoOfY[]){
  if(x == 0) return 0;
  if(x == 1) return NoOfY[0];
  int* index = upper_bound(y,y+n,x);
  int answer = (y+n) - index;

  answer += (NoOfY[0] + NoOfY[1]);
  if(x==2) answer -= (NoOfY[3] + NoOfY[4]);
  if(x==3) answer += NoOfY[2];
  return answer;
}

int countPairs(int x[], int y[], int m, int n){
  int NoOfY[5] = {0};
  sort(y,y+n);
  REP(i,n){
    if(y[i] < 5) NoOfY[y[i]]++;
  }
  int ans = 0;
  REP(i,m) ans += count(x[i],y,n,NoOfY);
  return ans;
}

int32_t main(int argc, char const *argv[]){
  T(){
    int m,n;cin>>m>>n;
    int x[m],y[n];
    REP(i,m) cin>> x[i];
    REP(i,n) cin>> y[i];
    cout<< countPairs(x,y,m,n)<< endl;
  }
  return 0;
}
