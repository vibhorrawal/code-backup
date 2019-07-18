#include<iostream>
using namespace std;

void  insertionSort(int arr[], int n ) {
  int i,j;
  for (i = 1; i < n; i++) {
    int key = arr[i];
    for (j = i-1; j >= 0; j--) {
      if(arr[j] < key) break;
      arr[j+1] = arr[j];
    }
    arr[j+1] = key;
  }
}
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;

    insertionSort(arr, n);
    cout << "Sorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;
    return 0;
}
