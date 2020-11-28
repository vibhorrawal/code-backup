// CPP program for rearrange an
// array such that arr[i] = i.
#include<bits/stdc++.h>
using namespace std;
void fix(int a[], int n){
  int i = 0;
  int y = a[0];
  int z;
  while(i < n) {
    if(y == -1)
      y = a[++i];
    else if(y == i){
      a[i] = y;
      i++;
    }
    else {
      z = a[y]; // temp value of the variable where this variable will go
      a[i] = -1;
      a[y] = y;
      y = z;
    }
  }
  // cout<<"here"<<endl;
  return;
}
int main(int argc, char const *argv[]){
  int A[] = { -1, -1, 6, 1, 9,
                  3, 2, -1, 4, -1 };

      int len = sizeof(A) / sizeof(A[0]);
      fix(A, len);

      for (int i = 0; i < len; i++)
          cout << A[i] << " ";
  return 0;
}
