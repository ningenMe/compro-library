/*
 * @title FastFourierTransform - 高速フーリエ変換
 * @docs md/math/FastFourierTransform.md
 */
class FastFourierTransform {
    inline static constexpr int prime1 =1004535809;
    inline static constexpr int prime2 =998244353;
    inline static constexpr int prime3 =985661441;
    inline static constexpr int inv21  =332747959; // ModInt<mod2>(mod1).inv().x;
    inline static constexpr int inv31  =766625513; // ModInt<mod3>(mod1).inv().x;
    inline static constexpr int inv32  =657107549; // ModInt<mod3>(mod2).inv().x;
    inline static constexpr long long prime12=(1002772198720536577LL);
    inline static constexpr array<int,26> pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};
    using Mint1 = ModInt<prime1>;
    using Mint2 = ModInt<prime2>;
    using Mint3 = ModInt<prime3>;
    inline static long long garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2 t2 = (b2-b1.x)*inv21;Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return prime12*t3.x+b1.x+prime1*t2.x;}
    template<int prime> inline static void ntt(vector<ModInt<prime>>& f) {
        const int N = f.size(), M = N>>1;
        const int log2_N = __builtin_ctz(N);
        ModInt<prime> h(3);
        vector<ModInt<prime>> g(N),base(log2_N);
        for(int i=0;i<log2_N;++i) base[i] = h.pow((prime - 1)/pow2[i+1]);
        for(int n=0;n<log2_N;++n) {
            const int& p = pow2[log2_N-n-1];
            ModInt<prime> w = 1;
            for (int i=0,k=0;i<M;i+=p,k=i<<1,w*=base[n]) {
                for(int j=0;j<p;++j) {
                    ModInt<prime> l = f[k|j],r = w*f[k|j|p];
                    g[i|j]   = l + r;
                    g[i|j|M] = l - r;
                }
            }
            swap(f,g);
        }
    }
    template<int prime> inline static vector<ModInt<prime>> convolution_friendlymod(const vector<long long>& a,const vector<long long>& b){
        if (min(a.size(), b.size()) <= 60) {
            vector<ModInt<prime>> f(a.size() + b.size() - 1);
            for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) f[i+j]+=a[i]*b[j];
            return f;
        }
        int N,M=a.size()+b.size()-1; for(N=1;N<M;N*=2);
        ModInt<prime> inverse(N); inverse = inverse.inv();
        vector<ModInt<prime>> g(N,0),h(N,0);
        for(int i=0;i<a.size();++i) g[i]=a[i];
        for(int i=0;i<b.size();++i) h[i]=b[i];
        ntt<prime>(g); ntt<prime>(h);
        for(int i = 0; i < N; ++i) g[i] *= h[i]*inverse;
        reverse(g.begin()+1,g.end());
        ntt<prime>(g);
        return g;
    }
public:
    inline static vector<long long> convolution(const vector<long long>& g,const vector<long long>& h){
        auto f1 = convolution_friendlymod<prime1>(g, h);
        auto f2 = convolution_friendlymod<prime2>(g, h);
        auto f3 = convolution_friendlymod<prime3>(g, h);
        vector<long long> f(f1.size());
        for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);
        return f;
    }
};
