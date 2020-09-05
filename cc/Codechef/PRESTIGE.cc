#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG false
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
ll solve(int first[], int up[], int a, int b, int c, int d);
void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}
void swap(int arr[], int k){
  for (int i = 0; i <= k; i++) {
    if(arr[i] == 1) arr[i] = -1;
    else arr[i] = 1;
  }
}
int32_t main(int argc, char const *argv[]){
  iinternaut();
  int n,m;
  cin>>n>>m;
  int up[n],down[n];
  int first[n];
  for (int i = 0; i < n; i++) {
    first[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    cin>>up[i];
  }
  for (int i = 0; i < n; i++) {
    cin>>down[i];
  }
  if(DEBUG){ cout<<"up: "; for(int i = 0; i < n ; i++){ cout<<up[i]<<' ';}cout<<endl; };
  if(DEBUG){ cout<<"down: "; for(int i = 0; i < n ; i++){ cout<<down[i]<<' ';}cout<<endl; };

  for (int tc = 0; tc < m; tc++) {
    // work
    int c;
    cin>>c;
    if(DEBUG){ cout<<"c: "<<c<<endl; };
    if(c == 1){
      int l,r;
      cin>>l>>r;
      l--,r--;
      if(DEBUG){ cout << "c1:: l: "<<l<<" r: "<<r << endl; };

      for (int i = 0; i <= (r-l)/2; i++) {
        swap(up[l+i], up[r-i]);
        swap(down[l+i], down[r-i]);
      }
      if(DEBUG){ cout<<"before: "; cout<<"up: "; for(int i = 0; i < n ; i++){ cout<<up[i]<<' ';}cout<<endl; cout<<"down: "; for(int i = 0; i < n ; i++){ cout<<down[i]<<' ';}cout<<endl; };
      for (int i = l; i <= r; i++) {
        swap(up[i],down[i]);
      }
      if(DEBUG){ cout<<"after: "; cout<<"up: "; for(int i = 0; i < n ; i++){ cout<<up[i]<<' ';}cout<<endl; cout<<"down: "; for(int i = 0; i < n ; i++){ cout<<down[i]<<' ';}cout<<endl; };

    }
    else if(c == 2){
      int k;
      cin>>k;
      if(k == 0) continue;
      k--;
      if(DEBUG){ cout << "c2:: k: "<<k<<endl; };
      swap(first,k);
      for (int i = 0; i <= k/2; i++) {
        swap(first[i],first[k-i]);
      }
      if(DEBUG){ cout<<"first: "; for(int i = 0; i < n ; i++){ cout<<first[i]<<' ';}cout<<endl; };
    }
    else
    {
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      if(DEBUG){ cout << "c3:: a: "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<< endl; };

      cout<<solve(first,up,a,b,c,d)<<endl;
    }

    if(DEBUG){ cout << "--------------" << endl; };
  }
  return 0;
}

ll solve(int first[], int up[], int a, int b, int c, int d){
  ll ans = 0;
  a--,b--,c--,d--;
  for (int i = a; i <= b-a; i++) {
    ans += first[c++] * up[i];
  }
  return ans;
}
