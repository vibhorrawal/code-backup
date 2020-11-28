// check-length-string-equal-number-appended-last
#include<bits/stdc++.h>
using namespace std;

int find_number(string s){
  int n = 0;
  char c;
  string num;
  int j = s.length() - 1;
  while(true){
    c = s[j--];
    cout<<c<<endl;
    if (!(c >= '0' && c <= '9')) break;
    num += c;
  }
  for (int i = num.length() - 1; i >= 0 ; i--) {
    n = n * 10 + (static_cast<int>(num[i]) - static_cast<int>('0'));
  }
  return n;
}
bool solve(string s){
  int num = find_number(s);
  int i = num, count = 0;;
  while(i){
    i /= 10;
    count++;
  }
  int n = s.length() - count;
  if(n == num) return true;
  return false;
}
int main(int argc, char const *argv[]){
  string s;
  cin>>s;
  cout<<solve(s)<<endl;
  return 0;
}
