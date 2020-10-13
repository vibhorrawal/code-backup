#include<iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
void countsort(int arr[], int n, int exp);
void radixsort(int arr[], int n);
// Driver program to test above functions
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}
void radixsort(int arr[], int n){
  int max = arr[0];
  for (int i = 1; i < n ; i++) {
    if(max < arr[i])
    max = arr[i];
  }

  for (int exp = 1; max/exp > 0; exp *= 10) {
    countsort(arr, n, exp);
  }
}

void countsort(int arr[], int n, int exp) {
  int output[n], count[10] = {0};
  for (int i = 0; i < n; i++) {
    count[(arr[i]/exp)%10]++;
  }
  for (int i = 1; i < 10; i++) {
    count[i] += count[i-1];
  }

  for (int i = n-1; i >= 0; i--) {
    output[ count[(arr[i]/exp)%10]  -   1 ] = arr[i];
    count[(arr[i]/exp)%10] --;
  }


  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}
