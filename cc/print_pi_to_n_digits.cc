#include<iostream>
#include<math.h>
#include<string>

#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[]){
  int n; // <15
  cout << "Enter number of digits to be printed after . in PI: ";
  cin>>n;
  // if (n<10) {
  //   char s[] = {'%',char(n+'0'),'d','\n',0};
  //   printf(s,M_PI);
  //
  // }
  // else{
  //    char s[] = {'%','1',char(n-10+'0'),'d','\n',0};
  //    printf(s,M_PI);
  //  }
  //  cout << M_PI << endl;
  cout<<setprecision(n);
  cout<<M_PI;
  return 0;
}
