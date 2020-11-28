/* rearrange-array-arrj-becomes-arri-j
For example, Suppose an element’s new value is 2, the old value is 1 and n is 3,
 then the element’s value is stored as 1 + 2*3 = 7. We can retrieve its old value
  by 7%3 = 1 and its new value by 7/3 = 2
*/
// below code is not giving correct answers
#include<bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int n){
  // old
  for (size_t i = 0; i < n ; i++)
    arr[arr[i]%n] = arr[i]%n + n * i;

  // new
  for (size_t i = 0; i < n ; i++)
      arr[i] = arr[i] / n;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

// Drive program
int main()
{
    int arr[] = { 2, 0, 1, 4, 5, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is : " << endl;
    printArray(arr, n);

    rearrange(arr, n);

    cout << "Modified array is :" << endl;
    printArray(arr, n);

    return 0;
}
