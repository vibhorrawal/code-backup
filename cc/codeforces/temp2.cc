#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){
  char c = 'a',v = 68;
  string s1 = "tt",s2="tt";
  cout<<s1+c<<endl;
  // cout<<s1.append(c)<<endl;
  cout<<s1+to_string(c)<<endl;
  return 0;
}
