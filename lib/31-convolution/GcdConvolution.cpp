/*
 * @title GcdConvolution - 添字gcd畳み込み
 * @docs md/31-convolution/GcdConvolution.md
 */
class GcdConvolution {
    template<class T> inline static void zeta(vector<T>& v, const Eratosthenes& eratosthenes) {
        assert(v.size());
        int N = v.size();
        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) v[i] += v[i*p];
    }
    template<class T> inline static void mobius(vector<T>& v, const Eratosthenes& eratosthenes) {
        assert(v.size());
        int N = v.size();
        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) v[i] -= v[i*p];
    }
public:
    template<class T> inline static vector<T> convolution(const vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {
        int N = max(a.size(),b.size());
        assert(N <= eratosthenes.size());
        vector<T> f(N,0),g(N,0);
        for(int i=0;i<N;++i) f[i] = a[i];
        for(int i=0;i<N;++i) g[i] = b[i];
        zeta(f,eratosthenes);zeta(g,eratosthenes);
        for(int i=0;i<N;++i) f[i] = f[i]*g[i];
        mobius(f,eratosthenes);
        return f;
    }
};