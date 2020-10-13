// O(n*log(log(n))) time | O(n) space
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(prime[i] == false)
                continue;
            for(int j = i; j*i < n; j++){
                prime[j*i] = false;
            }
        }
        int count = 0;
        for(bool p : prime)
            if(p) count++;
        return count;
    }
};
