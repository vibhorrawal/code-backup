// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;


 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}

} // } Driver Code Ends


/*The function takes an array of heights, width and
length as its 3 arguments where each index i value
determines the height, width, length of the ith box.
Here n is the total no of boxes.*/
struct box {
  int h;
  int w;
  int l;
};
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<box> a(n * 3);
    for (int i = 0; i < n; i++) {
      a[3*i].h = length[i];
      a[3*i].l = max(width[i], height[i]);
      a[3*i].w = min(width[i], height[i]);

      a[3*i+1].h = width[i];
      a[3*i+1].l = max(length[i], height[i]);
      a[3*i+1].w = min(length[i], height[i]);

      a[3*i+2].h = height[i];
      a[3*i+2].l = max(width[i], length[i]);
      a[3*i+2].w = min(width[i], length[i]);
    }

    sort(a.begin(), a.end(), [](box b1, box b2){
      return (b1.w * b1.l) < (b2.w * b2.l);
    });

    n = n * 3;
    int dp[n];

    for (int i = 0; i < n; i++) {
      dp[i] = a[i].h;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        // if(a[j].l > a[i].l || a[j].w > a[i].w) continue;
        // dp[i] = max(dp[i], dp[j] + a[i].h);
        if(a[j].l < a[i].l && a[j].w < a[i].w && dp[i] < dp[j] + a[i].h)
          dp[i] = dp[j] + a[i].h;
      }
    }
    return *max_element(dp, dp+n);
}
