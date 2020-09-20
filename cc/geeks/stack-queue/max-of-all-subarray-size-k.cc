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

void max_k(vi v, int n, int k){
  deque<int> q;
  if(k == 1){
    for(int i = 0; i < n ; i++){ cout<<v[i]<<' ';}cout<<endl;
    return;
  }
  REP(i,k) {
    while(q.size() && v[q.back()] < v[i]){
      q.pop_back();
    }
    q.push_back(i);
  }
  cout << v[q.front()] << ' ';
  for(int i = 0; i < n-k; i++){
    if(q.size() && q.front() <= i){
      q.pop_front();
    }
    int j = i + k;
    if(v[q.back()] < v[j]){
      while(q.size() && v[q.back()] < v[j]){
        q.pop_back();
      }
    }
    q.push_back(j);
    cout << v[q.front()] << ' ';

  }
  cout << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    REP(i,n) cin >> v[i];
    max_k(v,n,k);
  }
  return 0;
}
