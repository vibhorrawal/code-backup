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
#define db(x) cout<<"deb: "<<x<<endl;

/*
void remove(string s){
  int n=s.size();
  if(n<2){
    cout << s<<endl;
    return;
  }
  int j=0;
  for (int i = 1; i < n; i++) {
    if(s[i]!=s[j]){
      j++;
      s[j]=s[i];
    }
  }
  j++;
  s[j]='\0';
  cout << s.substr(0,j) << endl;
}
char* removeUtil(char str[], char* last_removed){
  if(str[0]=='\0' || str[1]=='\0') return str;
  if(str[0]==str[1]){
    *last_removed=str[0];
    while (str[1] && str[0]==str[1]) str++;
    return str;
  }
}
char* remove_str(string s){
  char* res = new char[s.size()];
  int i;
  for ( i = 0; i < s.size(); i++) res[i]=s[i];
  res[i]='\0';
  char last_removed='\0';
  return removeUtil(res,&last_removed);
}*/

// this looks fine to me, but wont pass for gfg: mississipie
//
// Its Correct output is:
// mpie
//
// And Your Code's output is:
// mipie
string remove_str_stack(string s){
  stack<char> st;
  st.push(s[0]);
  int i=1;
  bool popped = false;
  while(i<s.size()){
    if(st.empty()){
      st.push(s[i]);
    }
    else{
      popped = false;
      while(st.top() == s[i]){
        i++;
        popped = true;
      }

      if(popped) --i,st.pop();
      else st.push(s[i]);
    }
    i++;
  }
  string ans;
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  reverse(all(ans));
  return ans;
}
int main(int argc, char const *argv[]){
T(){
  string s;
  cin>>s;
  // remove(s);
  cout<<remove_str_stack(s)<<endl;
  }
  return 0;
}
