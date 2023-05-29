/*
 * @title NumberTheoreticalTransform - 数論変換
 * @docs md/convolution/NumberTheoreticalTransform.md
 */
template<long long mod> class NumberTheoreticalTransform {
    inline static constexpr int prime_1004535809 =1004535809;
    inline static constexpr int prime_998244353  =998244353;
    inline static constexpr int prime_985661441  =985661441;
    inline static constexpr int prime_998244353_1004535809 = ModInt<prime_998244353>(prime_1004535809).inv().x;
    inline static constexpr int prime_985661441_1004535809 = ModInt<prime_985661441>(prime_1004535809).inv().x;
    inline static constexpr int prime_985661441_998244353 = ModInt<prime_985661441>(prime_998244353).inv().x;
    inline static constexpr long long prime12=((long long)prime_1004535809) * prime_998244353;
    inline static constexpr int log2n_max = 21;
    template<int prime> inline static constexpr array<ModInt<prime>,log2n_max> get_pow2_inv() {
        array<ModInt<prime>,log2n_max>  ar;
        ModInt<prime> v=1; ar[0]=v;
        for(int i=1;i<log2n_max;++i) ar[i]=ar[i-1]/2;
        return ar;
    }
    inline static constexpr array<ModInt<prime_1004535809>,log2n_max> pow2_inv_1004535809 = get_pow2_inv<prime_1004535809>();
    inline static constexpr array<ModInt<prime_998244353>, log2n_max> pow2_inv_998244353  = get_pow2_inv<prime_998244353>();
    inline static constexpr array<ModInt<prime_985661441>, log2n_max> pow2_inv_985661441  = get_pow2_inv<prime_985661441>();

    template<int prime> inline static constexpr array<ModInt<prime>,log2n_max> get_base(int inv=0) {
        array<ModInt<prime>,log2n_max> base, es, ies;
        //TODO 3のハードコーディングを直す
        ModInt<prime> e = ModInt<prime>(3).pow((prime - 1) >> log2n_max), ie = e.inv();
        for (int i = log2n_max; i >= 2; --i) {
            es[i - 2]  = e, ies[i - 2] = ie;
            e *= e, ie *= ie;
        }
        ModInt<prime> acc = 1;
        if(!inv) {
            for (int i = 0; i < log2n_max - 2; ++i) {
                base[i] = es[i] * acc;
                acc *= ies[i];
            }
        }
        else {
            for (int i = 0; i < log2n_max - 2; ++i) {
                base[i] = ies[i] * acc;
                acc *= es[i];
            }
        }
        return base;
    }
    inline static constexpr array<ModInt<prime_1004535809>,log2n_max> base_1004535809=get_base<prime_1004535809>();
    inline static constexpr array<ModInt<prime_1004535809>,log2n_max> ibase_1004535809=get_base<prime_1004535809>(1);
    inline static constexpr array<ModInt<prime_998244353>,log2n_max> base_998244353=get_base<prime_998244353>();
    inline static constexpr array<ModInt<prime_998244353>,log2n_max> ibase_998244353=get_base<prime_998244353>(1);
    inline static constexpr array<ModInt<prime_985661441>,log2n_max> base_985661441=get_base<prime_985661441>();
    inline static constexpr array<ModInt<prime_985661441>,log2n_max> ibase_985661441=get_base<prime_985661441>(1);

    using Mint1 = ModInt<prime_1004535809>;
    using Mint2 = ModInt<prime_998244353>;
    using Mint3 = ModInt<prime_985661441>;
    inline static ModInt<mod> garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2 t2 = (b2-b1.x)*prime_998244353_1004535809;Mint3 t3 = ((b3-b1.x)*prime_985661441_1004535809-t2.x)*prime_985661441_998244353;return ModInt<mod>(ModInt<mod>(prime12)*t3.x+b1.x+prime_1004535809*t2.x);}

    template<long long prime> inline static void butterfly(vector<ModInt<prime>>& a, const array<ModInt<prime>,log2n_max>& base) {
        int h = __builtin_ctz(a.size());
        for (int i = 0; i < h; i++) {
            int w = 1 << i, p = 1 << (h - (i+1));
            ModInt<prime> acc = 1;
            for (unsigned int s = 0; s < w; s++) {
                int offset = s << (h - i);
                for (int j = 0; j < p; ++j) {
                    auto l = a[j + offset];
                    auto r = a[j + offset + p] * acc;
                    a[j + offset] = l + r;
                    a[j + offset + p] = l - r;
                }
                acc *= base[__builtin_ctz(~s)];
            }
        }
    }
    template<long long prime> inline static void ibutterfly(vector<ModInt<prime>>& a, const array<ModInt<prime>,log2n_max>& base) {
        int h = __builtin_ctz(a.size());
        for (int i = h-1; 0 <= i; i--) {
            int w = 1 << i, p = 1 << (h - (i+1));
            ModInt<prime> acc = 1;
            for (unsigned int s = 0; s < w; s++) {
                int offset = s << (h - i);
                for (int j = 0; j < p; ++j) {
                    auto l = a[j + offset];
                    auto r = a[j + offset + p];
                    a[j + offset] = l + r;
                    a[j + offset + p] = (l - r) * acc;
                }
                acc *= base[__builtin_ctz(~s)];
            }
        }
    }
    template<long long prime> inline static vector<ModInt<prime>> convolution_friendrymod(
        const vector<ModInt<mod>>& a,
        const vector<ModInt<mod>>& b,
        const array<ModInt<prime>,log2n_max>& base,
        const array<ModInt<prime>,log2n_max>& ibase,
        const array<ModInt<prime>,log2n_max>& pow2_inv
    ){
        int n = a.size(), m = b.size();
        if (!n || !m) return {};
        if (min(n, m) <= 60) {
            vector<ModInt<prime>> f(n+m-1);
            if (n >= m) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) f[i+j]+=a[i].x*b[j].x;
            else for (int j = 0; j < m; j++) for (int i = 0; i < n; i++) f[i+j]+=a[i].x*b[j].x;
            return f;
        }

        int N,L,M=n+m-1; for(N=1,L=0;N<M;N*=2,++L);
        ModInt<prime> inverse = pow2_inv[L];
        vector<ModInt<prime>> g(N,0),h(N,0);
        for(int i=0;i<a.size();++i) g[i]=a[i].x;
        for(int i=0;i<b.size();++i) h[i]=b[i].x;

        butterfly<prime>(g,base);
        butterfly<prime>(h,base);
        for(int i = 0; i < N; ++i) g[i] *= h[i];
        ibutterfly<prime>(g,ibase);
        for (int i = 0; i < n + m - 1; i++) g[i] *= inverse;
        return g;
    }
    template<long long prime, long long ZZ> class Inner {
    public:
        inline static vector<ModInt<prime>> convolution_impl(const vector<ModInt<mod>>& g,const vector<ModInt<mod>>& h){
            auto f1 = convolution_friendrymod<prime_1004535809>(g, h, base_1004535809, ibase_1004535809, pow2_inv_1004535809);
            auto f2 = convolution_friendrymod<prime_998244353> (g, h, base_998244353,  ibase_998244353,  pow2_inv_998244353);
            auto f3 = convolution_friendrymod<prime_985661441> (g, h, base_985661441,  ibase_985661441,  pow2_inv_985661441);

            vector<ModInt<prime>> f(f1.size());
            for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);
            return f;
        }
    };
    template<long long prime> class Inner<prime, prime_998244353> {
    public:
        inline static vector<ModInt<prime>> convolution_impl(const vector<ModInt<mod>>& g,const vector<ModInt<mod>>& h) { 
            return convolution_friendrymod<prime>(g,h,base_998244353,ibase_998244353,pow2_inv_998244353);
        }
    }; 
public:
    inline static vector<ModInt<mod>> convolution(const vector<ModInt<mod>>& g,const vector<ModInt<mod>>& h){return Inner<mod,mod>::convolution_impl(g,h);}
};