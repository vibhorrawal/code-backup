// O(n) space and time
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int i = 0, n = arr.size();
        stack<int> index;
        int maxArea = 0;
        while(i<n){
            if(index.empty() || arr[i] > arr[index.top()])
                index.push(i++);
            else{
                int id = index.top(); index.pop();
                int area = arr[id] * (index.empty() ? i : i - index.top() - 1);
                maxArea = max(area, maxArea);
            }
        }
        while(!index.empty()){
            int id = index.top(); index.pop();
            int area = arr[id] * (index.empty() ? i : i - index.top() - 1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};

// O(nlogn) time | O(n) space
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        vector<int>lessLeftIdx(n), lessRightIdx(n);
        lessLeftIdx[0] = -1;
        lessRightIdx[n-1] = n;

        for(int i = 1; i < n; i++){
            int p = i-1;
            while(p >= 0 && heights[p] >= heights[i])
                p = lessLeftIdx[p];
            lessLeftIdx[i] = p;
        }

        for(int i = n-2; i >= 0; i--){
            int p = i + 1;
            while(p < n && heights[p] >= heights[i])
                p = lessRightIdx[p];
            lessRightIdx[i] = p;
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++)
            maxArea = max(heights[i] * (lessRightIdx[i] - lessLeftIdx[i] - 1), maxArea);
        return maxArea;
    }
};

// O(N) time and space stock-span like
class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> left(n), right(n); // left-smaller and right-smaller indexes
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(st.size() and a[st.top()] >= a[i]) st.pop();
            left[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(st.size() and a[st.top()] >= a[i]) st.pop();
            right[i] = st.size() ? st.top() : n;
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int area = a[i] * (right[i] - left[i] - 1);
            ans = max(ans, area);
        }
        return ans;
    }
};
