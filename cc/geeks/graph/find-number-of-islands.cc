// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
int gn,gm;
int dx[] = {0,0,-1,-1,-1,1,1,1};
int dy[] = {1,-1,-1,0,1,-1,0,1};
vector<int> *gA;
void findUtil(int i, int j){
  if(i < 0 || i >= gn || j < 0 || j >= gm)
    return;
    if(gA[i][j] == 0) return;
    gA[i][j] = 0;

    for (int ii = 0; ii < 8; ii++) {
      for (int jj = 0; jj < 8; jj++) {
        findUtil(i+dx[ii], j + dy[jj]);
      }
    }
    return;
}
int findIslands(vector<int> A[], int n, int m) {
    gn = n;
    gm = m;
    gA = A;
    // Your code here
    int ans = 0;
    for (int i = 0; i < gn; i++) {
      for (int j = 0; j < gm; j++) {
        if(gA[i][j]){
          ans += 1;
          findUtil(i,j);
        }
      }
    }
    return ans;
}
