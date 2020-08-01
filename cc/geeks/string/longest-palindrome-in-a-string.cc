#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

string palindrome(string s){
  // int max=0,start=0,end=0;
  // for (int i = 1; i < s.size(); i++) {
  //   int j=0;
  //   while(i-j >=0 && i + j <s.size()){
  //     if(s[i-j]==s[i+j]){
  //       if(max<2*j+1){
  //         max = 2*j+1;
  //         start=i-j;
  //         end=i+j;
  //       }
  //     }
  //     else break;
  //     j++;
  //   }
  //   int k=0;
  //   while(i-k >=0 && i + k + 1<s.size()){
  //     if(s[i-k]==s[i+k+1]){
  //       if(max<2*k+2){
  //         max=2*k+2;
  //         start=i-k;
  //         end=i+k+1;
  //       }
  //     }
  //     else break;
  //     k++;
  //   }
  // }
  int maxLength = 1;

   int start = 0;
   int len = s.size();

   int low, high;

   // One by one consider every
   // character as center point of
   // even and length palindromes
   for (int i = 1; i < len; ++i) {
       // Find the longest even length palindrome
       // with center points as i-1 and i.
       low = i - 1;
       high = i;
       while (low >= 0 && high < len
              && s[low] == s[high]) {
           if (high - low + 1 > maxLength) {
               start = low;
               maxLength = high - low + 1;
           }
           --low;
           ++high;
       }

       // Find the longest odd length
       // palindrome with center point as i
       low = i - 1;
       high = i + 1;
       while (low >= 0 && high < len
              && s[low] == s[high]) {
           if (high - low + 1 > maxLength) {
               start = low;
               maxLength = high - low + 1;
           }
           --low;
           ++high;
       }
   }
  return s.substr(start,start+maxLength-1);
}
int main(int argc, char const *argv[]){
T(){
  string s;
  cin>>s;
  cout<<palindrome(s)<<endl;
  }
  return 0;
}
