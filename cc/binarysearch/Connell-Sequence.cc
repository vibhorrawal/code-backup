// O(n) time | O(1) additional space
int solve(int n) {
    vector<int> v(1,1);
    int count = 1;
    while(v.size() <= n){
        int can = v.back() + 1;
        count++;
        for(int i = 0; i < count; i++, can+=2) v.push_back(can);
    }
    return v[n];
}
