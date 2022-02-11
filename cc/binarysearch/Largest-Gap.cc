// O(nlogn) time | O(1) space
int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int diff = 0;
    for(int i = 1; i < nums.size(); i++)
        diff = max(nums[i] - nums[i-1], diff);
    return diff;
}

// O(N) time and space
// ref: https://binarysearch.com/problems/Largest-Gap/solutions/4904614
int solve(vector<int>& nums) {
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    const int n = nums.size();
    if(n < 2) return 0;
    int d = max(1, (maxVal - minVal) / (n - 1)); // bucket from (minVal, minVal + d)
    int numBuckets = ((maxVal - minVal) / d) + 1;
    vector<pair<int,int>> bucket(numBuckets, make_pair(INT_MAX, INT_MIN)); // min,max of bucket[i]
    for(int num : nums) {
        // in i-th bucket we have (minVal + i * d, minVal + (i + 1) * d)
        int i = (num - minVal) / d;
        // cout<<i<<endl;
        if(i >= numBuckets) return -1;
        bucket[i].first = min(bucket[i].first, num);
        bucket[i].second = max(bucket[i].second, num);
    }
    int maxDiff = 0;
    // inside a bucket max diff possible is d - 1, and for array with same d throughout 
    // atleast we have d hence no need to check diff inside a bucket, but
    // accross buckets

// this was initial try with very complicated logic which can be replaced if you try to not think min/max instead 
// if a bucket is used or not(even with 1 val, min/max both are populated)
    // int i = 0, nextVal = INT_MIN, prevVal = INT_MIN;
    // while(i < n) {
    //     while(i < n and bucket[i].second == INT_MIN) i++;
    //     if(i == n) break;
    //     prevVal = bucket[i].second;
    //     i++;
    //     if(i == n) break;
    //     while(i < n and bucket[i].first == INT_MAX) i++;
    //     if(i == n) break;
    //     nextVal = bucket[i].first;
    //     maxDiff = max(maxDiff, nextVal - prevVal);
    // }

    int prev = 0;
    for(int idx = 1; idx < numBuckets; idx++) {
        if(bucket[idx].first != INT_MAX) {
            maxDiff = max(maxDiff, bucket[idx].first - bucket[prev].second);
            prev = idx;
        }
    }
    return maxDiff;
}