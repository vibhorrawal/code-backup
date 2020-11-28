#include<iostream>
using namespace std;

template <typename T>
T abs(T n){
  return n < 0 ? -n : n;
}

template <class Type>
class MyStack {
private:
  Type st[20];
  int top;
public:
  MyStack() { top = -1; }
  void push(Type var) {
     st[++top] = var;
   }
  Type pop() {
     return st[top--];
   }
};

int main(int argc, char const *argv[]) {
  cout << abs(-2.35) << endl;
  MyStack<int> st;
  return 0;
}
