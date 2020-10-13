
// O(log(n)) time | O(1) space
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if(x < 0){
            isNeg = true;
            x = -x;
        }
        string num = to_string(x);
        std::reverse(num.begin(), num.end());
        return std::stoi(num) * pow(-1, isNeg);
    }
};
