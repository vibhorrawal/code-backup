// O(nlogn) time | O(1) space
bool solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if(nums.size() == 1) return false;
    int i = 1, count = 1;
    while(i < nums.size()){
        if(nums[i] != nums[i-1]){
            if(count % 2) return false;
            count = 1;
        }
        else count++;
        i++;
    }
    return count % 2 == 0;
}

bool solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if(nums.size() % 2) return false;
    if(nums.size() == 1) return false;
    for(int i = 1; i < nums.size(); i+= 2){
        if(nums[i] != nums[i-1])
            return false;
    }
    return true;
}

// O(n) time and O(1) space using hashing with xor to prevent collision
// 1 ^ 2 ^ 3 == 0
int hashf(int n){
    return n * n * 101 + 5;
}
bool solve(vector<int>& nums) {
    int x = 0;
    for(int n : nums){
        x = x ^ hashf(n);
    }
    return x == 0;
}

bool solve(vector<int>& a) {
    int x = 0;
    hash<int> hs;
    for(int i : a) {
        x ^= hs(i * i + 1);
    }
    return x == 0;
}

// best way I found, there won't be hash collisions if we check for All(i) and All(i+1)
// like check for [2,4,6]
bool solve(vector<int>& a) {
    int x = 0, x_1 = 0;
    for(int i : a){
        x ^= i;
        x_1 ^= (i + 1);
    }
    return x == 0 and x_1 == 0;
}
