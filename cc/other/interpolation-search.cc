#include<iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key){
  int low = 0, high = n -1;
  while ((low <= high) && (key >= arr[low]) && (key <= arr[high])) {
    if (low == high) {
      if(arr[low] == key) return low;
      else return -1;
    }

    int pos = low + (static_cast<double>(high - low)/(arr[high] - arr[low])) * (key - arr[low]);
    // int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));
    if(arr[pos] == key)
      return pos;

      if(arr[pos] < key)
        low = pos + 1;
      else
        high = pos - 1;
    }
    return -1;
  }
// Driver Code
int main()
{
    // Array of items on which search will
    // be conducted.
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21,
                 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 18; // Element to be searched
    int index = interpolationSearch(arr, n, x);

    // If element was found
    if (index != -1)
        cout << "Element found at index " << index<<endl;
    else
        cout << "Element not found.";
    return 0;
}
