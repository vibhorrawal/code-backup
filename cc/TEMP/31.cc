/*Given a sorted array of positive integers, rearrange the array alternately
i.e first element should be the maximum value, second minimum value,
 third-second max, fourth-second min and so on.
 */
#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n){
  int maxElement = arr[n-1] + 1;
  int minIndex = 0, maxIndex = n-1;
  // to store a.b.c at arr[i] we use a = arr[i], arr[i] = b * c + a, b is 'n' so we can store c with this method
  for (size_t i = 0; i < n ; i++) {
    if(i % 2) // odd
      arr[i] = arr[i] + (arr[minIndex++] % maxElement) * maxElement;

    else // even
    arr[i] = arr[i] + (arr[maxIndex--] % maxElement) * maxElement;
  }

  for (size_t i = 0; i < n ; i++) {
    arr[i] = arr[i] / maxElement;
  }
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    rearrange(arr, n);

    cout << "\nModified Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        std::cout << '\n';
    return 0;
}
