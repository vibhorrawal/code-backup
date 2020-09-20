#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<ll>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

void print_NGE(vi &v, int n){
  stack<int> st;
  int i;
  vi res (n);
  for(i = 0; i < n; i++){
    if(st.empty()){
      st.push(i);
      continue;
    }
    while(!st.empty() && v[st.top()] < v[i]){
      res[st.top()] = v[i];
      st.pop();
    }
    st.push(i);
  }
  while(!st.empty()) {
    res[st.top()] = -1;
    st.pop();
  }
  for(int i = 0; i < n ; i++){ cout<<res[i]<<' ';}cout<<endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin >> n;
    vi v(n);
    REP(i,n) cin >> v[i];
    print_NGE(v,n);
  }
  return 0;
}
