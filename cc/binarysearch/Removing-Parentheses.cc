// O(N) time | O(1) space
int solve(string s) {
    int open = 0, count = 0;
    for (char c : s) {
        if (c == '(') {
            open++;
        } else {
            open--;
            if (open < 0) {
                count++;
                open = 0;
            }
        }
    }
    return open + count;
}