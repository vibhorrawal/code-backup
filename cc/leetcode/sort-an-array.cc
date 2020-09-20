// O(nlogn) avg time | O(logn) avg space
class Solution {
    void qsort(int start, int end, vector<int>& nums){
        if(start >= end)
            return;
        int pivot = start;
        int l = start + 1, r = end;
        while(l <= r){
            if(nums[pivot] < nums[l] && nums[pivot] > nums[r]){
                swap(nums[l], nums[r]);
            }
            if(nums[pivot] >= nums[l])
                l++;
            if(nums[pivot] <= nums[r])
                r--;
        }
        swap(nums[pivot], nums[r]);
        qsort(start, r-1, nums);
        qsort(r+1, end, nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        qsort(0,nums.size()-1, nums);
        return nums;
    }
};

// O(nlogn) time | O(n) space
class Solution {
    void mergeSortHelper(vector<int>& nums, vector<int>& auxilary, int l, int r){
        if(l == r)
            return;
        int m = (l+r)/2;
        mergeSortHelper(auxilary, nums, l, m);
        mergeSortHelper(auxilary, nums, m+1, r);
        merge(nums, auxilary, l, m, r);
    }
    void merge(vector<int>& nums, vector<int>& auxilary, int l, int m, int r){
        int i = l, j = m+1, k = l;
        while(i <= m && j <= r){
            if(auxilary[i] < auxilary[j])
                nums[k++] = auxilary[i++];
            else
                nums[k++] = auxilary[j++];
        }
        while(i <= m)
            nums[k++] = auxilary[i++];
        while(j <= r)
            nums[k++] = auxilary[j++];
    }
public:
    //merge sort
    vector<int> sortArray(vector<int>& nums) {
        vector<int> auxilary(nums.begin(), nums.end());
        mergeSortHelper(nums, auxilary, 0, nums.size()-1);
        return nums;
    }
};
