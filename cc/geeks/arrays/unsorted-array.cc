#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      int a[n];
      for (int i = 0; i < n; i++) {
        cin>>a[i];
      }
      int lmax[n],rmin[n];
      lmax[0]=a[0];
      for (int i = 1; i < n; i++) {
        lmax[i] = max(lmax[i-1],a[i]);
      }
      rmin[n-1]=a[n-1];
      for (int i = n-2; i >=0; i--) {
        rmin[i] = min(rmin[i+1],a[i]);

      }
      for (int i = 1; i < n-1; i++) {
        if(a[i] >= lmax[i-1] && a[i] <= rmin[i+1]) {
          cout << a[i] << endl;
          goto CONT;
        }
      }
      cout << "-1" << endl;
      CONT:
      t;
    }
  return 0;
}
