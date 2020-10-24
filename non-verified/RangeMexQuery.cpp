/*
 * 区間mex
 * @params A vector
 * @params ranges 半開区間[l,r)のvector 0-indexed
 * @params offset mexの最小値
 * @params ret rangeに対するmexの値
 * @see https://codeforces.com/contest/1436/problem/E
 * @see https://twitter.com/noshi91/status/1279594849826533377?s=20
 */
template<class T> map<pair<int,int>,int> static_range_mex_query(const vector<T>& A, const vector<pair<int,int>>& ranges, T offset = 0) {
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
