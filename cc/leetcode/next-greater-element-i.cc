// O(n) space and time
class Solution {
public:
  // changed function parameters 1-> 2 (i assumed wrong names)
    vector<int> nextGreaterElement(vector<int>& nums2, vector<int>& nums1) {
        map<int,int> mp;
        stack<int> st;
        int n = nums1.size();
        for(int i = n-1; i >= 0; i--){
            while(st.size() and st.top() < nums1[i]) st.pop();
            int t = st.empty() ? -1 : st.top();
            mp[nums1[i]] = t;
            st.push(nums1[i]);
        }
        vector<int> res;
        for(int i = 0; i < nums2.size(); i++) res.push_back(mp[nums2[i]]);
        return res;
    }
};
