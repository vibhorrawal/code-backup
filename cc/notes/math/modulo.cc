const int MOD = 1e9+7;

long long add(long long A, long long B){
  return (A + B) % MOD;
}

long long subtract(long long A, long long B){
  A = (A - B) % MOD;
  if(A < 0) A += MOD;
  return A;
}

long long mul(long long A, long long B){
  return ((A % MOD) * (B % MOD)) % MOD;
}

// euler's theorm for division, here P is a prime
long long div(long long A, long long B){
  return A * power(b, P-2) * % P;
}
