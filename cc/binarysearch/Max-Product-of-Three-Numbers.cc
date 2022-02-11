// O(NLogN) time | O(1) space
int solve(vector<int>& a) {
    sort(a.begin(), a.end());
    if(a.size() == 3) return a[0] * a[1] * a[2];
    int n = a.size();
    return max({a[n-1] * a[n-2] * a[n-3], a[0] * a[1] * a[n-1]});
}

// O(N) time | O(1) space
int solve(vector<int>& nums) {
    const int INF = 1e9 + 7;
    int smallest = INF, secondSmallest = INF; // for -ve case (-ve * -ve * +ve)
    int largest = -INF, secondLargest = -INF, thirdLargest = -INF; // (+ve * +ve * +ve)
    for(int num : nums) {
        // larger
        if(num > largest) {
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = num;
        } else if(num > secondLargest) {
            thirdLargest = secondLargest;
            secondLargest = num;
        } else if(num > thirdLargest) {
            thirdLargest = num;
        }

        // smaller
        if(num < smallest) {
            secondSmallest = smallest;
            smallest = num;
        } else if(num < secondSmallest) {
            secondSmallest = num;
        }
    }
    return max(largest * secondLargest * thirdLargest, largest * smallest * secondSmallest);
}