// O(n) time | O(1) space
class Solution {
public:
    int myAtoi(string str) {
        long long num = 0;
        int i = 0;
        bool isNeg = false;
        while(str[i] == ' ') 
            i++;
        if(str[i] == '-'){
            i++;
            isNeg = true;
        }
        else if(str[i] == '+')
            i++;
        
        for(; i < str.size(); i++){
            char c = str[i];
            if(c < '0' || c > '9')
                return num;
            else num = num * 10 - (c - '0');
            if(num <= INT_MIN) return INT_MIN;
            if(num >= INT_MAX) return INT_MAX;
        }
        return num;
    }
};
