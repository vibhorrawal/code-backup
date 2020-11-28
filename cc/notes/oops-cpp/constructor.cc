#include<iostream>
using namespace std;

class A {
  static float someVar;
public:
  A() {
    cout << "I am a default constructor (called before derived classes)" << endl;
  }
  void display(){
    cout << "message" << endl;
  }
  ~A() {}
};
float A::someVar = 0;

class B : public A{
  int var;
  const int c;
public:
  B() : c(0) {
    cout << "I am a derived class constructor" << endl;
  }

  B(int i, int cv) : var(i), c(cv)  // proper way to initialse vars
  {

  }
  void display(){
    cout << "read below" << endl;
    A::display();
  }
};

int main(){
  B obj;
}
