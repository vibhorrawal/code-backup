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


// O(1) using math
int solve(int n, int e, int o, int t) {
    double odd = (1 + o/100.0);
    double even = (1 + e/100.0);
    double target = double(t)/n;
    if(t <= n) return 0;
    // let's package in 2 yrs
    double packed_odd_even = odd * even;
    int yrs_2 = floor(log(target) / log(packed_odd_even));
    double acheived_target = pow(packed_odd_even, yrs_2);
    int total_years = yrs_2 * 2;
    
    double value = n * acheived_target; 
    if(t <= value) return total_years;

    value *= even;
    if(t <= value) return total_years + 1;

    value *= odd;
    if(t <= value) return total_years + 2;
    return -1;
}