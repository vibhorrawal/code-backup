#include<iostream>
#include <cstdlib>
using namespace std;

int partition(int arr[], int low, int high ) {
  int pivot = arr[high];
  int k = low - 1;
  for (size_t i = low; i < high; i++) {
    if(arr[i] < pivot)
      swap(arr[i], arr[++k]);
  }
  swap(arr[high], arr[++k]);
  return  k;
}
int partition_r(int arr[], int low, int high){
  srand(time(NULL));
  int random = low + rand() % (high - low + 1);
  swap(arr[random], arr[high]);
  return partition(arr, low, high);
}
void quickSort(int arr[], int low, int high){
  if(low >= high) return;
  int pivot = partition_r(arr, low, high);
  quickSort(arr, low, pivot-1);
  quickSort(arr, pivot+1, high);
}
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"array: "; for(int i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    cout<<"array: "; for(int i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;
    return 0;
}
