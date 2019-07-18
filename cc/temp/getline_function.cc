// use of function getline
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
  string s1;
  char s2[20];
  getline(cin,s1,'$');
  // getline(cin,s2);
  std::cout << s1 << '\n';

/* below methods work to flush cin buffer */

  // flushes the standard input
  // (clears the input buffer)
      // while ((getchar()) != '\n');

  // or

  // Discards the input buffer and
  // intial white spaces of string
      // cin >> ws;

// or

// Discards the input buffer
  // cin.sync();    // this didn't help

// or

// discards the input buffer
// cin.ignore(numeric_limits<streamsize>::max(),'\n');


cin.get(s2,20);
std::cout << s2 << '\n';
  return 0;
}
