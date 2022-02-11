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


// alternate 
class Solution {
public:
    vector<int> find_nge(vector<int> &a) {
        const int n = a.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(st.size() and a[st.top()] <= a[i]) {
                int id = st.top();
                res[id] = a[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> indexOf;
        for(int i = 0; i < nums2.size(); i++) 
            indexOf[nums2[i]] = i;
        
        vector<int> res, nge = find_nge(nums2);
        for(int num : nums1) {
            int id = indexOf[num];
            res.push_back(nge[id]);
        }
        return res;
    }
};