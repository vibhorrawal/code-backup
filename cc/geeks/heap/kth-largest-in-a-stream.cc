#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define sz(x) (int) x.size()

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void largest(int n, int k){
  priority_queue<int, vector<int>, greater<int>> pq;
  int i=0,t;
  db(k);
  db(n);
  for (i = 0; i < k-1; i++) {
    cin>>t;
    pq.push(t);
    db(i);
    cout << -1 << ' ';
  }

  cin>>t;
  pq.push(t);
  cout << pq.top() << ' ';

  for(++i; i < n; i++){
    cin >> t;
    if(t > pq.top()){
      pq.push(t);
      pq.pop();
    }
    cout << pq.top() << ' ';
  }
  cout << endl;
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n,k;
    cin >> k >> n;
    // v1d a(n);
    // REP(i,n) cin >> a[i];
    largest(n, k);
  }
  return 0;
}
