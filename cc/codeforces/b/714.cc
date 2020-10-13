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

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n;
  cin>>n;
  vi arr(n);
  REP(i,n) cin>>arr[i];
  map<int,int> count;
  for(int i : arr){
    count[i]++;
  }
  bool possible = false;
  if(count.size() < 3) possible = true;
  if(count.size() == 3){
    map<int,int>::iterator it = count.begin();
    int a = (*it).first;
    it++;
    int b = (*it).first;
    it++;
    auto c = (*it).first;
    if(c - b == b - a) possible = true;
  }
  cout<<(possible ? "YES" : "NO");
  return 0;
}
