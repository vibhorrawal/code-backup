#include<stdio.h>
enum State{WORKING = 0, FAIL, FREEZ, A, B};
enum State currState = 2;
enum State findState(){
  return currState;
}

int main(){
  register xyz_123= 91;
  auto pqr_123 = 991;
  const _1a1 = pqr_123 + ~xyz_123;
  printf("%d\n", _1a1);
  (findState() == WORKING)?printf("%d\n", WORKING):printf("not\n");
  return 0;
}
