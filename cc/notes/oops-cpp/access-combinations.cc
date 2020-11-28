#include<iostream>
using namespace std;

class A{
private:
  int privData;
protected:
  int protData;
public:
  int pubData;
};

class B : public A {
public:
  void fun(){
    int a;
    a = privData; // not accessible
    a = protData;
    a = pubData;
  }
};

class C : private A {
public:
  void fun(){
    int a;
    a = privData; // not accessible
    a = protData;
    a = pubData;
  }
};

int main(){
  int a;
  B bobj;
  a = bobj.privData; // not accessible
  a = bobj.protData; // not accessible
  a = bobj.pubData;

  C cobj;
  a = cobj.privData; // not accessible
  a = cobj.protData; // not accessible
  a = cobj.pubData; // not accessible
}
