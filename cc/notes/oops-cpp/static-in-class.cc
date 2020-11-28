#include <iostream>
using namespace std;

class A{
  static int total;
public:
  A() { total++; }
  static int getTotal() { return total; }
  void fun() { cout << "message" << endl; }
};

int main(){
  A obj;
  obj.fun();
  int a = A::getTotal();
}
