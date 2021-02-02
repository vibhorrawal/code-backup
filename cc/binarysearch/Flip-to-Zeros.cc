
// O(n) time | O(1) space
int solve(vector<int>& nums) {
    int count = 0;
    bool swap = false;
    for(int i : nums){
        if((i == 0 && swap == false) ||
        (i == 1 && swap == true))
            continue;
        count++;
        swap = !swap;
    }
    return count;
}

int solve(vector<int>& a) {
    int flipped = 0, ans = 0;
    for(int i : a){
        if(i ^ flipped){
            ans++;
            flipped ^= 1;
        }
    }
    return ans;
}
