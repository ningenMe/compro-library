#include <bits/stdc++.h>
using namespace std;

template<long long mod> class modint {
	long long x;
public:
	modint(const long long x) :x((x + mod) % mod) {}
	modint<mod> operator + (modint<mod> &rhs) {
		modint<mod> ret(x + rhs.x);
		return ret;
	}
	modint<mod> operator - (modint<mod> &rhs) {
		modint<mod> ret(x - rhs.x);
		return ret;
	}
	long long operator()() {
		return x;
	}

	modint& operator&() {
		return this;
	}

	ostream &operator<<(ostream &o) { o << x; return o; }

};

//template<long long mod> ostream &operator<<(ostream &o, modint<mod>& obj) { o << obj(); return o; }

