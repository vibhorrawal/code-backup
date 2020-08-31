#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void test_case(){
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  if(n==1 && a==1 && b ==1 ){
    cout << 1;
    return;
  }
  if((a==n && b != c) || (b == n && a != c) ||
  (a + b - c > n) || (c==1 && a == 1 && b == 1) || c > min(a,b)){
    cout << "IMPOSSIBLE";
    return;
  }
  v1d ans(n);
  REP(i,n) ans[i] = 1;
  bool rev = false;
  int k=2,j=0;

  if(a>b){
    swap(a,b);
    rev = true;
  }
  if(n==2 && a==1 && b==2){
    ans[0]=2;
    ans[1]=1;
    goto PRNT;
  }

  if(c == a && a == b){
    ans[n-1] = n;

    for (int i = 0; i < c-1; i++) {
      ans[i] = n;
    }
    goto PRNT;
  }

  REP(i,a-c) ans[j++] = k++;

  REP(i,c) ans[j++] = n;

  j=n-1;
  k=1;
  if(b-c == 1) k=2;
  REP(i,b-c) ans[j--] = k++;

  PRNT:
  if(rev) reverse(all(ans));
  for(int i = 0; i < n ; i++){ cout<<ans[i]<<' ';}
/*
  // for a
  int k=n-a+1;
  REP(i,a-c) cout << k++ << ' ';
  // for c
  REP(i,n) cout<< n << ' ';

  // hide remaining buildings
  k=1;
  REP(i,n-(a+b)+c+1) cout << k++<<' ';

  //for b
  REP(i,b-c) cout << --n << ' ';
  cout << endl;*/
}
int32_t main(int argc, char const *argv[]){
  clr();
  int T;
  cin>>T;
  REP(i,T){
    cout<<"Case #"<<i+1<<": ";
    test_case();
    cout<<endl;
  }
  return 0;
}
