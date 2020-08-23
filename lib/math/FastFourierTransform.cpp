/*
 * @title FastFourierTransform
 */
class FastFourierTransform{
    inline static constexpr double pi2 = 2.0 * M_PI;
    inline static constexpr pair<double,double> mul(const pair<double,double>& l,const pair<double,double>& r) {
        return {(l.first*r.first-l.second*r.second),(l.first*r.second+l.second*r.first)};
    }
    inline static constexpr pair<double,double> add(const pair<double,double>& l,const pair<double,double>& r) {
        return {(l.first+r.first),(l.second+r.second)};
    }
    inline static vector<pair<double,double>> dft(vector<pair<double,double>> f, int sgn = 1) {
        int N = f.size(),M = N/2;
        if(!M) return f;
        vector<pair<double,double>> g(M), h(M);
        pair<double,double> acc = {1,0},coe = {cos(pi2 / N), sin(pi2 / N)*sgn};
        for(int i=0; i<M; i++) g[i] = f[(i<<1)+0],h[i] = f[(i<<1)+1];
        g = dft(g, sgn); h = dft(h, sgn);
        for(int i=0; i<N; ++i, acc = mul(acc,coe)) f[i] = add(g[i%M],mul(acc,h[i%M]));
        return f;
    }
    inline static vector<pair<double,double>> inv(vector<pair<double,double>> f) {
        int N=f.size();
        f = dft(f,-1);
        for(int i=0; i<N; i++) f[i].first /= N;
        return f;
    }
public:
    template<class T> inline static vector<pair<double,double>> convolution(const vector<T>& a,const vector<T>& b) {
        int N; for(N=1;N<a.size()+b.size()+1; N<<=1);
        vector<pair<double,double>> f(N),g(N),h(N);
        for(int i = 0; i < a.size(); ++i) g[i]={a[i],0};
        for(int i = 0; i < b.size(); ++i) h[i]={b[i],0};
        g = dft(g); h = dft(h);
        for(int i=0; i<N; i++) f[i] = mul(g[i],h[i]);
        return inv(f);
    }
};