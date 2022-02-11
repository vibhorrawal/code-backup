function isPrime(n) {
    if(n <= 3) return n > 1;
    if(n % 2 == 0 || n % 3 == 0) return false;
    let sqrt_n = Math.sqrt(n);
    for(let i = 5; i < sqrt_n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) 
            return false;
    }
    return true;
}

// -- let's cache this using closure

let isPrime2 = (function isPrimeCached(){
    let cache = {};
    let solver = function(n){
        if(cache[n] == undefined){
            cache[n] = isPrime(n);
            console.log("Cached for", n);
        }
        return cache[n];
    }
    return solver;
})();

console.log(isPrime2(5));
console.log(isPrime2(5));
console.log(isPrime2(15));
console.log(isPrime2(15));


// -- caching inside calls

let factorial = (function IIFE() {
    let cache = {};

    function solver(n) {
        if(cache[n] != undefined) return cache[n];
        if(n < 2) return 1;
        console.log("Solving for", n);
        return cache[n] = n * solver(n-1);
    }
    return solver;
})();


console.log(factorial(5));
console.log(factorial(6));