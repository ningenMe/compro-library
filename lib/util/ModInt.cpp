
template<long long mod> class ModInt {
public:
	long long x;
	constexpr ModInt():x(0) {
		// do nothing
	}
	constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {
		// do nothing
	}
	ModInt &operator+=(const ModInt &p) {
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator+=(const long long y) {
        ModInt p(y);
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator+=(const int y) {
        ModInt p(y);
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator-=(const ModInt &p) {
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator-=(const long long y) {
        ModInt p(y);
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator-=(const int y) {
        ModInt p(y);
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator*=(const ModInt &p) {
		x = (x * p.x % mod);
		return *this;
	}
	ModInt &operator*=(const long long y) {
        ModInt p(y);
		x = (x * p.x % mod);
		return *this;
	}
	ModInt &operator*=(const int y) {
        ModInt p(y);
		x = (x * p.x % mod);
		return *this;
	}
	ModInt &operator/=(const ModInt &p) {
		*this *= p.inv();
		return *this;
	}
	ModInt &operator/=(const long long y) {
        ModInt p(y);
		*this *= p.inv();
		return *this;
	}
	ModInt &operator/=(const int y) {
        ModInt p(y);
		*this *= p.inv();
		return *this;
	}
	ModInt operator=(const int y) {
        ModInt p(y);
        *this = p;
        return *this;
    }
    ModInt operator=(const long long y) {
        ModInt p(y);
		*this = p;
        return *this;
    }
	ModInt operator-() const { return ModInt(-x); }
	ModInt operator++() { 
        x++;
        if(x>=mod) x-=mod;
        return *this; 
    }
	ModInt operator--() { 
        x--;
        if(x<0) x+=mod;
        return *this; 
    }
	ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
	ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
	ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
	ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
	bool operator==(const ModInt &p) const { return x == p.x; }
	bool operator!=(const ModInt &p) const { return x != p.x; }
	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while(b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}
	ModInt pow(long long n) const {
		ModInt ret(1), mul(x);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}
	friend ostream &operator<<(ostream &os, const ModInt &p) {
		return os << p.x;
	}
	friend istream &operator>>(istream &is, ModInt &a) {
		long long t;
		is >> t;
		a = ModInt<mod>(t);
		return (is);
	}
};
//using modint = ModInt<MOD>;