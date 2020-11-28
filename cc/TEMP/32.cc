#include<bits/stdc++.h>
using namespace std;
void test(int a = 10, char c = 'c'){
  cout<<"Default argument is called"<<endl;
}
void test(){
  std::cout << "function overloaded!" << '\n';
}
int main(int argc, char const *argv[]){
  test();
  return 0;
}

/* OUTPUT:
32.cc: In function ‘int main(int, const char**)’:
32.cc:10:8: error: call of overloaded ‘test()’ is ambiguous
   test();
        ^
32.cc:3:6: note: candidate: ‘void test(int, char)’
 void test(int a = 10, char c = 'c'){
      ^~~~
32.cc:6:6: note: candidate: ‘void test()’
 void test(){
      ^~~~
*/
