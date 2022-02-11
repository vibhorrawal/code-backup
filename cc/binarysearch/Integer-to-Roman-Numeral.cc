// O(N) time 
// easy peesy
string solve(int n) {
    unordered_map<int,string> mp = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string res;
    for(int it : {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}){
        while(n >= it) {
            res += mp[it];
            n -= it;
        }
    }
    return res;
}