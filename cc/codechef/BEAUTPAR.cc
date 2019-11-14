#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin>>arr[i];
    }
    string out[k];
    int ki;
    int ii = 0;

   while(1){
     int max_sub,global_max;
     max_sub = global_max = arr[ii];

     int count = 0;
     for (int i = ii; i < n ; i++) {
       max_sub += arr[i];
       global_max = max(global_max, max_sub);
       
       count++;
       if(global_max > 0){
         out[ki++] = count;
          break;
        }
     }

    ii++;
    if(ii >= n) break;
   }

   if(ki >= k){
     cout << "YES" << endl;
     for (int i = 0; i < k; i++) {
       cout << out[i] << " ";
     }
     cout<<endl;
   }
   else{
     cout << "NO" << endl;
   }
  }
  return 0;
}
