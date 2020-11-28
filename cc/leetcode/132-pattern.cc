// O(n^2) time | O(1) space
class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n = a.size();
        int mini = INT_MAX;
        for(int i = 1; i < n; i++){
            mini = min(mini, a[i-1]);
            for(int j = i + 1; j < n; j++){
                if(a[i] > a[j] && a[j] > mini)
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    // O(n) space | O(n) time
    // s1 < s3 > s2
    bool find132pattern(vector<int>& nums) {
        int s2 = INT_MIN;
        stack<int> st;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < s2) return true;
            else while(!st.empty() && st.top() < nums[i]){
                s2 = max(s2, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
