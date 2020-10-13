// O(nlog(n)) time | O(n) space
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for(int num : nums)
            res.push_back(to_string(num));
        sort(res.begin(), res.end(), [](string a, string b){
            string x = a + b;
            string y = b + a;
            return x > y;
        });
        string number = ;
        for(string num : res)
            number += num;
        if(number[0] == '0')
            return 0;
        return number;
    }
};
