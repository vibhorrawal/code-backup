// palindromes of size k are printed with given chars
#include<bits/stdc++.h>
using namespace std;
vector<string> li;
int k,kk;
void increment_arr(int arr[], int n){
  arr[k-1]++;
  for (int i = k-1; i > 0; i--) {
    if(arr[i] == n){
      arr[i-1]++;
      arr[i]--;
    }
  }
  // cout<<"array: "; for(int i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;
}

void print_array(int index[], char arr[]){
  string s = "";
  for (int i = 0; i < k; i++) {
    s += char(arr[index[i]]);
  }
  int l;
  if(kk%2) l = k-2;
  else l = k-1;
  for (int i = l; i >= 0; i--) {
    s+= char(arr[index[i]]);
  }
  li.push_back(s);
}


int main(int argc, char const *argv[]){
  int n;
  cin>>n>>kk;
  // k = (k)/2+1;
  if(kk%2) k = kk/2 +1;
  else k = kk / 2;
  char input_chars[n];
  cin>>input_chars;
  int index[k] = {0};
  int temp[k];
  while(index[0] != n){

    for (int i = 0; i < k; i++) temp[i] = index[i];
    do {
      print_array(temp, input_chars);
      // cout<<"temp: "; for(int i = 0; i < 5 ; i++){ cout<<temp[i]<<' ';}cout<<endl;
    } while(next_permutation(temp, temp + k));

    increment_arr(index, n);

  }
  // cout<<"size: "<<li.size()<<endl;
  // cout<<li[0]<<endl;

  bool contains;
  for(auto i = 0; i < li.size() ; i++){
    contains = true;
    // if(contains) cout<<li[i]<<endl;

    for (int j = 0; j < n; j++) {
      if(li[i].find(input_chars[j]) == std::string::npos){
        contains = false;
        // cout<<input_chars[j]<< " not found"<<" in "<<li[i]<<endl;
      }
    }
    if(contains) cout<<li[i]<<endl;
  }
  return 0;
}
