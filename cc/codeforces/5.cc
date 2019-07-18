#include<bits/stdc++.h>
using namespace std;
std::vector<int> v;
list<int> p;
int main(int argc, char const *argv[]){
  long long int n,m,k;
  cin>>n>>m>>k;
  for (size_t i = 0; i < n; i++) {
    v.push_back(i+1);
  }
  int in;
  for (size_t i = 0; i < m; i++) {
    cin>>in;
    p.push_back(in);
  }
  long long int pgsize = n / k;
  if(k * pgsize != n) pgsize++;

  vector <int> ::iterator vi1,vi2,vi,it;
  list <int> :: iterator pi;
  vi1 = v.begin();
  pi = p.begin();
  // vi2 = vi1 + (k-1);
  int countperpage = 0, count = 0;
  while (!p.empty()) {
    // countperpage = 0;
    it = find(vi1, vi1 + k, p.front());
    if( it == vi1 + k){
      count++;
      vi1 += k;
    }
    else p.pop_front();
  }
  cout<<count<<endl;
  return 0;
}
