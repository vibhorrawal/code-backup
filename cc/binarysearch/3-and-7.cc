// O(n) time | O(1) space
bool possible(int n){
    if(n == 0) return true;
    if(n < 0) return false;
    if(n % 3 == 0 || n % 7 == 0) return true;
    return possible(n-3) | possible(n-7);
}
bool solve(int n) {
    if(n % 3 == 0 || n % 7 == 0) return true;
    return possible(n);
}
