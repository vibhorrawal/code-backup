const int MOD = 1e9 + 7;
typedef long long ll;

// recursive power
ll powerRecur(ll A, ll B){
  if(B == 0) return 1;
  ll temp = powerRecur(A, B/2);
  ll result = temp * temp % MOD;
  if(B % 2 == 1) result = result * A % MOD;
  return result;
}

// iterative
ll power(ll A, ll B){
  ll result = 1;
  while(B > 0){
    if(B % 2 == 1) result = (result * A) % MOD;
    A = (A * A) % MOD;
    B /= 2;
  }
  return result;
}

// Euler: a^(p-1) = 1
// a^(p-2) = 1/a
ll inverse(ll a, ll p){
  return power(a, p-2); // also change MOD to P for power func
}
