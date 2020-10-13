#include<iostream>
using namespace std;

void  bubbleSort(int arr[], int n){
  for (size_t i = 0; i < n-1 ; i++)
    for (size_t j = 0; j < n-1-i; j++)
      if(arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
}

void betterBubbleSort(int arr[], int n){
  for (size_t i = 0; i < n-1; i++) {
    bool swapped = false;
    for (size_t j = 0; j < n-1-i; j++) {
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(!swapped) break;
  }
}
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;

    betterBubbleSort(arr, n);
    cout << "Sorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;
    return 0;
}
