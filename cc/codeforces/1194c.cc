#include<bits/stdc++.h>
using namespace std;

string s,t,p;
void solve(){
  multiset <char, greater<char> > mset;
  multiset <char, greater<char> >::iterator it;

  for (size_t i = 0; i < s.length(); i++) {
    mset.insert(s[i]);
  }

  for (size_t i = 0; i < p.length(); i++) {
    mset.insert(p[i]);
  }

  for (size_t i = 0; i < t.length(); i++) {
    it = mset.find(t[i]);
    if(it != mset.end()){
      mset.erase(it);
    }
    else{
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
  return;
}
int main(int argc, char const *argv[]){
  int q;
  cin>>q;
  while(q--){
    cin>>s>>t>>p;
    solve();
  }
  return 0;
}
