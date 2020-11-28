#include <iostream>
using namespace std;

class alpha {
private:
  alpha& operator = (alpha&); // assigment operator
  alpha(alpha&); // copy constructor
};
// now you cant copy object of this class
// ie.
// obj1 = obj2 or
// alpha obj2(obj1)
// will fail
