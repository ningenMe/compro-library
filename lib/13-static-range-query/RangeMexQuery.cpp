/*
 * @title RangeMexQuery - 区間mex
 * @docs md/static-range-query/RangeMexQuery.md
 */
template<class T> map<pair<int,int>,int> RangeMexQuery(const vector<T>& A, const vector<pair<int,int>>& ranges, T offset = 0) {
    int N = A.size();
    vector<vector<int>> r_to_l(N+1);
    for(int i=0;i<ranges.size();++i) {
        const int& l=ranges[i].first;
        const int& r=ranges[i].second;
        r_to_l[r].push_back(l);
    }
    SegmentTree<NodeMinPointUpdate<int>> seg(offset+N+1,-1);
    for(int i=0;i<offset;++i) seg.update(i,offset+N+1);
    map<pair<int,int>,int> ret;
    for(int r=0;r<N;++r) {
        if(A[r]<=offset+N) seg.update(A[r],r);
        for(int& l:r_to_l[r+1]) {
            ret[{l,r+1}] = seg.prefix_binary_search(offset,offset+N+1,l);
        }
    }
    return ret;
}
