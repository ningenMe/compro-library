/*
 * @title Argument - 偏角
 * @docs md/geometory/Argument.md
 */
class Argument {
public:
    template<class T> inline static vector<int> sort_by_atan2l(vector<pair<T,T>> points){
        int N = points.size();
        vector<long double> arg(N);
        for(int i = 0; i < N; ++i) arg[i] = atan2l(points[i].second,points[i].first);
        vector<int> res(N);
        iota(res.begin(),res.end(),0);
        sort(res.begin(),res.end(),[&](int l,int r){return arg[l] < arg[r];});
        return res;
    }
};
