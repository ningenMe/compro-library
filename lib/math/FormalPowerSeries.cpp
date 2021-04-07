/*
 * @title FormalPowerSeries - 形式的冪級数
 * @docs md/math/FormalPowerSeries.md
 */
template<class T> struct FormalPowerSeries : public vector<T> {
    using vector<T>::vector;
    using Mint  = T;
    using Fps   = FormalPowerSeries<T>;
    inline static constexpr int N_MAX = 500000;
public:
    //a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1)
    FormalPowerSeries(vector<Mint> v){*this=FormalPowerSeries(v.size());for(int i=0;i<v.size();++i) (*this)[i]=v[i];}
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

    Fps operator+(const Fps& r) const { return Fps(*this) += r; }
    Fps &operator+=(const Fps& r) {if(r.size() > this->size()) this->resize(r.size());for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];return *this;}
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
    Fps even(void) const {Fps ret;for(int i = 0; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
    Fps odd(void)  const {Fps ret;for(int i = 1; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
    Fps symmetry(void) const {Fps ret(this->size());for(int i = 0; i < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}
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


    Fps pow(long long k,size_t n) const {
        Fps ret(n,0);
        for(size_t i=0; i < min(n,this->size()) && i*k < n; ++i) {
            if((*this)[i].x == 0) continue;
            Mint t0=(*this)[i], t0_inv=t0.inv();
            Fps tmp(n-i);for(int j=i;j<min(n,this->size()); ++j) tmp[j-i]=(*this)[j]*t0_inv;
            tmp = (tmp.log(n)*k).exp(n)*(t0.pow(k));
            for(int j=0;j+i*k<n;++j) ret[j+i*k] = tmp[j];
            break;
        }
        return ret;
    }
    Fps pow(long long k) const {return pow(k,this->size());}
    Fps exp(size_t n) const {Fps ret(1,1);for(size_t i=1;i<n;i<<=1) ret = (ret*(this->prefix(i<<1) + Fps(1,1) - ret.log(i<<1))).prefix(i<<1);return ret.prefix(n);}
    Fps exp(void) const {return exp(this->size());}
    Mint sub(Mint x) const {Mint base = 1,ret = 0; for(size_t i=0;i<this->size(); ++i,base *= x) ret += base*(*this)[i]; return ret;}
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
        return NumberTheoreticalTransform<Mint>::convolution(lhs,rhs);
    }
    inline static Mint nth_term_impl(long long n, Fps numerator,Fps denominator) {
        while(n) {
            numerator   *= denominator.symmetry();
            numerator    = ((n&1)?numerator.odd():numerator.even());
            denominator *= denominator.symmetry();
            denominator  = denominator.even();
            n >>= 1;
        }
        return numerator[0];
    }

    friend ostream &operator<<(ostream &os, const Fps& fps) {os << "{" << fps[0];for(int i=1;i<fps.size();++i) os << ", " << fps[i];return os << "}";}
};
//using fps = FormalPowerSeries<RuntimeModInt<mod>>;
//using fps = FormalPowerSeries<ModInt<MOD>>;