// O(nlogn) time | O(1) space
bool solve(vector<vector<int>>& a) {
    sort(a.begin(), a.end(), [](const vector<int> &x, const vector<int> &y){
        if(x[0] == y[0]) return x[1] >= y[1];
        else return x[0] < y[0];
    });
    for(int j = 0; j < a.size(); j++){
        int i = j;
        while(i+1 < a.size() && a[i][0] <= a[j][1]){
            if(a[j][0] <= a[i+1][0] && a[i+1][1] <= a[j][1])
                return true;
            i++;
        }
    }
    return false;
}

bool solve(vector<vector<int>>& a) {
    sort(a.begin(), a.end(), [](const vector<int> &x, const vector<int> &y){
        if(x[0] == y[0]) return x[1] >= y[1];
        else return x[0] < y[0];
    });
    int endTime = INT_MIN;
    for(int j = 0; j < a.size(); j++){
        if(a[j][1] <= endTime)
            return true;
        endTime = max(endTime, a[j][1]);
    }
    return false;
}
