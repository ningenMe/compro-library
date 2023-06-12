/*
 * @title StaticRangeSetQuery - 静的区間setクエリ
 * @docs md/static-range-query/StaticRangeSetQuery.md
 */
template<class T> class StaticRangeSetQuery {
    using size_t = unsigned int;
    WaveletMatrix<size_t> wm;
    size_t length;
    size_t range_set_size_impl(const int l, const int r) const {
        if (l < 0 || length <= l || r < 0 || length < r) return 0;
        return (r-l) - wm.range_freq_upper(l,r,r);
    }
    inline static vector<size_t> init(const vector<T> & vec) {
        size_t n = vec.size();
        unordered_map<T,set<size_t>> mp;
        for(size_t i = 0; i<n; ++i) mp[vec[i]].insert(i);
        vector<size_t> ar(n);
        for(auto& [_,st]: mp) {
            st.insert(n);
            int cnt=0;
            size_t l=n,r=n; //このl,rは閉区間 [l,r]
            for(size_t idx: st) {
                r=idx;
                if(cnt) ar[l]=r;
                l=r; cnt++;
            }
        }
        return ar;
    }
public:
    StaticRangeSetQuery(const vector<T> & vec): wm(init(vec)), length(vec.size()) {}
    //[l,r) range set size 
    size_t range_set_size(const int l, const int r) const {return range_set_size_impl(l,r);}
};

