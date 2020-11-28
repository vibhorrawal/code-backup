#include<iostream>

using namespace std;

class A {
  int a;
};

int main(){
  int *ptr = new int[5];

  delete[] ptr;

  A *obj = new A;

  delete obj;
}
