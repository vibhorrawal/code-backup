vector<bool> generate(int n){
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(!prime[i]) continue;
        for(int j = i * i; j <= n; j += i)
            prime[j] = false;
    }
    return prime;
}
bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
bool solve(int n) {
    int d = ceil(log10(n));
    // vector<bool> prime = generate(pow(10,d + 1));
    string num = to_string(n);
    for(int i = 0; i < num.size(); i++){
        string t = num.substr(i) + num.substr(0,i);
        if(!isPrime(stoi(t)))
            return false;
    }
    return true;
}


// cleaner
// O(N * sqrt(N)) time
bool isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
bool solve(int n) {
    string s = to_string(n);
    int d = s.size();
    while(d--) {
        if(not isPrime(stoi(s))) return false;
        s = s.back() + s.substr(0, s.size()-1);
    }
    return true;
}
