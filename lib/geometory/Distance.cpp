
template<class T> class Distance{
public:
    //Euclidean distance
    inline static constexpr T euclid(const T& x1, const T& y1, const T& x2, const T& y2) {
        return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    }
    //Chebyshev distance
    inline static constexpr T chebyshev(T x1, T y1, T x2, T y2) {
        return max(abs(x1 - x2),abs(y1 - y2));
    }
    //Manhattan distance
    inline static constexpr T manhattan(T x1, T y1, T x2, T y2) {
        return abs(x1 - x2)+abs(y1 - y2);
    }
    inline static constexpr T between_point_and_line(const T& x,const T& y,const T& x1,const T& y1,const T& x2,const T& y2){
        return abs((y2 - y1)*x+(x1 - x2)*y-(y2-y1)*x1+(x2-x1)*y1)/sqrt((y2 - y1)*(y2 - y1)+(x1 - x2)*(x1 - x2));
    }
};