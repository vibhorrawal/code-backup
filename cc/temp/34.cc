// retref.cpp
// returning reference values
#include <iostream>
using namespace std;

// global variable
int& setx();
// function declaration
int main()
{
// set x to a value, using
setx() = 92;
// function call on left side
cout << "x = " << setx() << endl; // display new value in x
return 0;
}
int x;
//--------------------------------------------------------------
int& setx()
{
return x;
// returns the value to be modified
}
