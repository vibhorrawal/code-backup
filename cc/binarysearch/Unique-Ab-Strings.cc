// O(N) time | O(1) space
int solve(string s) {
    int countA = 1;
    for(char c : s) if(c == 'a') countA *= 2;
    return countA;
}
