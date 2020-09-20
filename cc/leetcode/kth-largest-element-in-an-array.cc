class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

//
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

//
class Solution {
    int partition(int start, int end, vector<int>& nums){
        if(start == end)
            return start;
        int ind = start + rand() % (end-start+1);
        swap(nums[start], nums[ind]);
        int pivot = start;
        int l = start + 1, r = end;
        while(l <= r){
            if(nums[pivot] < nums[l] && nums[pivot] > nums[r])
                swap(nums[l], nums[r]);
            if(nums[l] <= nums[pivot])
                l++;
            if(nums[r] >= nums[pivot])
                r--;
        }
        swap(nums[r], nums[pivot]);
        return r;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pivot = partition(0,nums.size()-1,nums);
        k = nums.size() - k;
        while(pivot != k){
            if(pivot > k)
                pivot = partition(0,pivot-1,nums);
            else
                pivot = partition(pivot+1,nums.size()-1,nums);
        }
        return nums[pivot];
    }
};