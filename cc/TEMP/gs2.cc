int minimizeMeetingCost(int N, int M, vector<vector<int>> costs) {
int row,col,curr_max,max_sofar;

for (int i = 0; i < N ; i++) {
  for (int j = 0; j < M ; j++) {
    costs[i][j] = -costs[i][j];
  }
}
for (int i = 0; i < N ; i++) {
  curr_max = costs[i][0];
for (int j = 1; j < M ; j++) {
  if(curr_max > costs[i][j])
  
}
}
}
