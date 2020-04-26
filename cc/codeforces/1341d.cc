//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl 'n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)

string num[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int32_t main(int argc, char const *argv[]){
  int n,k;
  cin>>n>>k;
  char clock[n];
  string s;
  REP(i,n){
    cin>>s;
    REP(j,10) if(s==num[j]){ clock[i] = j+'0'; break;}
  }
  string out = "";
  if(n==1){

  }else{
    int index = 0;
    while(index++ < n)
    switch (clock[index]) {
      case '0': if(k>1) {
                  out += '8';
                  k--;
              }
              else if(k==1){
                out 
              }
              else{
                out += '0';
              }
              break;

      case '1':
      if(k>=4){
        out += '9';
        k -= 4;
      }
      else if(k>=1){
        out += '7';
        k--;
      }
      else{
        out += '1';
      }
      break;

    case '2':
    if(k>=2){
      out += '8';
      k -= 2;
    }
    else{
      out += '2';
    }
    break;

    case '3':
    if(k>=1){
      out += '9';
      k--;
    }
    else{
      out += '3';
    }
    break;

    case '4':
    if(k>=2){
      out += '9';
      k -=2;
    }
    else{
      out += '4';
    }
    break;

    case '5':
    if(k>=1){
      out += '9';
      k--;
    }
    else{
      out += '5';
    }
    break;

    case '6':
    if(k>=1)
    {
      out += '8';
      k--;
    }
    else{
      out += '6';
    }
    break;

    case '7':
    if(k>= 3){
      out += '9';
      k -=3;
    }
    else {
      out += '7';
    }
    break;

    case '8':
    out += '8';
    break;

    case '9':
    out += '9';
    break;
    }

    if(!k) cout<<out;
    else cout<<-1;
  }
  return 0;
}
