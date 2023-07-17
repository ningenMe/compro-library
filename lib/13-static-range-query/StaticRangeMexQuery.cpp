
/*
 * @title StaticRangeMexQuery - 静的区間mexクエリ
 * @docs md/static-range-query/StaticRangeMexQuery.md
 */
template<class T> class StaticRangeMexQuery {
    struct MonoidRangeMinPointUpdate {
        using TypeNode = T;
        inline static constexpr TypeNode unit_node = (1LL<<31)-1;
        inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return min(l,r);}
        inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return r;}
        inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var > nodeVal;}
    };
    unordered_map<long long, long long> res;
    long long length;
public:
    StaticRangeMexQuery(const vector<T>& A, const vector<pair<int,int>>& ranges, T offset = 0) {
        length = A.size();
        vector<vector<int>> r_to_l(length+1);
        for(int i=0;i<ranges.size();++i) {
            const int& l=ranges[i].first;
            const int& r=ranges[i].second;
            r_to_l[r].push_back(l);
        }
        SegmentTree<MonoidRangeMinPointUpdate> seg(offset+length+1,-1);
        for(int i=0;i<offset;++i) seg.operate(i,offset+length+1);
        for(int r=0;r<length;++r) {
            if(A[r]<=offset+length) seg.operate(A[r],r);
            for(int& l:r_to_l[r+1]) {
                res[l*(length+1)+r+1] = seg.prefix_binary_search(offset,offset+length+1,l);
            }
        }
    }
    //[l,r) の mex (クエリ先読みしたもののみ)
    long long fold(int l, int r) {
        assert(res.count((length+1)*l + r)>0);
        return res[(length+1)*l+r];
    }
};