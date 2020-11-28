#include<bits/stdc++.h>
using namespace std;
void test1(){
  cout<<"Global var is "<<globalVariable<<endl;
}
int globalVariable = 10;
void test2(){
  cout<<"Global var is "<<globalVariable<<endl;
}
int main(int argc, char const *argv[]){
  test1();
  test2();
  return 0;
}
