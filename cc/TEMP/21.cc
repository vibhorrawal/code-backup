// to find sum(i*a[i])
#include<bits/stdc++.h>
using namespace std;

void solve(int a[], int n){
  int sum = 0, max = -1;
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (size_t j = 0; j < n; j++) {
      sum += a[(j+i)%n] * ((j)%n);
    }
    if (sum > max) max = sum;
  }
  std::cout << max << '\n';
}
int main(){
  int a[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(a)/sizeof(a[0]);
  std::cout << n << '\n';
  solve(a, n);
}
