/* Given an array of numbers, arrange them in a way that yields the largest value.
For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654
gives the largest value. And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4},
then the arrangement 998764543431 gives the largest value.
*/
#include<bits/stdc++.h>
using namespace std;
bool compareFunction(string x, string y){
  return x.compare(y) ? 1 : 0;
  
  string xy = x.append(y);
  string yx = y.append(x);

  return xy.compare(yx) ? 1 : 0;
}
void printLargest(vector<string> arr){
  sort(arr.begin(), arr.end(), compareFunction);

  for (size_t i = 0; i < arr.size(); i++) {
    cout<<arr[i];
  }cout<<endl;
}
int main(int argc, char const *argv[]){
  vector<string> arr;
 //output should be 6054854654
 arr.push_back("54");
 arr.push_back("546");
 arr.push_back("548");
 arr.push_back("60");
 printLargest(arr);

  return 0;
}
