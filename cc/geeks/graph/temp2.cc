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

void calculateSpan(vi &price, int n, int S[])
{
    stack<int> st;
    st.push(0);

    S[0] = 1;
    for (int i = 1; i < n; i++) {

        while (!st.empty() && price[st.top()] < price[i])
            st.pop();

        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
}

int max_house(vi &v){
  int n = v.size();
  int l[n];
  calculateSpan(v, n, l);
  REP(i,n) l[i]--;
  cout<<"l: "; for(int i = 0; i < n ; i++){ cout<<l[i]<<' ';}cout<<endl;
  return 0;
  // stack<pair<int, int>> st;
  // vi r(n);
  // REP(i,n) r[i] = n - i;
  // st.push({v[0], 0});
  //
  // for (int i = 0; i < n; i++) {
  //   if(st.empty())
  //     st.push({v[i],i});
  //
  //     while(!st.empty() && st.top() < v[i]){
  //
  //     }
  // }
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin >> n;
    vi v(n);
    REP(i, n) cin >> v[i];
    cout << max_house(v) << endl;
  }
  return 0;
}
