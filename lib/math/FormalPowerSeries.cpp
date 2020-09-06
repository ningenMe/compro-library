/*
 * @title FormalPowerSeries
 */
template<long long mod> class FormalPowerSeries{
    using Mint = ModInt<mod>;
    using Fps  = FormalPowerSeries<mod>;
    vector<Mint> ar;
    Fps even(void) const {Fps ret;for(int i = 0; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
    Fps odd(void)  const {Fps ret;for(int i = 1; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
    Fps minus_x(void) const {Fps ret(this->dimension());for(int i = 0; i < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}
public:
    //a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1) + a_n*x^n
    FormalPowerSeries(){}
    FormalPowerSeries(int n):ar(n+1,0){}
    FormalPowerSeries(int n,Mint a):ar(n+1,a){}
    FormalPowerSeries(const vector<Mint>& v):ar(v){}
    FormalPowerSeries(initializer_list<Mint> v):ar(v){}
    size_t size(void) const {return ar.size();}
    size_t dimension(void) const {return ar.size()-1;}
    Mint& operator[](size_t i) {return ar[i];}
    Mint operator[](size_t i) const {return ar[i];}
    void push_back(Mint a){ar.push_back(a);}
    void pop_back(void){ar.pop_back();}
    Fps operator*(const Fps& r) const { return Fps(*this) *= r; }
    Fps &operator*=(const Fps& r) {Fps ret((this->dimension())+r.dimension());for(int i=0;i<(this->size());++i) for(int j=0;j<r.size();++j) ret[i+j]+=((*this)[i])*r[j];return *this = ret;}
    Fps pow(long long n) const {Fps ret(0,1), mul(*this);for(;n > 0;mul *= mul,n >>= 1LL) if(n & 1LL) ret *= mul;return ret;}
    friend ostream &operator<<(ostream &os, const Fps& fps) {os << "{" << fps[0];for(int i=1;i<fps.size();++i) os << ", " << fps[i];return os << "}";}

    /**
     * O(log(n)*d*d)
     * fpsのn項目のみを求める。
     * @param n 求めたい項数
     * @param numerator 分子のfps
     * @param denominator 分母のfps
     * @see <a href="http://q.c.titech.ac.jp/docs/progs/polynomial_division.html">線形漸化式を満たす数列のN項目を計算するアルゴリズム</a>
     */
    static Mint nth_term(long long n, Fps numerator,Fps denominator) {
        while(n) {
            numerator   *= denominator.minus_x();
            if(n&1) numerator = numerator.odd();
            else    numerator = numerator.even();
            denominator *= denominator.minus_x();
            denominator  = denominator.even();
            n >>= 1;
        }
        return numerator[0];
    }
};