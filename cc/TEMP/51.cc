#include<iostream>
using namespace std;

class A{
public:
  int a;
  A(){
    cout << "message" << endl;
  }
  void display(){
    cout << "a: "<<a << endl;
  }
};

void displa(A a){
  a.display();
}

A fun(A a){
  a.a = 2;
  A f;
  return f;
}
int32_t main(int argc, char const *argv[]){
  A obj;
  // displa(obj);
  fun(obj);
  displa(obj);
  return 0;
}
