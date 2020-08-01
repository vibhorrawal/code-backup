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

void spiral(int **mat, int m, int n){
  int i = 0,j = 0;
  int maxj = n, minj = 0, maxi = m, mini = 0;
  while (mini < maxi && minj < maxj) {
    for(j = minj; j< maxj; j++) cout<<mat[mini][j]<<' ';
    mini++;

    for(i = mini; i < maxi; i++) cout<<mat[i][maxj-1]<<' ';
    maxj--;

    if(mini< maxi){
      for(j = maxj - 1; j >= minj; j--) cout<<mat[maxi-1][j]<<' ';
      maxi--;
    }

    if(minj < maxj) {
      for(i = maxi - 1; i >= mini; i--) cout<<mat[i][minj]<<' ';
      minj++;
    }
  }
  cout << endl;
}
int main(int argc, char const *argv[]){
T(){
  int m,n;cin>>m>>n;
  int **mat = new int*[m];
  REP(i,m) mat[i] = new int[n];
  REP(i,m) REP(j,n) cin>>mat[i][j];
  spiral(mat,m,n);
}
  return 0;
}
