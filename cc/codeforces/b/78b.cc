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

void color(){
  char clr[7] = {'V','I','B','G','Y','O','R'};
  int n;
  cin>>n;
  int mix = n % 7;
  if(mix > 3) mix = 0;
  for(int i = 0; i < 4; i++) cout<<clr[i];
  for(int i = 0; i < mix; i++) cout<<clr[i];
  for(int i = 4; i < n - mix; i++) cout<<clr[i%7];
  cout<<endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  color();
  return 0;
}
