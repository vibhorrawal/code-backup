// O(num_of_digits) time and space
int solve(int num, int k) {
    string v = to_string(num);
    long long mul = 1, res = 0, count0 = 0;
    for(int i = 0; i < k; i++){
        if(v[i] == '0') count0++;
        else mul *= v[i] - '0';
    }
    if(!count0) res = mul;
    for(int i = k; i < v.size(); i++){
        if(v[i-k] == '0') count0--;
        else mul /= v[i-k] - '0';
        if(v[i] == '0') count0++;
        else mul *= v[i] - '0';
        if(!count0) res = max(res, mul);
    }
    return res;
}
