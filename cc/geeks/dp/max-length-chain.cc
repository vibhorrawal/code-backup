//Driver code starts
#include<bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};

bool compare(struct val a, struct val b){
  return a.first < a.second;
}
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
	sort(p,p+n,compare);
  int max=0,mcl[n];
  for (int i = 0; i < n; i++) mcl[i] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if(p[j].second < p[i].first && (mcl[i] < mcl[j] + 1))
        mcl[i] = mcl[j] + 1;
    }
  }
  for (int i = 0; i < n; i++) if(max < mcl[i]) max = mcl[i];

  return max;
}

int main(){
  int t;
  cin>> t;
  while(t--){
    int n;
    cin>>n;
    val p[n];
    for (int i = 0; i < n; i++) {
      cin>>p[i].first>>p[i].second;
    }
    cout << maxChainLen(p,n) << endl;
  }
}
