#include <bits/stdc++.h>
using namespace std;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	else {
		long long d = extGCD(b, a%b, y, x);
		y -= a / b * x;
		return d;
	}
}

// r mod m_i = b_i, M = lcm(m_i)
pair<long long, long long> Chinese_Remainder_Theorem(const vector<long long> &b, const vector<long long> &m) {
    long long r = 0, M = 1;
    for (int i = 0; i < b.size(); ++i) {
        long long p, q;
        long long d = extGCD(M, m[i], p, q);
        if ((b[i] - r) % d != 0) return {0, -1};
        long long tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return {(r%M+M)%M, M};
}

//verify https://yukicoder.me/problems/no/186