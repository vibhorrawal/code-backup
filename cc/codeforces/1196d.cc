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
#define DEBUG true
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
void create1(char* c, int k){
  // char c[2000];
  int i;
  for ( i = 0; i < k/3; i+=3) {
    c[i] = 'R';
    c[i+1]='G';
    c[i+2]='B';
  }
  if(k%3 == 1) c[i] = 'R';
  if(k%3==2){c[i++] = 'R';c[i]='G';}
  // return c;
}
void create2(char* c,int k){
  int i;
  // char c[2000];
  for ( i = 0; i < k/3; i+=3) {
    c[i] = 'G';
    c[i+1]='B';
    c[i+2]='R';
  }
  if(k%3 == 1) c[i] = 'G';
  if(k%3==2){c[i++] = 'G';c[i]='B';}
  // return c;
}
void create3(char* c,int k){
  int i;
  // char c[2000];
  for ( i = 0; i < k/3; i+=3) {
    c[i] = 'B';
    c[i+1]='R';
    c[i+2]='G';
  }
  if(k%3 == 1) c[i] = 'B';
  if(k%3==2){c[i++] = 'B';c[i]='R';}
  // return c;
}
void solve(){
  int n,k;
  cin>>n>>k;
  char s[2000];
  cin>>s;
  int i;
  for (i = 0; s[i]; i++);
  int m = i; // strlen()

  char t1[2000],t2[2000],t3[2000];
  create1(t1,k);
  create2(t2,k);
  create3(t3,k);

  if(DEBUG){ cout<<"t1: "; for(int i = 0; i < k ; i++){ cout<<t1[i]<<' ';}cout<<endl; };
  if(DEBUG){ cout<<"t2: "; for(int i = 0; i < k ; i++){ cout<<t2[i]<<' ';}cout<<endl; };
  if(DEBUG){ cout<<"t3: "; for(int i = 0; i < k ; i++){ cout<<t3[i]<<' ';}cout<<endl; };
  // size_t found1 = s.find(t1);
  // size_t found2 = s.find(t3);
  // size_t found3 = s.find(t3);

  // if(found1 != string::npos || found2 != string::npos || found3 != string::npos){
  //   cout<<0<<endl;
  //   return;
  // }
  int min1 = lcs(s,t1,m,k);
  int min2 = lcs(s,t2,m,k);
  int min3 = lcs(s,t3,m,k);
  cout<<min1<<' '<<min2<<' '<<min3<<endl;
  int minimum = min1;
  if(minimum > min2) minimum = min2;
  if(minimum > min3) minimum = min3;

  cout<<minimum<<endl;
}
int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
    solve();
  }
  return 0;
}
