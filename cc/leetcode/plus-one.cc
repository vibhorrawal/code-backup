// O(n) time | O(1) space
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int s = 0;
        int carry = 1, i = 0;
        while(i < digits.size() && carry){
            s = digits[i] + s + carry;
            carry = s / 10;
            s = s % 10;
            digits[i] = s;
            i++;
        }
        if(carry)
            digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
