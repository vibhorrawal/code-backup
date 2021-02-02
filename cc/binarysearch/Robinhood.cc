int solve(int nn, int ee, int oo, int tt) {
    int yr = 0, odd = 1;
    double n = nn, e = ee, o = oo, t = tt;
    while(n < t){
        if(odd){
            n = (n + (e/100)*n);
            odd = 0;
        }
        else{
            n = (n + (o/100) * n);
            odd = 1;
        }
        yr++;
    }
    return yr;
}

// same
int solve(int n, int e, int o, int t) {
    double principal = n, eyr = 1 + (double) e / 100, oyr = 1 + (double) o / 100;
    int years = 0;
    while(principal < t) {
        years++;
        if(years % 2) principal *= eyr;
        else principal *= oyr;
    }
    return years;
}
