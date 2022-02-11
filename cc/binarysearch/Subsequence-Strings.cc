// O(N) time | O(1) space
bool solve(string s1, string s2) {
    int i = 0, j = 0;
    for(int j = 0; j < s2.size(); j++){
        if(s1[i] == s2[j])
            i++;
    }
    return i == s1.size();
}