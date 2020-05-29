class FastFourierTransform{
    inline static vector<complex<double>> dft(vector<complex<double>> f, int sgn = 1) {
        int N = f.size();
        if(N == 1) return f;
        vector<complex<double>> g(N/2), h(N/2);
        complex<double> mul = 1,coe(cos(2.0 * M_PI / N), sin(2.0 * M_PI / N) * sgn);
        for(int i=0; i<N/2; i++) g[i] = f[2*i+0],h[i] = f[2*i+1];
        g = dft(g, sgn); h = dft(h, sgn);
        for(int i=0; i<N; ++i, mul *= coe) f[i] = g[i%(N/2)] + mul*h[i%(N/2)];
        return f;
    }
    inline static vector<complex<double>> inv(vector<complex<double>> f, int N) {
        f = dft(f,-1);
        for(int i=0; i<N; i++) f[i] /= N;
        return f;
    }
public:
    template<class T> inline static vector<complex<double>> convolution(const vector<T>& a,const vector<T>& b) {
        int N; for(N=1;N<a.size()+b.size()+1; N*=2);
        vector<complex<double>> f(N),g(N),h(N);
        for(int i = 0; i < a.size(); ++i) g[i]=a[i];
        for(int i = 0; i < b.size(); ++i) h[i]=b[i];
        g = dft(g); h = dft(h);
        for(int i=0; i<N; i++) f[i] = g[i]*h[i];
        return inv(f, N);
    }
};