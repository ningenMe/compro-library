/*
 * @title FormalPowerSeries - 形式的冪級数
 * @docs md/polynomial/FormalPowerSeries.md
 */
template<long long prime, class T = ModInt<prime>> struct FormalPowerSeries;
template<long long prime, class T = ModInt<prime>> class SparseFormalPowerSeries {
    using Mint = T;
    using Sfps = SparseFormalPowerSeries<prime>;
    unordered_map<size_t, T> mp;
    size_t sz;
public:
    friend class FormalPowerSeries<prime>;
    SparseFormalPowerSeries():sz(0){}
    void update(const size_t idx, const Mint val) {
        if(val.x == 0) mp.erase(idx);
        else mp[idx]=val;
        size_t tmp_sz=0;
        for(auto& p:mp) tmp_sz=max(tmp_sz,p.first);
        sz=tmp_sz;
    }
    inline static Sfps mul(const Sfps& lhs, const Sfps& rhs) {
        unordered_map<size_t, T> ret;
        for(auto& [i,a]: lhs.mp) {
            for(auto& [j,b]: rhs.mp) {
                ret[i+j]+=a*b;
            }
        }
        return ret;
    }
    //mapのサイズじゃなくて、最大のindexを返すことに注意
    size_t size() const {return sz+1;}
};
template<long long prime, class T> struct FormalPowerSeries : public vector<T> {
    using vector<T>::vector;
    using Mint  = T;
    using Fps   = FormalPowerSeries<prime>;
    using Sfps   = SparseFormalPowerSeries<prime>;
    inline static constexpr int N_MAX = 1000000;
    Fps even(void) const {Fps ret;for(int i = 0; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
    Fps odd(void)  const {Fps ret;for(int i = 1; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
    Fps symmetry(void) const {Fps ret(this->size());for(int i = 0; i < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}
public:
    //a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1)
    FormalPowerSeries(const vector<Mint>& v){*this=FormalPowerSeries(v.size());for(int i=0;i<v.size();++i) (*this)[i]=v[i];}
    //TODO constexprにする
    inline static vector<Mint> invs;
    static void invs_build() {
        if(invs.size()) return;
        vector<Mint> fac(N_MAX+1,1),finv(N_MAX+1,1);
        invs.resize(N_MAX+1);
        for(int i=1;i<=N_MAX;i++) fac[i]=fac[i-1]*i;
        finv[N_MAX]=fac[N_MAX].inv();
        for(int i=N_MAX;i>=1;i--) finv[i-1]=finv[i]*i;
        for(int i=1;i<=N_MAX;i++) invs[i]=finv[i]*fac[i-1];
    }
    Fps operator*(const int r) const {return Fps(*this) *= r; }
    Fps &operator*=(const int r) {for(int i=0;i< this->size(); ++i) (*this)[i] *= r; return *this; }
    Fps operator*(const long long int r) const {return Fps(*this) *= r; }
    Fps &operator*=(const long long int r) {for(int i=0;i< this->size(); ++i) (*this)[i] *= r; return *this; }
    Fps operator*(const Mint r) const {return Fps(*this) *= r; }
    Fps &operator*=(const Mint r) {for(int i=0;i< this->size(); ++i) (*this)[i] *= r; return *this; }
    Fps operator/(const int r) const {return Fps(*this) /= r; }
    Fps &operator/=(const int r) {return (*this) *= Mint(r).inv(); }
    Fps operator+(const int r) const {return Fps(*this) += r; }
    Fps &operator+=(const int r) {for(int i=0;i< this->size(); ++i) (*this)[i] += r; return *this; }
    Fps operator-(void) const {return Fps(*this) *= (-1);}
    Fps operator-(const int r) const {return Fps(*this) -= r; }
    Fps &operator-=(const int r) {for(int i=0;i< this->size(); ++i) (*this)[i] -= r; return *this; }
    Fps prefix(size_t n) const {
        return Fps(this->begin(),this->begin()+min(n,this->size()));
    }
    Fps inv(size_t n) const {
        Fps ret({Mint(1)/(*this)[0]});
        for(size_t i=2,m=(n<<1);i < m; i<<=1) {
            Fps h = mul(mul(ret,ret),(this->prefix(i)));
            ret.resize(i);
            for(int j=i>>1;j<i;++j) ret[j] -= h[j];
        }
        return ret.prefix(n);
    }
    Fps inv(void) const {return inv(this->size());}
    Fps diff(void) const {
        Fps ret(max(0,int(this->size())-1));
        for(int i=0;i<ret.size(); ++i) ret[i]=(*this)[i+1]*(i+1);
        return ret;
    }
    Fps intg(size_t n) const {
        invs_build();
        Fps ret(min(this->size()+1,n));
        for(int i=1;i<ret.size(); ++i) ret[i]=(*this)[i-1]*invs[i];
        return ret;
    }
    Fps log(size_t n) const {
        return mul(this->diff(),this->inv(n)).intg(n);
    }
    Fps log(void) const {return log(this->size());}
    Fps exp(size_t n) const {
        Fps ret(1,1);
        for(size_t i=2,m=(n<<1);i<m;i<<=1) {
            Fps h = mul(ret,(sub(this->prefix(i),ret.log(i))));
            ret.resize(i);
            for(int j=i>>1;j<i;++j) ret[j] += h[j];
        }
        return ret.prefix(n);
    }
    Fps exp(void) const {return exp(this->size());}
    Fps pow(long long k,size_t n) const {
        Fps ret(n,0);
        for(size_t i=0,m = min(n,this->size()); i < m && i*k < n; ++i) {
            if((*this)[i].x == 0) continue;
            Mint t0=(*this)[i], t0_inv=t0.inv();
            Fps tmp(n-i);for(int j=i;j<m; ++j) tmp[j-i]=(*this)[j]*t0_inv;
            tmp = (tmp.log(n)*k).exp(n)*(t0.pow(k));
            for(int j=0;j+i*k<n;++j) ret[j+i*k] = tmp[j];
            break;
        }
        return ret;
    }
    Fps pow(long long k) const {return pow(k,this->size());}
    Mint eval(Mint x) const {
        Mint base = 1,ret = 0;
        for(size_t i=0;i<this->size();++i) {
            ret += (*this)[i]*base;
            base *= x;
        }
        return ret;
    }
    inline static Fps add(const Fps& lhs,const Fps& rhs) {
        size_t n = lhs.size(), m = rhs.size();
        Fps res(max(n,m),0);
        for(int i=0;i<n;++i) res[i] += lhs[i];
        for(int i=0;i<m;++i) res[i] += rhs[i];
        return res;
    }
    inline static Fps sub(const Fps& lhs,const Fps& rhs) {
        size_t n = lhs.size(), m = rhs.size();
        Fps res(max(n,m),0);
        for(int i=0;i<n;++i) res[i] += lhs[i];
        for(int i=0;i<m;++i) res[i] -= rhs[i];
        return res;
    }
    inline static Fps mul(const Fps& lhs, const Fps& rhs) {
        return NumberTheoreticalTransform<prime>::convolution(lhs,rhs);
    }
    inline static Fps mul(const Fps& lhs, const Sfps& rhs) {
        size_t n = lhs.size() + rhs.size();
        Fps res(n,0);
        for(auto& [i,a]:rhs.mp) {
            for (int j = 0; j < lhs.size(); ++j) res[i+j]+=a*lhs[j];
        }
        return res;
    }
    inline static Fps div(Fps lhs, Fps rhs) {
        while(lhs.size() && lhs.back().x == 0) lhs.pop_back();
        while(rhs.size() && rhs.back().x == 0) rhs.pop_back();
        int n = lhs.size(), m = rhs.size();
        if(n < m) return Fps(1,0);
        reverse(lhs.begin(),lhs.end());
        reverse(rhs.begin(),rhs.end());
        auto f = mul(lhs,rhs.inv(n-m+1)).prefix(n-m+1);
        reverse(f.begin(),f.end());
        return f;
    }
    inline static Fps mod(const Fps& lhs, const Fps& rhs) {
        int m = rhs.size();
        auto f = sub(lhs,mul(div(lhs,rhs).prefix(m),rhs)).prefix(m);
        while(f.size() && f.back().x==0) f.pop_back();
        return f;
    }
    inline static Fps fold_all(vector<Fps> vfps, size_t n=0) {
        if(vfps.empty()) return {};
        priority_queue<pair<size_t,size_t>, vector<pair<size_t,size_t>>, greater<>> pq;
        for(size_t i=0;i<vfps.size(); ++i) pq.emplace(vfps[i].size(), i);
        while(pq.size()>1) {
            auto l=pq.top().second; pq.pop();
            auto r=pq.top().second; pq.pop();
            vfps[l]=mul(vfps[l],vfps[r]);
            if(n) vfps[l].resize(n);
            vfps[r]={};
            pq.emplace(vfps[l].size(), l);
        }
        auto ret=pq.top().second; pq.pop();
        return vfps[ret];
    }
    vector<Mint> multipoint_evaluation(vector<Mint> x) {
        int n = x.size(),m;
        for(m=1;m<n;m<<=1);
        vector<Fps> f(2*m,Fps(1,1));
        for(int i=0;i<n;++i) f[i+m] = Fps({-x[i],1});
        for(int i=m-1;i;--i) f[i] = mul(f[(i<<1)|0],f[(i<<1)|1]);
        f[1] = mod(*this,f[1]);
        for(int i=2;i<m+n;++i) f[i] = mod(f[i>>1],f[i]);
        for(int i=0;i<n;++i)   x[i] = f[i+m][0];
        return x;
    }
    inline static Fps interpolation(const vector<Mint>& x,const vector<Mint>& y) {
        int n = x.size(),m;
        for(m=1;m<n;m<<=1);
        vector<Fps> f(2*m,Fps(1,1)),g(2*m);
        for(int i=0;i<n;++i) f[i+m] = Fps({-x[i],1});
        for(int i=m-1;i;--i) f[i] = mul(f[(i<<1)|0],f[(i<<1)|1]);
        g[1] = mod(f[1].diff(), f[1]);
        for(int i=2;i<m+n;++i) g[i] = mod(g[i>>1],f[i]);
        for(int i=0;i<n;++i) g[i+m] = Fps(1, y[i] / g[i+m][0]);
        for(int i=m-1;i;--i) g[i] = add(mul(g[(i<<1)|0],f[(i<<1)|1]),mul(f[(i<<1)|0],g[(i<<1)|1]));
        return g[1];
    }
    inline static Mint nth_term(long long n, Fps numerator,Fps denominator) {
        while(n) {
            numerator    = mul(numerator,denominator.symmetry());
            numerator    = ((n&1)?numerator.odd():numerator.even());
            denominator  = mul(denominator,denominator.symmetry());
            denominator  = denominator.even();
            n >>= 1;
        }
        return numerator[0];
    }
    //(1-rx)^(-n) = Σ (i+n-1)_C_(n-1) (rx)^i をm項まで計算して返してくれる
    inline static Fps negative_binomial_theorem(const Mint r, const size_t n, const size_t m, const CombinationMod<prime>& cm) {
        assert(n-1+m-1 <= cm.size());
        Fps res(m,0);
        for(int i=0;i<m;++i) {
            res[i]= Mint(cm.binom(i+n-1,n-1));
        }
        return res;
    }
    friend ostream &operator<<(ostream &os, const Fps& fps) {os << "{" << fps[0];for(int i=1;i<fps.size();++i) os << ", " << fps[i];return os << "}";}
};