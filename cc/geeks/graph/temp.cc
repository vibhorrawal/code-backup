#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define int long long
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

const int M = 1e9+7;
void calculateSpan(vi &price, int n, vi &S)
{
    stack<int> st;
    st.push(0);

    S[0] = 1;
    for (int i = 1; i < n; i++) {

        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();

        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
}
int prod(int a, int b){
  a = a % M;
  b = b % M;
  long long ans = a;
  return (ans * b) % M;
}
int max_house(vi &v){
  int n = v.size();
  vi l(n, 0), r(n, 0);

  calculateSpan(v,n,l);
  reverse(all(v));
  calculateSpan(v,n,r);
  reverse(all(r));

  REP(i,n) {
    l[i]--;
    r[i]--;
    assert(l[i] >= 0);
    assert(r[i] >= 0);
  }
  int ans = INT_MIN, ind;
  for (int i = 0; i < n; i++) {
    int val = prod((r[i] + l[i]) % M, i+1);
    if(val >= ans){
      ans = val;
      ind = i+1;
    }
  }
  return ind;
}
int32_t main(int32_t argc, char const *argv[]){
  T(){
    int n;
    cin >> n;
    vi v(n);
    REP(i, n) cin >> v[i];
    cout << max_house(v) << endl;
  }
  return 0;
}
