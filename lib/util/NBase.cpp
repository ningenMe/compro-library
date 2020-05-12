/*
 * @title NBase
 */
class NBase{
public:
	inline static vector<long long> translate(long long X,long long N) {
		assert(abs(N)>1);
		vector<long long> res;
		while(1) {
			long long b = (X%abs(N)+abs(N)) % abs(N);
			res.push_back(b);
			(X -= b) /= N;
			if(X==0) break;
		}
		return res;
	}
	//Digit Sum
	inline static constexpr long long digit_sum(long long N, long long K) {
		long long sum = 0;
		for (; N > 0; N /= K) sum += N % K;
		return sum;
	}
};
