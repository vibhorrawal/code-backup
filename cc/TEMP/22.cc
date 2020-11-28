// Binary Search based C++ program to find number
// of rotations in a sorted and rotated array.
#include<bits/stdc++.h>
using namespace std;
int countRotations(int arr[], int l, int h){
  int mid = l + h / 2;
  if (arr[mid] > arr[mid+1]) {
    return mid;
  }
  if (arr[mid] < arr[h]) {
    return countRotations(arr,l,mid-1);
  }
  else return countRotations(arr,mid+1,h);
}
int main(int argc, char const *argv[]){
    int arr[] = {2, 3, 6, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << (countRotations(arr, 0, n-1)+1)%n;
  return 0;
}
