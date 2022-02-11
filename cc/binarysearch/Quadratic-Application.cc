// O(N) time | O(1) function space
// for a > 0 we have U
// for a < 0 we have ∩
// approach the values from both
vector<int> solve(vector<int>& x, int a, int b, int c) {
    int n = x.size();
    vector<int> res;
    int l = 0, r = n-1;
    auto F = [&](int x){
        return a * x * x + b * x + c;
    };
    while(l <= r){
        int fl = F(x[l]), fr = F(x[r]);
        if(a > 0){
            if(fl > fr) {
                res.push_back(fl);
                l++;
            }
            else{
                res.push_back(fr);
                r--;
            }
        }
        else{
            if(fl < fr) {
                res.push_back(fl);
                l++;
            }
            else{
                res.push_back(fr);
                r--;
            }
        }
    }
    if(a > 0) reverse(res.begin(), res.end());
    return res;
}