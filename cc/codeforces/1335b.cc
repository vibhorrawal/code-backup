#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){
  int t;
  cin>>t;
  while(t--){
    int n,a,b;
    cin>>n>>a>>b;

    int arr[a];
    for (int i = 0; i < a; i++) {
      arr[i] = i % b;
    }
    for (int i = 0; i < n; i++) {
      cout<<char(arr[i%a]+'a');
    }
    cout << endl;
  }
  return 0;
}
