
template <class T> class SmallestEnclosingDisc{
    inline T cross(const complex<T>& a, const complex<T>& b) {return a.real()*b.imag() - a.imag()*b.real(); }
    inline T dot(const complex<T>& a, const complex<T>& b) { return a.real()*b.real() + a.imag()*b.imag(); }
    inline void makeCenter(const complex<T>& a,const complex<T>& b) {
        center = (a+b)/2.;
        radius = abs(a-center);
    }
    inline void makeCenter(const complex<T>& a,const complex<T>& b,const complex<T>& c) {
        T s = norm(b-c),t = norm(c-a),u = norm(a-b),z = abs(cross(b-a,c-a));
        center = (s*(t+u-s)*a+t*(u+s-t)*b+u*(s+t-u)*c)/(4*z*z);
        radius = abs(a-center);
    }
    inline bool isInCircle(const complex<T>& point){
        return norm(point-center) <= radius*radius + eps;
    } 
    vector<complex<T>> points;
    T eps;
public:
    complex<T> center;
    T radius;

    SmallestEnclosingDisc(T eps = 1e-9): eps(eps){
    }
    inline void addPoint(complex<T> point){
        points.push_back(point);
    }
    void solve(){
        int num = points.size();
        if(num == 1) {
            radius = 0;
            center = points.front();
            return;
        }
        random_device seed_gen;
        mt19937 engine(seed_gen());
        shuffle(points.begin(), points.end(), engine);
        makeCenter(points[0],points[1]);
        for(int i = 2; i < num; ++i){
            if(isInCircle(points[i])) continue;
            makeCenter(points[0],points[i]);
            for(int j = 1; j < i; ++j) {
                if(isInCircle(points[j])) continue;
                makeCenter(points[i],points[j]);
                for(int k = 0; k < j; ++k) {
                    if(isInCircle(points[k])) continue;
                    makeCenter(points[i],points[j],points[k]);
                }
            }
        }
    }
};

//verify https://atcoder.jp/contests/abc151/tasks/abc151_f
