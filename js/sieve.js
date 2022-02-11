function findPrimes(N) {
    let sieve = Array(N).fill(true);
    let sqrt = Math.sqrt(N);

    for(let i = 2; i < sqrt; i++) {
        if(sieve[i]) {
            for(let j = i * i; j < N; j += i) {
                sieve[j] = false;
            }
        }
    }

    return sieve.map((flag, index) => flag ? index : false).filter(num => !!num).slice(1);
}

console.log(findPrimes(100))