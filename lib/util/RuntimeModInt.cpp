/*
 * @title RuntimeModInt
 * @docs md/util/RuntimeModInt.md
 */
template<long long& mod> class RuntimeModInt {
public:
    long long x;
    constexpr RuntimeModInt():x(0) {}
    constexpr RuntimeModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}
    RuntimeModInt &operator+=(const RuntimeModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}
    RuntimeModInt &operator+=(const long long y) {RuntimeModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}
    RuntimeModInt &operator+=(const int y) {RuntimeModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}
    RuntimeModInt &operator-=(const RuntimeModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}
    RuntimeModInt &operator-=(const long long y) {RuntimeModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}
    RuntimeModInt &operator-=(const int y) {RuntimeModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}
    RuntimeModInt &operator*=(const RuntimeModInt &p) {x = (x * p.x % mod);return *this;}
    RuntimeModInt &operator*=(const long long y) {RuntimeModInt p(y);x = (x * p.x % mod);return *this;}
    RuntimeModInt &operator*=(const int y) {RuntimeModInt p(y);x = (x * p.x % mod);return *this;}
    RuntimeModInt &operator^=(const RuntimeModInt &p) {x = (x ^ p.x) % mod;return *this;}
    RuntimeModInt &operator^=(const long long y) {RuntimeModInt p(y);x = (x ^ p.x) % mod;return *this;}
    RuntimeModInt &operator^=(const int y) {RuntimeModInt p(y);x = (x ^ p.x) % mod;return *this;}
    RuntimeModInt &operator/=(const RuntimeModInt &p) {*this *= p.inv();return *this;}
    RuntimeModInt &operator/=(const long long y) {RuntimeModInt p(y);*this *= p.inv();return *this;}
    RuntimeModInt &operator/=(const int y) {RuntimeModInt p(y);*this *= p.inv();return *this;}
    RuntimeModInt operator=(const int y) {RuntimeModInt p(y);*this = p;return *this;}
    RuntimeModInt operator=(const long long y) {RuntimeModInt p(y);*this = p;return *this;}
    RuntimeModInt operator-() const {return RuntimeModInt(-x); }
    RuntimeModInt operator++() {x++;if(x>=mod) x-=mod;return *this;}
    RuntimeModInt operator--() {x--;if(x<0) x+=mod;return *this;}
    RuntimeModInt operator+(const RuntimeModInt &p) const { return RuntimeModInt(*this) += p; }
    RuntimeModInt operator-(const RuntimeModInt &p) const { return RuntimeModInt(*this) -= p; }
    RuntimeModInt operator*(const RuntimeModInt &p) const { return RuntimeModInt(*this) *= p; }
    RuntimeModInt operator/(const RuntimeModInt &p) const { return RuntimeModInt(*this) /= p; }
    RuntimeModInt operator^(const RuntimeModInt &p) const { return RuntimeModInt(*this) ^= p; }
    bool operator==(const RuntimeModInt &p) const { return x == p.x; }
    bool operator!=(const RuntimeModInt &p) const { return x != p.x; }
    RuntimeModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return RuntimeModInt(u);}
    RuntimeModInt pow(long long n) const {RuntimeModInt ret(1), mul(x);for(;n > 0;mul *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}
    friend ostream &operator<<(ostream &os, const RuntimeModInt &p) {return os << p.x;}
    friend istream &operator>>(istream &is, RuntimeModInt &a) {long long t;is >> t;a = RuntimeModInt<mod>(t);return (is);}
};
long long mod;
using modint = RuntimeModInt<mod>;