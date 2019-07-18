// https://codeforces.com/contest/1194/problem/A
#include<bits/stdc++.h>
using namespace std;

void solve(int n, int x){
  list<int> li;
  list<int>::iterator it1,it2,it3;

  for (size_t i = 0; i < n; i++) {
    li.push_back(i+1);
  }
   it1 = it2 = li.begin();

   for (int num = 0; num < x; num++) {
     it1 = li.erase(it1);
     advance(it1, 1);
    }
    it2 = li.begin();
    advance(it2, x-1);
    cout<<*it2<<endl;
}
int main(int argc, char const *argv[]){
  int t;
  cin>>t;
  int n,x;
  while(t--){
    cin>>n>>x;
    solve(n,x);
  }
  return 0;
}
