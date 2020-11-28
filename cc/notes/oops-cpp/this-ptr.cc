#include <iostream>
using namespace std;

class alpha {
private:
  int data;
public:
  alpha() { }
  alpha(int d)  { data = d; }
  void display() { cout << data; }
  alpha& operator = (alpha& a) { //overloaded = operator
    data = a.data; //not done automatically
    cout << "Assignment operator invoked" << endl;
    return *this; //return copy of this alpha
    // this->data; // you use this like any obj pointer, but it points to it's own object location
  }
};

int main(){

}
