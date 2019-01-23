#include <bits/stdc++.h>
using namespace std;

//Pow_Mod O(log(n))
long long Pow_Mod(long long x, long long n, long long mod) {
    long long res = 1;
    for (; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;
    return res;
}

//Inv_Mod O(log(mod))
long long Inv_Mod(long long x, long long mod){
	return Pow_Mod(x,mod-2,mod); 
}
