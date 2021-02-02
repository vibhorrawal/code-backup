// O(1) space and time 
double solve(int t, int p) {
    double drain_rate;
    double total_t;
    if(p > 20){
        drain_rate = (double) (100-p) / t;
    }
    else{
        int used20 = 20 - p;
        drain_rate = (double) (2 * used20 + 80) / t;
    }
    total_t = (80 / drain_rate) + 40 / (drain_rate);
    return total_t - t;
}
