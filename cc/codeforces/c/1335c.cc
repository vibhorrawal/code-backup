#include<iostream>
#include<map>
using namespace std;

int main(int argc, char const *argv[]){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    std::map<int, int> mp;
    int l;
    for (int i = 0; i < n; i++) {
      cin>>l;
      mp[l]++;
    }
    int maxcount = -1,unique = 0;
    for (auto x: mp) {
      maxcount = max(maxcount, x.second);
      if(x.second) unique++;
    }
    if(unique == maxcount) unique--;
    cout << min(unique, maxcount) << endl;
  }
  return 0;
}
