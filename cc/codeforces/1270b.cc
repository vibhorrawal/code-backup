//#pragma GCC optimize ("O3")
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
#define pb(a) push_back(a)

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  T(){
    int n;
    cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    int mini[n], maxi[n],miniv[n], maxiv[n], minival = 0, maxival=0;
    mini[0] = a[0];
    maxi[0] = a[0];
    for (int i = 1; i < n; i++) {
      if(mini[i-1] < a[i]){
        mini[i] = mini[i-1];
        miniv[i] = minival;
      }
      else{
        mini[i] = a[i];
        miniv[i] = i;
        minival = i;
      }

      if(maxi[i-1] > a[i]) {
        maxi[i] = maxi[i-1];
        maxiv[i] = maxival;
      }
      else {
        maxi[i] = a[i];
        maxiv[i] = i;
        maxival = i;
      }
    }
    // REP(i,n){
    //   if(maxi[i] - mini[i] >= abs(maxiv[i] - miniv[i])+1){
    //     cout<<"YES\n";
    //     cout<<min(maxiv[i],miniv[i])+1<<' '<<max(maxiv[i],miniv[i])+1<<endl;
    //     goto restart;
    //   }
    // }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          if(maxi[j] - mini[i] >= abs(maxiv[j] - miniv[i])+1){
            cout<<"YES\n";
            cout<<min(maxiv[j],miniv[i])+1<<' '<<max(maxiv[j],miniv[i])+1<<endl;
            goto restart;
          }
      }
    }
    cout << "NO" << endl;
    restart:
    ;
  }
  return 0;
}
