#include <iostream>
using namespace std;
const int MAX = 3;

class Stack {
private:
  int st[MAX];
  int top;
public:
  class Full {  //exception class
  public:
    int maxsize;
    Full(int s) : maxsize(s) { }
  };

  class Empty { }; //exception class

  Stack() { top = -1; }

  void push(int var) {
    if(top >= MAX-1)
      throw Full(MAX);
    st[++top] = var;
  }
  int pop() {
  if(top < 0)
    throw Empty();
  return st[top--];
  }
};

int main(){
  Stack s1;

  try {
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
  }
  catch(Stack::Full e) {
    cout << "Exception: Stack Full of size: " << e.maxsize << endl;
  }
  catch(Stack::Empty) {
    cout << "Exception: Stack Empty" << endl;
  }

  return 0;
}
