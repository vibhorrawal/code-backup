// O(n) time | O(n) space
// dp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3)
            return 0;
        vector<int> leftMax(n,0), rightMax(n,0);
        int water = 0;
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);
        for(int i = 1; i < n-1; i++)
            water += min(leftMax[i], rightMax[i]) - height[i];
        
        return water;
    }
};

// O(n) time | O(n) space, but using only 1 array (rightMax)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3)
            return 0;
        vector<int> rightMax(n,0);
        int water = 0;
        int leftMax = height[0];
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);
        for(int i = 1; i < n-1; i++){
            leftMax = max(height[i], leftMax);
            water += min(leftMax, rightMax[i]) - height[i];
        }
        return water;
    }
};

// O(n) time | O(1) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3)
            return 0;
        int water = 0;
        int leftMax = 0, rightMax = 0;
        int l = 0, r = n-1;
        while(l < r){
            if(height[l] < height[r]){
                if(height[l] > leftMax)
                    leftMax = height[l];
                else
                    water += leftMax - height[l];
                l++;
            }
            else{
                if(height[r] > rightMax)
                    rightMax = height[r];
                else
                    water += rightMax - height[r];
                r--;
            }
        }
        return water;
    }
};

// O(n) time | O(n) space with clearest meaning
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3)
            return 0;
        vector<int> leftMax(n,0), rightMax(n,0);
        int water = 0;
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        for(int i = 0; i < n; i++)
            water += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        
        return water;
    }
};