template <long long mod> class MontmortNumber{
    vector<long long> res;
public:
    MontmortNumber(long long N):res(N+1,0) {
        if(N>=2) res[2]=1;
        for(int i = 3; i <= N; ++i) res[i]=(i-1)*((res[i-1]+res[i-2])%mod) % mod;
    }
	inline long long num(int N) {
		return res[N];
	}   
};