// O(N * 4^N) space time
map<char,vector<char>> mp;
void build(){
    mp['2'] = {'a','b','c'};
    mp['3'] = {'d','e','f'};
    mp['4'] = {'g','h','i'};
    mp['5'] = {'j','k','l'};
    mp['6'] = {'m','n','o'};
    mp['7'] = {'p','q','r','s'};
    mp['8'] = {'t','u','v'};
    mp['9'] = {'w','x','y','z'};
}
vector<string> solve(string digits) {
    build();
    vector<string> v;
    v.push_back("");
    for(int i = 0; i < digits.size(); i++){
        char d = digits[i];
        vector<string> t;
        for(string s : v){
            for(char c : mp[d]) 
            t.push_back(s + string(1,c));
        }
        v = t;
    }
    return v;
}

// shorter 
vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> solve(string digits) {
    if(digits.empty()) return {""}; 
    vector<string> v;
    for(char character : keypad[digits[0] - '0']) {
        for(string ans : solve(digits.substr(1))) {
            v.push_back(string(1, character) + ans);
        }
    }
    return v;
}