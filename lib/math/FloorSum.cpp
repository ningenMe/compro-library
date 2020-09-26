/**
 * @title FloorSum - 直線領域の格子点数
 * @docs md/math/FloorSum.md
 */
inline static long long FloorSum(long long n, long long m, long long a, long long b) {
    long long ret=0;
    while(1) {
        if(a >= m) ret += ((n-1)*n*(a/m))>>1,a%=m;
        if(b >= m) ret += n*(b / m),b%=m;
        long long y=(a*n+b)/m, x=(y*m-b);
        if(y==0) return ret;
        ret += (n-(x+a-1)/a)*y;
        b=(a-x%a)%a; swap(a,m); n=y;
    }
}