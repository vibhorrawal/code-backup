//printing n distinct sorted integers with as few lines of code as possible (<10)
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
std::vector<int> v;
int n,t;cin>>n;
while(n--){
   cin>>t;
   v.push_back(t);
 }
 sort(v.begin(), v.end());
 for (int i = 0; i < v.size(); i++) {
   if(v[i] != v[i-1]) cout << v[i] << " ";
 }cout<<endl;
  return 0;
}
