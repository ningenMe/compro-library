/*
 * @title Mod
 * @docs md/util/Mod.md
 */
class Mod{
public:
	//Pow_Mod O(log(n))
	inline static long long pow(long long x, long long n, long long mod) {
		long long res = 1;
		for (x %= mod; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;
		return res;
	}
	//Inv_Mod O(log(mod))
	inline static long long inv(long long x, long long mod){
		return pow(x,mod-2,mod); 
	}
};