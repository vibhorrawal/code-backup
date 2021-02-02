// O(n) space | O(logn) time
// time is more or less constant as an Int of 10 digits will get to
// 3 digits in first step, and then also it is decreasing
int change(int n){
    int res = 0;
    while(n){
        int s = n % 10;
        n /= 10;
        res += s*s;
    }
    return res;
}
bool solve(int n) {
    set<int> vis;
    while(n != 1){
        vis.insert(n);
        n = change(n);
        if(vis.count(n))
            return false;
    }
    return true;
}
