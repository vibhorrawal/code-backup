// https://codeforces.com/contest/1191/problem/0
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
  int x;
  cin>>x;
  //now
  int d = x % 4;
  switch (d) {
    case 0: cout<<"1 A"<<endl; break;
    case 1: cout<<"0 A"<<endl; break;
    case 2: cout<<"1 B"<<endl; break;
    case 3: cout<<"2 A"<<endl; break;
  }
  return 0;
}
