// O(n+m) time | O(n) space
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> contain;
        for(int num: nums1)
            contain[num]++;
        vector<int> res;
        for(int num: nums2){
            if(contain[num]){
                res.push_back(num);
                contain[num]--;
            }
        }
        return res;
    }
};

// O(nlogn + mlogm) time | O(1) space
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j])
                i++;
            else if(nums1[i] > nums2[j])
                j++;
            else if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++,j++;
            }
        }
        return res;
    }
};
