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
#define DEBUG false
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  // v1d arr;

  T(){
    int n,k;
    cin>>n>>k;
    int sum = 0;
    int temp;
    int arr[n];
    int size = 0;
    for (int i = 0; i < n; i++) {
      cin>>temp;
      if(temp <= k) sum += temp;
      else arr[size++] = temp;
    }

    // if(DEBUG){ cout<<"array: "; for(auto i = arr.begin(); i != arr.end() ; i++){ cout<<*i<<' ';}cout<<endl; };
    int N = size - 1;
    if(size == 1){
      cout<<sum+arr[0]<<endl;
      continue;
    }
    sort(arr, arr+size);
    int max = arr[size-1];

    priority_queue<int> pq;
    for (int i = 0; i < size-1; i++) {
      pq.push(arr[i]);
    }
    while(1){
      int m1 = pq.top();
      pq.pop();
      int m2 = pq.top();
      if(m2 <= k) break;

      pq.push(--m1);
      pq.push(--m2);
    }
    int m = pq.top();
    while(m > k){
      m--;
      max--;
    }
    int ans = 0;
    ans += m + max;
    ans += (size - 2) * k;
  //   while(size>2){
  //   if(DEBUG){ cout<<"array: "; for(int i = 0; i < size ; i++){ cout<<arr[i]<<' ';}cout<<endl; };
  //   if(arr[N-2] <= k) break;
  //
  //   int temp = arr[N - 2] - 1;
  //   arr[N-2]--;
  //   arr[N-1] -= temp;
  // }

  // while(arr[N-1] > k){
  //   int temp = arr[N - 1] - k;
  //   arr[N-1] = k;
  //   arr[N] -= temp;
  // }

    // int ans = 0;
    // FOR(i,arr) ans += *i;

    // for (int i = 0; i < size; i++) {
    //     ans += arr[i];
    // }
    cout<<ans+sum<<endl;

    // arr.clear();
  }
  return 0;
}
