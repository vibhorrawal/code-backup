#include <iostream>
using namespace std;

class Base {
public:
  void show() {
    cout << "base class" << endl;
  }
};

class Derv1 : public Base {
public:
  void show(){
    cout << "derv1 class" << endl;
  }
};

/////////////////////////////////////////////////////////////
class BaseWithVirt {
public:
  virtual void show(){
    cout << "base class" << endl;
  }
};

class Derv2 : public BaseWithVirt {
public:
  void show(){
    cout << "derv1 class" << endl;
  }
};

int main() {
  Base * obj = new Derv1;
  obj->show();  // prints base class

  BaseWithVirt *obj2 = new Derv2;
  obj2->show(); // prints derv2 class  aka late binding / dynamic binding
}

/////////////////////////////////////////////////////////////////
class ThisIsAnAbstractClass { // has atleast one pure virtual function, hence can't instantiate, but can derive
public:
  virtual void fun() = 0; // pure virtual function
};

///////////////////////////////////////////////////////////////
class Parent {
protected:
  int basedata;
};
class Child1 : virtual public Parent // shares copy of Parent
{ };
class Child2 : virtual public Parent // shares copy of Parent
{ };
class Grandchild : public Child1, public Child2 {
public:
  int getdata() { return basedata; } // OK: only one copy of Parent
};
