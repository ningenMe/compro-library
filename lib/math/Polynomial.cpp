/*
 * @title Polynomial - 多項式補間
 * @docs md/math/Polynomial.md
 */
template<class T> class Polynomial{
public:
    //O(N^2)
    inline static vector<T> interpolation(const vector<T>& x,const vector<T>& y) {
        assert(x.size()==y.size());
        int n = x.size();
        vector<T> dp(n+1,0),tp(n+1),res(n,0);
        dp[0] = 1;
        for(int i=0;i<n;++i) {
            for(int j=0;j<=n;++j) tp[j] = 0;
            for(int j=0;j<=i;++j) {
                tp[j+0] += dp[j]*(-x[i]);
                tp[j+1] += dp[j]*1;
            }
            swap(dp,tp);
        }
        for(int i=0;i<n;++i) {
            if(x[i].x == 0) {
                for(int j=0;j<n;++j) {
                    tp[j] = dp[j+1];
                }
            }
            else {
                T ix = T(1) / x[i];
                tp[0] = dp[0]*(-ix);
                for(int j=1;j<n;++j) {
                    tp[j] = (dp[j]-tp[j-1])*(-ix);
                }
            }
            T base = 1,c = 0;
            for(int j=0;j<n;++j) {
                c += base*tp[j];
                base *= x[i];
            }
            c = y[i] / c;
            for(int j=0;j<n;++j) {
                res[j] += c*tp[j];
            }
        }
        return res;
    }
    //O(N \log mod)
    inline static T interpolation_arithmetic(const T a0,const T d, const vector<T>& y,const T x) {
        int n = y.size();
        T gx = 1,fx = 0;
        vector<T> gxi(n,1);
        for(int i=0;i<n;++i) gx *= x-(a0 + d*i);
        for(int i=1;i<n;++i) gxi[0] *= (-d*i);
        for(int i=1;i<n;++i) gxi[i] = gxi[i-1] * (d*i) / (d*(i-n));
        for(int i=0;i<n;++i) fx += (y[i] / gxi[i]) * (gx / (x - (a0 + d*i))); 
        return fx;
    } 
    //O(N)
    inline static T eval(const vector<T>& f,T x) {
        T base = 1, res = 0;
        for(int i=0;i<f.size(); ++i) {
            res += base*f[i];
            base *= x;
        }
        return res;
    }
};