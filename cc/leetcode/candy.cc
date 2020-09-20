// O(n) time | O(n) space
class Solution {
    vector<int> findMinIndx(vector<int>& arr){
        vector<int> res;
        if(arr.size() == 1)
            return {0};
        for(int i = 0; i < arr.size(); i++){
            if(i == 0 && arr[0] < arr[1])
                res.push_back(i);
            if(i == arr.size() - 1 && arr[i] < arr[i-1])
                res.push_back(i);
            if(i == 0 || i == arr.size()-1)
                continue;
            if(arr[i-1] >= arr[i] && arr[i] <= arr[i+1])
                res.push_back(i);
        }
        return res;
    }
    void inflate(vector<int>& ratings, int idx, vector<int>& res){
        int l = idx - 1;
        while(l >= 0 && ratings[l] > ratings[l+1]){
            res[l] = max(res[l], res[l+1] + 1);
            l--;
        }
        int r = idx + 1;
        while(r < ratings.size() && ratings[r] > ratings[r-1]){
            res[r] = res[r-1] + 1;
            r++;
        }
    }
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() < 2)
            return ratings.size();
        vector<int> res(ratings.size(), 1);
        auto minIndx = findMinIndx(ratings);
        for(int min: minIndx)
            inflate(ratings, min, res);
        
        return accumulate(res.begin(), res.end(), 0);
    }
};

// O(n) time | O(1) space
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() < 2)
            return ratings.size();
        vector<int> res(ratings.size(), 1);
        for(int i = 1; i < res.size(); i++){
            if(ratings[i] > ratings[i-1])
                res[i] = res[i-1] + 1;
        }
        for(int i = res.size() -2; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                res[i] = max(res[i], res[i+1]+1);
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};