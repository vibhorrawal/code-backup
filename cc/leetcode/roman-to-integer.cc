// O(n) time | O(1) space
class Solution {
public:
    int romanToInt(string s) {
        int number = 0, i = 0;
        map<char, int> roman = {{'M' , 1000},
                                {'D', 500},
                                {'C', 100},
                                {'L', 50},
                                {'X', 10},
                                {'V', 5},
                                {'I', 1}};

        for(; i < s.size() - 1; i++){
            if(roman[s[i]] < roman[s[i+1]])
                number -= roman[s[i]];
            else
                number += roman[s[i]];
        }
        number += roman[s[i]];
        return number;
    }
};
