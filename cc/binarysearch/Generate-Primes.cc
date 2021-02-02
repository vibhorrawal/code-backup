// O(n ^ 3/2) time
vector<int> solve(int n) {
    vector<int> prime;
    // prime.push_back(2);
    for(int p = 2; p <= n; p++){
        bool isprime = true;
        for(int i = 2; i*i <= p; i++){
            if(p % i == 0){
                isprime = false;
                break;
            }
        }
        if(isprime) prime.push_back(p);
    }
    return prime;
}

// Sieve of Eratosthenes 
vector<int> solve(int n) {
    vector<bool> isprime(n+1, true);
    vector<int> prime;
    for(int i = 2; i <= n; i++){
        if(not isprime[i]) continue;
        for(int j = i*i; j <= n; j+= i){
            isprime[j] = false;
        }
    }
    for(int p = 2; p <= n; p++)
        if(isprime[p])
            prime.push_back(p);
    return prime;
}
