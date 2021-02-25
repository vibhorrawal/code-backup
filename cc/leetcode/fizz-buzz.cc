// O(n) time | O(1) space
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++){
            string num = "";
            if(i % 3 == 0)
                num += Fizz;
            if(i % 5 == 0)
                num += Buzz;

            if(num == "")
                res.push_back(to_string(i));
            else
                res.push_back(num);
        }
        return res;
    }
};
