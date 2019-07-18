// longest-subarray-having-average-greater-than-or-equal-to-x
#include<iostream>
using namespace std;
int LongestSub(int arr[], int n, int x){
  for (size_t i = 0; i < n ; i++) {
    arr[i] -= x;
  }
  int global_max = 0;
  int longest = global_max;
  int sum = 0;
  for (size_t i = 0; i < n ; i++) {
    if(sum + arr[i] >= 0){
      sum = sum + arr[i];
      longest++;
    }
    else // sum < 0
    {
      sum = 0;
      longest = 0;
    }

    global_max = max(global_max, longest);

  }
  return global_max;
}
int main(int argc, char const *argv[]){
  int arr[] = { -2, 1, 6, -3 };
  int n = sizeof(arr) / sizeof(arr[0]);

  int x = 3;

  cout << LongestSub(arr, n, x);
  return 0;
}
