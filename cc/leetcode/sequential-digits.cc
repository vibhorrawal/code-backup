class Solution {
    set<int> res;
    int low, high;
    void rec(int num){
        if(num > high)
            return;
        if(low <= num && num <= high)
            res.insert(num);
    
        int last_digit = num % 10;
        if(last_digit < 9){
            int n1 = num * 10 + last_digit + 1;
            rec(n1);
        }
        
        int n2 = num;
        if(n2 % 10 == 9)
            return;
        int pos = 0;
        while(n2){
            n2 = n2 / 10;
            pos++;
        }
        n2 = num;
        while(pos){
            n2 += pow(10, pos-1);
            pos--;
        }
        rec(n2);
    }
public:
    vector<int> sequentialDigits(int l, int h) {
        low = l, high = h;
        int n = 1, digit = 2;
        rec(n);
        vector<int> ans(res.begin(), res.end());
        return ans;
    }
};
