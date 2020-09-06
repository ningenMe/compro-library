/*
 * @title NumberTheoreticTransform
 */
template<int mod,int root = 3> class NumberTheoreticTransform {
	inline static constexpr int prime1 =1004535809;
	inline static constexpr int prime2 =998244353;
	inline static constexpr int prime3 =985661441;
	inline static constexpr int inv21=332747959; // ModInt<mod2>(mod1).inv().x;
	inline static constexpr int inv31=766625513; // ModInt<mod3>(mod1).inv().x;
	inline static constexpr int inv32=657107549; // ModInt<mod3>(mod2).inv().x;
	inline static constexpr int prime12=(1002772198720536577LL) % mod;
	using Mint = ModInt<mod>;
	using Mint1 = ModInt<prime1>;
	using Mint2 = ModInt<prime2>;
	using Mint3 = ModInt<prime3>;
	inline Mint garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {
		Mint2 t2 = (b2-b1.x)*inv21;
		Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;
		return Mint(prime12*t3.x+b1.x+prime1*t2.x);
	}
	template<int prime> inline void ntt(vector<ModInt<prime>>& f,int sgn=1) {
		int N = f.size();
		ModInt<prime> h(root); h = h.pow((prime - 1) / N);
		if (sgn == -1) h = h.inv();

		for (int i = 0,j = 1; j < N - 1; ++j) {
			for (int k = N >> 1; k > (i ^= k); k >>= 1);
			if (j < i) swap(f[i], f[j]);
		}
		for (int i = 1,j = 2; i < N; i *= 2, j *= 2) {
			ModInt<prime> w = 1, base = h.pow(N/j);
			for(int k= 0;k < i; ++k, w*=base) {
				for (int l = k; l < N; l += j) {
					auto u = f[l];
					auto d = f[l + i] * w;
					f[l] = u + d;
					f[l + i] = u - d;
				}
			}
		}
	}
public:
	template<int prime=mod> inline vector<ModInt<prime>> convolution(const vector<long long>& a,const vector<long long>& b){
		int N; for(N=1;N<a.size()+b.size(); N*=2);
		vector<ModInt<prime>> f(N),g(N,0),h(N,0);
		for(int i=0;i<a.size();++i) g[i]=a[i];
		for(int i=0;i<b.size();++i) h[i]=b[i];
		ntt<prime>(g); ntt<prime>(h);
		for(int i = 0; i < N; ++i) f[i] = g[i]*h[i];
		ntt<prime>(f,-1);
		ModInt<prime> inverse(N); inverse = inverse.inv();
		for (auto& x : f) x = x * inverse;
		return f;
	}
	template<int prime=mod> inline vector<ModInt<prime>> convolution(const vector<Mint>& mg,const vector<Mint>& mh){
		vector<long long> g(mg.size()),h(mh.size());
		for(int i=0;i<g.size();++i) g[i]=mg[i].x;
		for(int i=0;i<h.size();++i) h[i]=mh[i].x;
		return convolution(g,h);
	}
	inline vector<Mint> convolution_arbitrarymod(const vector<Mint>& mg,const vector<Mint>& mh){
		vector<long long> g(mg.size()),h(mh.size());
		for(int i=0;i<g.size();++i) g[i]=mg[i].x;
		for(int i=0;i<h.size();++i) h[i]=mh[i].x;
		return convolution_arbitrarymod(g,h);
	}
	inline vector<Mint> convolution_arbitrarymod(vector<long long> g, vector<long long> h){
		auto x = convolution<prime1>(g, h);
		auto y = convolution<prime2>(g, h);
		auto z = convolution<prime3>(g, h);
		vector<Mint> res(x.size());
		for(int i=0; i < x.size(); ++i) res[i] = garner(x[i],y[i],z[i]);
		return res;
	}
};
