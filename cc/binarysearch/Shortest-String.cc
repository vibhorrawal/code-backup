int solve(string s) {
    int count1 = 0, count0 = 0;
    for(char c : s)
        if(c == '1') count1++;
        else count0++;
    return abs(count1 - count0);
}
