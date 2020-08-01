#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)

int count(int a[], int n){
  std::map<int, pair<int,int>> mp;
  int result=0;
  REP(i,n){
    for(int j = i+1;j<n;j++){
        mp[(a[i] + a[j])] = make_pair(i,j);
    }
  }
  REP(i,n){
    if(mp.find(a[i]) != mp.end()) result++;
  }
  return result==0?-1:result;
}

int geeks_count(int arr[], int n)
   {
       // compute the max value in the array
       // and create frequency array of size
       // max_val + 1.
       // We can also use HashMap to store
       // frequencies. We have used an array
       // to keep remaining code simple.
       int max_val = 0;
       for (int i = 0; i < n; i++)
           max_val = max(max_val, arr[i]);
       int freq[max_val + 1]={0};
       for (int i = 0; i < n; i++)
           freq[arr[i]]++;

       int ans = 0; // stores the number of ways

       // Case 1: 0, 0, 0
       ans += freq[0] * (freq[0] - 1) * (freq[0] - 2) / 6;

       // Case 2: 0, x, x
       for (int i = 1; i <= max_val; i++)
           ans += freq[0] * freq[i] * (freq[i] - 1) / 2;

       // Case 3: x, x, 2*x
       for (int i = 1; 2 * i <= max_val; i++)
           ans += freq[i] * (freq[i] - 1) / 2 * freq[2 * i];

       // Case 4: x, y, x + y
       // iterate through all pairs (x, y)
       for (int i = 1; i <= max_val; i++) {
           for (int j = i + 1; i + j <= max_val; j++)
               ans += freq[i] * freq[j] * freq[i + j];
       }

       return ans==0?-1:ans;  
   }

int main(int argc, char const *argv[]){
  T(){
    int n;
    cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    cout<< geeks_count(a,n)<<endl;
  }
  return 0;
}
