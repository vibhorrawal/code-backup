// O(N) time | O(1) space
class Solution {
public:
    int maxPower(string s) {
        int power = 0, maxpower = 0, curr = '#';
        for(char c : s){
            if(c == curr) power++;
            else curr = c, power = 1;
            maxpower = max(power, maxpower);
        }
        return maxpower;
    }
};
