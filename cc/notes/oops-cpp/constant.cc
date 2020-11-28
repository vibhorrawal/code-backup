#include<iostream>
using namespace std;

const int willBeGlobal = 2; // default global vars are initialsed to 0

class A {
  const int a = 0;
};

class B{
  const int b;
  B() : b(2) { }
};

class C{
public:
  mutable int var; // these vars can be changed hence the keyword mutable
  C() : var(0) { }
  void fizz(){
    cout << "fizz" << endl;
  }

  void buzz(int i) const {
    var = i;
    cout << "buzz: "<< var << endl;
  }
};

int main(){
  const C obj;

  // obj.fizz(); // error
  obj.buzz(2);
}
