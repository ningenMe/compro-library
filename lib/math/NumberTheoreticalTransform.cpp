/*
 * @title NumberTheoreticalTransform - 数論変換
 * @docs md/math/NumberTheoreticalTransform.md
 */
template<class T> class NumberTheoreticalTransform {
    inline static constexpr int prime1 =1004535809;
    inline static constexpr int prime2 =998244353;
    inline static constexpr int prime3 =985661441;
    inline static constexpr int inv21  =332747959; // ModInt<mod2>(mod1).inv().x;
    inline static constexpr int inv31  =766625513; // ModInt<mod3>(mod1).inv().x;
    inline static constexpr int inv32  =657107549; // ModInt<mod3>(mod2).inv().x;
    inline static constexpr long long prime12=(1002772198720536577LL);
    inline static constexpr int log2n_max = 21;
    using Mint  = T;
    using Mint1 = ModInt<prime1>;
    using Mint2 = ModInt<prime2>;
    using Mint3 = ModInt<prime3>;
    inline static Mint garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2 t2 = (b2-b1.x)*inv21;Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return Mint(Mint(prime12)*t3.x+b1.x+prime1*t2.x);}
    template<int prime> inline static array<ModInt<prime>,log2n_max> get_base(int inv=0) {
        array<ModInt<prime>,log2n_max> base, es, ies;
        ModInt<prime> e = ModInt<prime>(3).pow((prime - 1) >> log2n_max), ie = e.inv();
        for (int i = log2n_max; i >= 2; --i) {
            es[i - 2]  = e, ies[i - 2] = ie;
            e *= e, ie *= ie;
        }
        ModInt<prime> acc = 1;
        if(!inv) for (int i = 0; i < log2n_max - 2; ++i) {
                base[i] = es[i] * acc;
                acc *= ies[i];
            }
        else for (int i = 0; i < log2n_max - 2; ++i) {
                base[i] = ies[i] * acc;
                acc *= es[i];
            }
        return base;
    }
    template<int prime> inline static void butterfly(vector<ModInt<prime>>& a, const array<ModInt<prime>,log2n_max>& base) {
        int h = __builtin_ctz(a.size());
        for (int i = 0; i < h; i++) {
            int w = 1 << i, p = 1 << (h - (i+1));
            ModInt<prime> acc = 1;
            for (int s = 0; s < w; s++) {
                int offset = s << (h - i);
                for (int j = 0; j < p; ++j) {
                    auto l = a[j + offset];
                    auto r = a[j + offset + p] * acc;
                    a[j + offset] = l + r;
                    a[j + offset + p] = l - r;
                }
                acc *= base[__builtin_ctz(~(unsigned int)(s))];
            }
        }
    }
    template<int prime> inline static void ibutterfly(vector<ModInt<prime>>& a, const array<ModInt<prime>,log2n_max>& base) {
        int h = __builtin_ctz(a.size());
        for (int i = h-1; 0 <= i; i--) {
            int w = 1 << i, p = 1 << (h - (i+1));
            ModInt<prime> acc = 1;
            for (int s = 0; s < w; s++) {
                int offset = s << (h - i);
                for (int j = 0; j < p; ++j) {
                    auto l = a[j + offset];
                    auto r = a[j + offset + p];
                    a[j + offset] = l + r;
                    a[j + offset + p] = (l - r) * acc;
                }
                acc *= base[__builtin_ctz(~(unsigned int)(s))];
            }
        }
    }
    template<int prime> inline static vector<ModInt<prime>> convolution_friendrymod(vector<Mint> a,vector<Mint> b){
        int n = a.size(), m = b.size();
        if (!n || !m) return {};
        if (min(n, m) <= 60) {
            if (n < m) swap(n, m),swap(a, b);
            vector<ModInt<prime>> f(n+m-1);
            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) f[i+j]+=a[i].x*b[j].x;
            return f;
        }

        int N,M=n+m-1; for(N=1;N<M;N*=2);
        ModInt<prime> inverse(N); inverse = inverse.inv();
        vector<ModInt<prime>> g(N,0),h(N,0);
        for(int i=0;i<a.size();++i) g[i]=a[i].x;
        for(int i=0;i<b.size();++i) h[i]=b[i].x;

        static array<ModInt<prime>,log2n_max> base;
        if(!base.front().x) base = get_base<prime>();
        static array<ModInt<prime>,log2n_max> ibase;
        if(!ibase.front().x) ibase = get_base<prime>(1);

        butterfly<prime>(g,base);
        butterfly<prime>(h,base);
        for(int i = 0; i < N; ++i) g[i] *= h[i];
        ibutterfly<prime>(g,ibase);
        for (int i = 0; i < n + m - 1; i++) g[i] *= inverse;
        return g;
    }
    inline static vector<Mint> convolution_arbitrarymod(const vector<Mint>& g,const vector<Mint>& h){
        auto f1 = convolution_friendrymod<prime1>(g, h);
        auto f2 = convolution_friendrymod<prime2>(g, h);
        auto f3 = convolution_friendrymod<prime3>(g, h);

        vector<Mint> f(f1.size());
        for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);
        return f;
    }
public:
    inline static vector<long long> convolution(const vector<long long>& g,const vector<long long>& h) {
        vector<T> a(g.size()),b(h.size());
        for(int i=0;i<a.size();++i) a[i]=T(g[i]);
        for(int i=0;i<b.size();++i) b[i]=T(h[i]);
        auto f1 = convolution_friendrymod<prime1>(a, b);
        auto f2 = convolution_friendrymod<prime2>(a, b);
        auto f3 = convolution_friendrymod<prime3>(a, b);
        vector<long long> f(f1.size());
        for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]).x;
        return f;
    }
    inline static vector<ModInt<998244353>> convolution(const vector<ModInt<998244353>>& g,const vector<ModInt<998244353>>& h){return convolution_friendrymod<998244353>(g,h);}
    inline static vector<ModInt<1000000007>> convolution(const vector<ModInt<1000000007>>& g,const vector<ModInt<1000000007>>& h){return convolution_arbitrarymod(g,h);}
    // inline vector<RuntimeModInt<runtime_mod>> convolution(const vector<RuntimeModInt<runtime_mod>>& g,const vector<RuntimeModInt<runtime_mod>>& h){return convolution_arbitrarymod(g,h);}
};