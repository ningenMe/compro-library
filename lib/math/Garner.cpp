/*
 * @title Garner
 */
template<long long mod> class Garner{
	inline static constexpr long long gcd(long long a, long long b) {
		return (b ? gcd(b, a % b):a);
	}
	inline static long long ext_gcd(long long a, long long b, long long &x, long long &y) {
		long long res;
		if (b == 0) res = a,x = 1,y = 0;
		else res = ext_gcd(b, a%b, y, x), y -= a/b * x;
		return res;
	}
	inline static long long inv_mod(long long a, long long b) {
		long long x, y;
		ext_gcd(a, b, x, y);
		return (x%b+b)%b;
	}
public:
	// O(N^2) x mod m_i = b_i なる x を返却　, b_iがすべて0のときは0ではなくm_iのlcmを返す
    // return x
	inline static long long garner(vector<long long> b, vector<long long> m){
        int N=b.size();
        vector<long long> coe(N+1,1),val(N+1,0);
		long long g,gl,gr,sum=accumulate(b.begin(),b.end(),0LL);
		//互いに素になるように処理
		for (int l = 0; l < N; ++l) {
			for (int r = l+1; r < N; ++r) {
				g = gcd(m[l], m[r]);
				if (sum && (b[l] - b[r]) % g != 0) return -1;
				m[l] /= g, m[r] /= g;
				gl = gcd(m[l], g), gr = g/gl;
				do {
					g = gcd(gl, gr);
					gl *= g, gr /= g;
				} while (g != 1);
				m[l] *= gl, m[r] *= gr;
				b[l] %= m[l], b[r] %= m[r];
			}
		}
		if(!sum) {
			long long lcm = 1;
			for(auto& e:m) (lcm*=e)%=mod;
			return lcm;
		}
		m.push_back(mod);
		for(int i = 0; i < N; ++i) {
			long long t = (b[i] - val[i]) * inv_mod(coe[i], m[i]);
			((t %= m[i]) += m[i]) %= m[i];
			for (int j = i+1; j <= N; ++j) {
				(val[j] += t * coe[j]) %= m[j];
				(coe[j] *= m[i]) %= m[j];
			}
		}
        return val.back();
	}
};