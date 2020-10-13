#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
int32_t main(int argc, char const *argv[]){
  T(){
    ll a,b,q;
    cin>>a>>b>>q;
    ll lcm = (a * b) / __gcd(a,b);
    while(q--){
        ll l,r;
        cin>>l>>r;
        if(a==b && b==1){
           cout<<0<<' ';
           continue;
         }
        ll count;
        if(r-l > max(a,b)) {
          if(DEBUG){ cout << " f "; };
          count = max(a,b) * ( ((r)/lcm-1)-(l/lcm)-1);

        // if(DEBUG){ cout << "count: "<<count << endl; };
          REP(i,max(a,b)){
              if(l<= i+((l)/lcm)*lcm) count++;

              if(r>= i+(r-1/lcm)*lcm) count++;
            }
          }
          else{
            if(DEBUG){ cout << " e "; };
            count = 0;
            REP(i,max(a,b)) if(l<= i+((r)/lcm)*lcm && r>= i+((r)/lcm)*lcm) count++;
          }
        cout << r-l+1-count<<' ';
        if(DEBUG){ cout << endl; };
      // cout << count << ' ';
    }
    cout  << endl;
  }
  return 0;
}
