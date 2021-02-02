// O(Inv(n!)) time | O(1) space
int solve(int a) {
    int res = 1;

    for(int i = 1; i < (1L<<31); i++) {
        res *= i;
        if(a == res) return i;
        if(a < res) return -1;
    }
    return -1;
}

// using 1,2,3....n division
int solve(int a) {
    int i = 1;
    while(a != 1){
        if(a % i) return -1;
        a /= i++;
    }
    return i-1;
}
