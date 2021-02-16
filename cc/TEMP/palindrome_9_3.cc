// palindromes of size k are printed with given chars with ? in between
#include<bits/stdc++.h>
using namespace std;
vector<string> li;
vector<string> newList;
int k,kk;
void increment_arr(int arr[], int n){
  arr[k-1]++;
  for (int i = k-1; i > 0; i--) {
    if(arr[i] == n){
      arr[i-1]++;
      arr[i]--;
    }
  }
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

void removeInvalidStrings(char input_chars[], int n){
  bool contains;
  for(auto i = 0; i < li.size() ; i++){
    contains = true;

    for (int j = 0; j < n; j++) {
      if(li[i].find(input_chars[j]) == std::string::npos){
        contains = false;
      }
    }
    if(contains) newList.push_back(li[i]);
  }

}
void addQuestionMark(string s){
  if(s.size() < 4){
    cout<<"Invalid string"<<endl; exit(0);
  }
  string temp = s;
  for (int i = 1; i < temp.size(); i+=1) {
    // temp.insert(i,"?");
    for (int j = i+1; j < temp.size(); j+=1) {
      // temp.insert(i,"?");
      for (int k = j+1; k < temp.size(); k+=1) {
        cout<<temp.insert(i,".").insert(j+1,".").insert(k+2,".")<<endl;
        temp = s;
      }
    }
  }

}
int main(int argc, char const *argv[]){
  int n;
  cin>>n>>kk;
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
    } while(next_permutation(temp, temp + k));

    increment_arr(index, n);

  }
  removeInvalidStrings(input_chars, n);
  for (int i = 0; i < newList.size(); i++) {
    addQuestionMark(newList[i]);
  }
  // addQuestionMark("abcba");
  return 0;
}