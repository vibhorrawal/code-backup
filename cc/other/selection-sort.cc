#include<iostream>
using namespace std;

void  selectionSort(int arr[], int n ) {
  int min_index;
  for (size_t i = 0; i < n ; i++) {
    min_index = i;
    for (size_t j = i+1; j < n; j++) {
      if(arr[j] < arr[min_index])
        min_index = j;
    }
    swap(arr[i], arr[min_index]);
  }
}
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;

    selectionSort(arr, n);
    cout << "Sorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;
    return 0;
}
