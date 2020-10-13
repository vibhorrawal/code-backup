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

void arraySort(){
  int n;
  cin>>n;
  std::vector<int> v(n);
  REP(i,n) cin>>v[i];
  bool isSorted = true;
  for (int i = 0; i < n-1; i++) {
    if(v[i] > v[i+1])
      isSorted = false;
  }
  if(isSorted){
    cout << "yes\n1 1" << endl;
    return;
  }
  int l = 0, r = n-1;
  while(l + 1 < n && v[l] <= v[l+1])
    l++;
  while(r - 1 >= 0 && v[r] >= v[r-1])
    r--;
  // int minEle = *min_element(v.begin() + l, v.begin() + r + 1);
  // int maxEle = *max_element(v.begin() + l, v.begin() + r + 1);
  reverse(v.begin() + l, v.begin() + r + 1);
  isSorted = true;
  for (int i = 0; i < n-1; i++) {
    if(v[i] > v[i+1])
      isSorted = false;
  }
  if(isSorted)
    cout << "yes" << endl<<l+1<<' '<<r+1;
  else
    cout << "no" << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  arraySort();
  return 0;
}
