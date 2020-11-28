// C++ program to Rearrange positive and negative numbers in a array
#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}
void RearrangePosNeg(int arr[], int n){
  // using insertion sort Modified
  for (size_t i = 0; i < n ; i++) {
    if(arr[i] < 0)
    {
      if(i == 0) continue;

      int j = 0;
      while (arr[j] < 0 && (j < n))
        j++;
        int temp = arr[i];
        // cout<<"i: "<<i<<" j: "<<j<<endl;
      for (size_t t  = i; t > j; t--) {
          arr[t] = arr[t-1];
      }
      arr[j] = temp;
      // printArray(arr, n);

    }
  }
}
int main(int argc, char const *argv[]){
    int arr[] = { 12, 11, -13, -5, 6, -7, 5, -3, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    RearrangePosNeg(arr, n);
    printArray(arr, n);
  return 0;
}
