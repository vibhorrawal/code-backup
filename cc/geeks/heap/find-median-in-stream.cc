#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define sz(x) (int) x.size()

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void median(v1d &v){
  priority_queue <int> maxpq;
  priority_queue<int, vector<int>, greater<int>> minpq;

  int med = v[0];
  cout<< med << endl;
  maxpq.push(med);
  for(int i = 1; i < sz(v); i++){
    if(v[i] > maxpq.top()) minpq.push(v[i]);
    else maxpq.push(v[i]);

    if(sz(maxpq) - sz(minpq) > 1){
      int t = maxpq.top();
      maxpq.pop();
      minpq.push(t);
    }
    else if(sz(minpq) - sz(maxpq) > 1){
      int t = minpq.top();
      minpq.pop();
      maxpq.push(t);
    }

    if(sz(minpq) == sz(maxpq)) cout<< (minpq.top() + maxpq.top())/2 << endl;
    else if(sz(minpq) > sz(maxpq)) cout<< minpq.top() << endl;
    else cout << maxpq.top() << endl;
  }
}
int32_t main(int argc, char const *argv[]){
  clr();
  int n;
  cin >> n;
  v1d a(n);
  REP(i, n) cin >> a[i];
  median(a);
  return 0;
}
