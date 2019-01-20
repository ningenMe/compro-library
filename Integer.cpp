#include <bits/stdc++.h>
using namespace std;

//Repeat Square Method x^n MOD O(log(N))
long long RSM(long long x, long long n, long long MOD) {
    long long y = 1;
    for (; n > 0; n >>= 1, (x *= x) %= MOD) if (n & 1) (y *= x) %= MOD;
    return y;
}

//Greatest Common Divisor O(log(N))
long long GCD(long long a, long long b) {
    return ((b == 0) ? a : GCD(b, a % b));
}

//Least Common Multiple O(log(N))
long long LCM(long long a, long long b) {
    return ((a*b == 0) ? 0 : (a / GCD(a, b)*b));
}

//extention Greatest Common Divisor O(log(N))
long long extGCD(long long a, long long b, long long &x, long long &y) {
	if (b == 0) return x = 1, y = 0, a;
    long long d = extGCD(b, a%b, y, x);
    return y -= a / b * x, d;
}	

//Prime Factorization O(sqrt(N))
vector<long long> PrimeFact(long long N) {
    vector<long long> ret;
    if (N == 1) ret.push_back(1);
    for (long long i = 2,M = N; i*i <= M; ++i) {
        if (N%i == 0) ret.push_back(i);
        while (N%i == 0) N /= i;
    }
    if (N != 1) ret.push_back(N);
    return ret;
}

//DigitSum O(log(N))
long long DigitSum(long long N, long long K) {
    long long sum = 0;
    for (; N > 0; N /= K) sum += N % K;
    return sum;
}

//Factorial O(N)
vector<long long> Factorial(long long N, long long mod) {
    vector<long long> res(N + 1, 1);
    for (long long i = 1; i <= N; ++i) res[i] = (res[i - 1] * i) % mod;
    return res;
}

//Permutation O(N^2) 
vector<vector<long long>> Permutation(long long N, long long mod) {
    vector<long long> fac(N + 1, 1);
    for (long long i = 1; i <= N; ++i) fac[i] = (fac[i - 1] * i) % mod;
    vector<long long> inv(N + 1, 1);
    for (long long i = 1; i <= N; ++i) inv[i] = RSM(fac[i], mod - 2, mod);
    vector<vector<long long>> res(N + 1, vector<long long>(N + 1, 1));
    for (long long i = 1; i <= N; ++i) for (long long j = 1; j <= i; ++j) res[i][j] = (fac[i] * inv[i - j]) % mod;
    return res;
}

int main(){
    
}