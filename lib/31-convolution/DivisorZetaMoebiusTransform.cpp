/*
 * @title DivisorZetaMoebiusTransform - 約数のゼータ・メビウス変換 (gcd/lcm畳み込み)
 * @docs md/math/DivisorZetaMoebiusTransform.md
 */
class DivisorZetaMoebiusTransform {
    template<class T> inline static void zeta_multiple(vector<T>& v, const Eratosthenes& eratosthenes) {
        assert(v.size()); int N = v.size();
        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) v[i] += v[i*p];
    }
    template<class T> inline static void mobius_multiple(vector<T>& v, const Eratosthenes& eratosthenes) {
        assert(v.size()); int N = v.size();
        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) v[i] -= v[i*p];
    }
    template<class T> inline static void zeta_divisor(vector<T>& v, const Eratosthenes& eratosthenes) {
        assert(v.size()); int N = v.size();
        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) {v[i*p] += v[i];}
    }
    template<class T> inline static void mobius_divisor(vector<T>& v, const Eratosthenes& eratosthenes) {
        assert(v.size()); int N = v.size();
        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) {v[i*p] -= v[i];}
    }
public:
    template<class T> inline static vector<T> gcd_convolution(const vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {
        int N = max(a.size(),b.size());
        assert(N <= eratosthenes.size());
        vector<T> f(N,0),g(N,0);
        for(int i=0;i<N;++i) f[i] = a[i];
        for(int i=0;i<N;++i) g[i] = b[i];
        zeta_multiple(f,eratosthenes);zeta_multiple(g,eratosthenes);
        for(int i=0;i<N;++i) f[i] = f[i]*g[i];
        mobius_multiple(f,eratosthenes);
        return f;
    }
    template<class T> inline static vector<T> lcm_convolution(const vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {
        int N = max(a.size(),b.size());
        assert(N <= eratosthenes.size());
        vector<T> f(N,0),g(N,0);
        for(int i=0;i<N;++i) f[i] = a[i];
        for(int i=0;i<N;++i) g[i] = b[i];
        zeta_divisor(f,eratosthenes);zeta_divisor(g,eratosthenes);
        for(int i=0;i<N;++i) f[i] = f[i]*g[i];
        mobius_divisor(f,eratosthenes);
        return f;
    }
};