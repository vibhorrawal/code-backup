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
#define DEBUG 0
#define pb(a) push_back(a)


int32_t main(int argc, char const *argv[]){
  T(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int newarr[n];
    int maxvalue = -1,maxcount = -1;
    int ans;
    REP(i,n) cin>>arr[i];
    std::map<int, int> mp;
    REP(i,n/2){
      int num = arr[i] + arr[n-i-1];
      // if(num<2k)
      mp[num]++;
      if(DEBUG){ cout << "loop1" << endl; };

    }
    TRYAGAIN:
    maxvalue = -1, maxcount = -1;
    for(auto x: mp){
      if(maxcount < x.second){
        maxvalue = x.first;
        maxcount = x.second;
      }
      if(DEBUG){ cout << "loop2" << endl; };
    }
    ans=0;
    for (int i = n/2; i < n; i++) {
      if(arr[i] > k){
        ans++;
        newarr[i] = maxvalue - arr[n-i-1];
        if(newarr[i] > k) newarr[i] = 1;
      }
      else newarr[i] = arr[i];
    }
    if(maxcount == 0 || maxcount == -1 || maxvalue == 0 || maxvalue == -1 ){
      ans = n/2;
      goto END;
    }
    // ans = 0;
    REP(i,n/2){
      newarr[i] = maxvalue - newarr[n-i-1];
      if(newarr[i] != arr[i]) ans++;
      if(newarr[i] > k || newarr[i] < 1){
        mp[maxvalue] = 0;
        goto TRYAGAIN;
      }
      if(DEBUG){ cout << "loop3" << endl; };

    }
    END:
    cout<<ans<<endl;
  }
  return 0;
}
