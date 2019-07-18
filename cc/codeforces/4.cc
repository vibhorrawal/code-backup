// https://codeforces.com/contest/1191/problem/B
#include<bits/stdc++.h>
using namespace std;

bool check_consecutive(int n[]){
  // std::cout << "check_consecutive" << '\n';
  int m[3];
  m[0] = n[0];
  m[1] = n[1];
  m[2] = n[2];
  sort(m, m + 3);
  //
  // for (size_t i = 0; i < 3; i++) {
  //   cout<<n[i]<<' ';
  // }cout<<endl;
  m[1] -= m[0];
  m[2] -= m[0];
  m[0] = 0;
  if(m[0] == 0 && m[1] == 1 && m[2] == 2)
    return true;
  return false;
}
void check(int n[], char c[]){
  // std::cout << "check" << '\n';
  string p,m,s;
  for (size_t i = 0; i < 3; i++) {
    if(c[i] == 'p')
      p += char(i);

    if(c[i] == 'm')
      m += char(i);

    if(c[i] == 's')
      s+= char(i);
  }
  string ans;
  if(p.length() >= 2) ans = p;
  if(m.length() >= 2) ans = m;
  if(s.length() >= 2) ans = s;

  if(ans.length() < 2){
     cout<<2<<endl; // eg 1p 2m 3s
     return;
   }
  //but if 1p 2p 3s
  if(ans.length() == 2){
    int i = int(ans[0]), j = int(ans[1]);

    if(abs(n[i] - n[j]) < 3) cout<<1<<endl;
    else cout<<2<<endl;
    return;
  }
  // cout<<"reached end"<<endl;
  // int i = int(ans[0]), j = int(ans[1]), k = int(ans[2]);

  // now check for 2 consq
  int mew[3];
  mew[0] = n[0];
  mew[1] = n[1];
  mew[2] = n[2];
  sort(mew, mew + 3);
  mew[1] -= mew[0];
  mew[2] -= mew[0];
  mew[0] = 0;
  if(mew[0] == 0 && mew[1] == 1 || mew[1] == 2) cout<<1<<endl;
  else cout<<2<<endl;
}
int main(int argc, char const *argv[]){
  int n[3];
  char c[3];
  for (size_t i = 0; i < 3; i++)
    scanf("%d%c", &n[i], &c[i]);
  // cout<<"bool "<<check_consecutive(n)<<endl;
  // for (size_t i = 0; i < 3; i++) {
  //   cout<<n[i]<<c[i]<<endl;
  // }

  // koutsu
  if((n[0] == n[1] && n[1] == n[2]) && (c[0] == c[1] && c[1] == c[2])){
    // std::cout << "entered 1" << '\n';
    cout<<0<<endl;
    return 0;
  }
  //shuntsu
  // cout<<"equality"<<(c[0] == c[1] == c[2])<<endl;
  if(c[0] == c[1] && c[1] == c[2]){
    if(n[0] == n[1] && n[1] == n[2])
      cout<<0<<endl;
    else if(check_consecutive(n))
      cout<<0<<endl;
    else check(n,c);

    return 0;
  }
  else
    check(n,c);
  return 0;
}
