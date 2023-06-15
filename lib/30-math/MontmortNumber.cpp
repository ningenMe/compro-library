/*
 * @title MontmortNumber - 完全順列,撹乱順列の個数
 * @docs md/math/MontmortNumber.md
 */
template <class T> class MontmortNumber{
public:
    inline static vector<T> get(const size_t N) {
        vector<T> res(N+1,0);
        if(N>=2) res[2]=1;
        for(int i = 3; i <= N; ++i) res[i]=(res[i-1]+res[i-2])*(i-1);
        return res;
    }
};