class Solution {
    void bubbleSort(vector<int>& nums){
        int moved = false;

        for(int i = 0; i < nums.size(); i++){
            moved = false;
            for(int j = 0; j < nums.size() - i - 1; j++){
                if(nums[j] > nums[j+1]){
                    moved = true;
                    swap(nums[j+1], nums[j]);
                }
            }
            if(!moved)
                return;
        }
    }
    
    void insertionSort(vector<int>& nums){
        for(int i = 0; i < nums.size(); i++){
            int j = i;
            int ele = nums[j--];
            while(j >= 0 && ele < nums[j]){
                nums[j+1] = nums[j];
                j--;
            }
            nums[++j] = ele;
        }
    }
    
    void selectionSort(vector<int> &nums){
        for(int i = 0; i < nums.size(); i++){
            int mini = i;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[mini] > nums[j])
                    mini = j;
            }
            swap(nums[i], nums[mini]);
        }
    }
public:
    void sortColors(vector<int>& nums) {
        selectionSort(nums);
    }
};