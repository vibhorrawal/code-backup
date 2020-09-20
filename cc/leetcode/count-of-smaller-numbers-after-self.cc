// avg -> O(nlog(n)) time | O(n) space
// worst -> O(n^2) time | O(n) space
class Solution {
    struct Node {
        Node *left, *right;
        int val;
        int leftSmallerThan;
        Node(int value){
            left = NULL;
            right = NULL;
            val = value;
            leftSmallerThan = 0;
        }
    };
    vector<int> counts;
    void BSTinsert(Node *root, int num, int countSmallerAtInsertTime){
        if(root->val > num){
            root->leftSmallerThan++;
            if(root->left){
                BSTinsert(root->left, num, countSmallerAtInsertTime);
            }
            else{
                root->left = new Node(num);
                counts.push_back(countSmallerAtInsertTime);
            }
        }
        else{
            countSmallerAtInsertTime += root->leftSmallerThan;
            if(num > root->val)
                countSmallerAtInsertTime++;
            if(root->right){
                BSTinsert(root->right, num, countSmallerAtInsertTime);
            }
            else{
                root->right = new Node(num);
                counts.push_back(countSmallerAtInsertTime);
            }
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0)
            return counts;
        counts.push_back(0);
        Node *bst = new Node(nums[nums.size()-1]);
        for(int i = nums.size()-2; i >= 0; i--)
            BSTinsert(bst, nums[i], 0);
        
        reverse(counts.begin(), counts.end());
        return counts;
    }
};


// avg -> O(nlog(n)) time | O(n) space
// mergesort
class Solution {
    void mergesort(vector<pair<int,int>>& arr, vector<pair<int,int>>& auxilary, vector<int>& smaller, int l, int r){
        if(l == r)
            return;
        int m = (l+r)/2;
        mergesort(auxilary,arr,smaller,l,m);
        mergesort(auxilary,arr,smaller,m+1,r);
        merge(arr,auxilary,smaller,l,m,r);
    }
    void merge(vector<pair<int,int>>& arr, vector<pair<int,int>>& auxilary, vector<int>& smaller, int l, int m, int r){
        int i = l, j = m+1, k = l;
        int numOfElemInRightLessThanLeft = 0;
        while(i <= m && j <= r){
            if(auxilary[i] > auxilary[j]){
                arr[k++] = auxilary[j];
                numOfElemInRightLessThanLeft++;
                j++;
            }
            else{
                arr[k++] = auxilary[i];
                smaller[auxilary[i].second] += numOfElemInRightLessThanLeft;
                i++;
            }
        }
        while(i <= m){
            arr[k++] = auxilary[i];
                smaller[auxilary[i].second] += numOfElemInRightLessThanLeft;
                i++;
        }
        while(j <= r){
            arr[k++] = auxilary[j];
                j++;
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0) return {};
        vector<int> smaller(nums.size(), 0);
        vector<pair<int,int>> arr(nums.size());
        for(int i = 0; i < nums.size(); i++)
            arr[i] = {nums[i], i};
        vector<pair<int,int>> auxilary(arr.begin(), arr.end());
        mergesort(arr,auxilary,smaller,0,arr.size()-1);
        return smaller;
    }
};