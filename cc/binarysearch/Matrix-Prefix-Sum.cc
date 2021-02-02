vector<vector<int>> solve(vector<vector<int>>& a) {
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(i) a[i][j] += a[i-1][j];
            if(j) a[i][j] += a[i][j-1];
            if(i&&j) a[i][j] -= a[i-1][j-1];
        }
    }
    return a;
}


vector<vector<int>> solve(vector<vector<int>>& a) {
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < a[0].size(); j++)
            if(i) a[i][j] += a[i-1][j];

    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < a[0].size(); j++)
            if(j) a[i][j] += a[i][j-1];
    return a;
}
