#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

int currency[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

int min_coins(int n){
  int dp[n+1];
  REP(i,n+1) dp[i] = i;
  dp[0] = 0;

  for (int i = 1; i < n+1; i++) {
    for (int j = 0; j < 10; j++) {
      if(currency[j] < i)
      dp[i] = min(dp[i-currency[j]]+1, dp[i]);
    }
  }
  return dp[n];
}
void print_coins(int n){
  int i=9;
  while(n>0 && i > -1){
    while(currency[i]<=n){
      cout<<currency[i]<<' ';
      n = n- currency[i];
    }
    i--;
  }
}
int main(int argc, char const *argv[]){
T(){
  int n;cin>>n;
  print_coins(n);
  cout << endl;
  }
  return 0;
}
