// checking base class constructors and derived class's
#include<bits/stdc++.h>
using namespace std;

class c1 {
private:
  /* data */
int c;
public:
  c1 (){
    printf("statement 2\n");
  }
  // virtual ~c1 ();
};
class c2 : public c1{
private:
  /* data */

public:
  c2 (): c1()
  {
    printf("standard 3\n" );
  }
  // virtual ~c2 ();
};
int main(int argc, char const *argv[]){
  c2 a;

  return 0;
}
