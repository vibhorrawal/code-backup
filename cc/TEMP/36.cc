// string find
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
  string s1 = "Hello there! How";
  int x = s1.find(' ');

  cout<<s1.size()<<endl;
  printf("x = %d\n", x);

  while(x < s1.size()){
    s1.replace(x, 1, "/");
    x = s1.find(' ');
    printf("x = %d\n", x);
  }
  cout<<s1;
  cin>>x;
  return 0;
}
