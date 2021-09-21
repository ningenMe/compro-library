/*
 * @title Combination - 二項係数
 * @docs md/math/Combination.md
 */
template<class T> class Combination{
    vector<vector<T>> num;
public:
    //O(N^2)
    Combination(int N):num(N+1,vector<T>(N+1,(T)0)){
        num[0][0] = 1;
        for (int n = 1; n <= N; n++) {
            for (int k = 0; k <= n; k++) {
                num[n][k] = (num[n - 1][k]+(k?num[n - 1][k - 1]:0));
            }
        }
    }
    inline T binom(int n, int k) {
        return ((n < 0 || k < 0 || n < k) ? 0 : num[n][k]);
    }
    //nCk mod p (p is prime & p <= N)
    inline T lucas(int n, int k, long long p) {
        long long res=1;
        for(;n||k;n/=p,k/=p) (res *= num[n%p][k%p]) %= p;
        return res;
    }
};