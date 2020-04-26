#include<iostream>
using namespace std;

#define T() int tc;cin>>tc;while(tc--)
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)


bool incl[100000] = {0};
int a[100000];
int r[100000];
int Count[100000];
int n;

void reset(){
  for (int i = 1; i <= n; i++) {
    incl[i] = false;
  }
}

int countVal(int i){
  int count = 0;
  for (int j = 1; j <= n; j++) {
    if(i == r[j]) count++;
  }
  return count;
}
int findNum(int num){
  for (int i = 1; i <= n; i++) {
    if(a[i] == num) return i;
  }
  return 0;
}
bool isPossible(int num){
  for (int j = 1; j <= n; j++) {
    int rj = j;
    while(incl[rj++]);rj--;

    if(rj == n+1) rj = -1;
    r[j] = rj;
  }
  // cout<<"array: "; for(int i = 1; i <= n ; i++){ cout<<r[i]<<' ';}cout<<endl;
  for (int i = 1; i <= n; i++) {
    Count[i] = countVal(i);
  }
  // cout<<"Count: "; for(int i = 1; i <= n ; i++){ cout<<Count[i]<<' ';}cout<<endl;

  int max = -1;
  for (int i = 1; i <= n; i++) {
    if(max < Count[i]) max = Count[i];
  }

  int index = findNum(num);
  if(Count[index] == max){
    incl[index] = true;
    return true;
  }
  else return false;
}
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int32_t main(int argc, char const *argv[]){
  iinternaut();
    // n = 5;
    // isPossible();
    // exit(0);
    T(){
      // int n;
      cin>>n;
      // a = new int [n];
      REP(i,n) cin>>a[i+1];
      // r = new int [n];
      // Count = new int [n];
      reset();
      bool flag = 0;
      int i = 1;
      while (i<=n) {
        if(!isPossible(i++)){
          flag = 1;
          break;
        }

      }

      if(flag) cout << "NO" << endl;
      else cout << "YES" << endl;
    }
  return 0;
}
