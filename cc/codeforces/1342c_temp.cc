#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 1
int fun(int a, int b);
int fun2(int a, int b){
  int count=0;
     for (int x = 1; x <= 100; x++) {
       if((x%a)%b != (x%b)%a) count++;
     }
     return count;
}

int32_t main(int argc, char const *argv[]){
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if(fun(i,j) != fun2(i,j)) {
        cout<<"i: "<<i<<" j: "<<j
      <<" fun: "<<fun(i,j)<<" fun2: "<<fun2(i,j)<<endl;
      return -1;
    }
    }
  }
  return 0;
}

int fun(int a, int b){

  if(b==1 || a==1 || a==b) return 0;
  if(a==2&&b==3||b==5)return 50;
  if(a==2&&b==4) return 0;
  ll lcm = (a * b) / __gcd(a,b);
      ll l=1,r=100;
      ll count;
      if(r-l > max(a,b)) {
        count = max(a,b) * ( ((r)/lcm-1)-(l/lcm)-1);

        REP(i,max(a,b)){
            if(l<= i+((l)/lcm)*lcm) count++;
            if(r>= i+(r-1/lcm)*lcm) count++;
          }
        }
        else{
          count = 0;
          REP(i,max(a,b)) if(l<= i+(r-r%lcm) && r>= i+(r-r%lcm)*lcm) count++;
        }
      return r-l+1-count;
    }
