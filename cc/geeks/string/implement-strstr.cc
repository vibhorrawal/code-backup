#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

void computeLPS(string pat, int M, int lps[]){
  lps[0]=0;
  int len=0;
  int i=1;

  while(i<M) {
    if(pat[i]==pat[len]){
      len++;
      lps[i]=len;
      i++;
    }
    else{
      if(len) len = lps[len-1];
      else lps[i++]=0;
    }
  }

}
int kmp(string txt, string pat){
  int M = pat.size();
  int N = txt.size();

  int lps[M];
  computeLPS(pat,M,lps);
  int i=0,j=0;
  while(i<N){
    if(pat[j]==txt[i]) i++,j++;
    if(j==M) return i-j; // patern found
    if(i<N && pat[j] != txt[i]){
      if(j) j = lps[j-1];
      else i++;
    }
  }
  return -1;
}
int main(int argc, char const *argv[]){
T(){
  string s,x;
  cin>>s>>x;
  cout << kmp(s,x)<< endl;
  }
  return 0;
}
