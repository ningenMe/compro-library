/*
 * @title Prime
 */
class Prime{
	using int128 = __int128_t;
	inline static int miller_rabin64(const int128 N) {
		long long M = N - 1,L = 0;
		for (; !(M&1); M >>= 1,L++);
		for (int128 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
			if(a >= N) break;
			int128 r = 1;
			for (long long K=M; K>0; K>>=1, (a*=a) %= N) if(K&1) (r *= a) %= N;
			if (r == 1) continue;
			for (int j = 1; j < L && r != N - 1; j++) (r *= r) %= N;
			if (r != N - 1) return 0;
		}
		return 1;
	}
	inline static int miller_rabin32(const long long N) {
		long long M = N - 1,L = 0;
		for (; !(M&1); M >>= 1,L++);
		for (long long a: {2, 7, 61}) {
			if(a >= N) break;
			long long r = 1;
			for (long long K=M; K>0; K>>=1, (a*=a) %= N) if(K&1) (r *= a) %= N;
			if (r == 1) continue;
			for (int j = 1; j < L && r != N - 1; j++) (r *= r) %= N;
			if (r != N - 1) return 0;
		}
		return 1;
	}
public:
	inline static int is_prime(long long n) {
		if (n == 2 || n == 3) return 1;
		if (!(n&1) || n%3 == 0 || n <= 1) return 0;
		if (n < (1LL<<32)) return miller_rabin32(n);
		else return miller_rabin64(n);
	}
};
