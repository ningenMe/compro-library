/*
 * @title GcdConvolution - 添字gcd畳み込み
 * @docs md/math/GcdConvolution.md
 */
class GcdConvolution {
    inline static vector<int> primes;
    inline static vector<int> eratosthenes(int N) {
        vector<int> sieve(N+1,1),primes;
        sieve[0]=sieve[1]=0;
        for(int i=1; i <= N/i; ++i) if(sieve[i]) for(int j=2*i;j<=N;j+=i) sieve[j]=0;
        for(int i=1; i <= N  ; ++i) if(sieve[i]) primes.push_back(i);
        return primes;
    };
    template<class T> inline static void zeta(vector<T>& v) {
        assert(v.size());
        int N = v.size();
        for(const int& p:primes) for(int i=(N-1)/p; i; --i) v[i] += v[i*p];
    }
    template<class T> inline static void mobius(vector<T>& v) {
        assert(v.size());
        int N = v.size();
        for(const int& p:primes) for(int i=1; i*p<N; ++i) v[i] -= v[i*p];
    }
public:
    template<class T> inline static vector<T> convolution(const vector<T>& a,const vector<T>& b) {
        int N = max(a.size(),b.size());
        vector<T> f(N,0),g(N,0);
        for(int i=0;i<N;++i) f[i] = a[i];
        for(int i=0;i<N;++i) g[i] = b[i];
        if(primes.empty()) primes = eratosthenes(N);
        zeta(f);zeta(g);
        for(int i=0;i<N;++i) f[i] = f[i]*g[i];
        mobius(f);
        return f;
    } 
};