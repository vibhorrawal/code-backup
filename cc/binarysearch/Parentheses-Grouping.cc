vector<string> solve(string s) {
    string temp;
    vector<string> res;
    int count = 0;
    for(char c : s){
        if(c == '(') count++;
        else count--;
        temp += c;
        if(count == 0){
            res.push_back(temp);
            temp = "";
        }
    }
    return res;
}
