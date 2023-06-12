/*
 * @title RangeSetQueryTree - 区間setクエリ用Tree
 * @docs md/segment-tree/RangeSetQueryTree.md
 */
template<class T> class RangeSetQueryTree {
    using size_t = unsigned int;
    RangeFrequencyQueryTree<size_t> tree;
    unordered_map<T,set<size_t>> mp;
    vector<T> ar;
    size_t length;
    size_t range_set_size_impl(const int l, const int r) const {
        if (l < 0 || length <= l || r < 0 || length < r) return 0;
        return (r-l) - tree.range_freq_upper(l,r,r);
    }
    void update_impl(const size_t idx, const T next) {
        T prev = ar[idx];
        queue<pair<size_t,size_t>> q;
        //更新前の1つ左に影響があるか確認
        {
            auto itr_l = mp[prev].find(idx);
            auto itr_r = mp[prev].upper_bound(idx);
            if(itr_l != mp[prev].begin()) {
                --itr_l;
                q.emplace((*itr_l),(*itr_r));
            }
            mp[prev].erase(idx);
        }
        {
            if(mp[next].size()==0) mp[next].insert(length);
            auto itr_r = mp[next].upper_bound(idx);
            q.emplace(idx,(*itr_r));
            //更新後の1つ左に影響があるか確認
            if(itr_r != mp[next].begin()) {
                --itr_r;
                q.emplace((*itr_r),idx);
            }
            mp[next].insert(idx);
        }
        ar[idx] = next;
        while(q.size()) {
            auto [l,r]=q.front(); q.pop();
            tree.update(l,r);
        }
    }
public:
    RangeSetQueryTree(const vector<T> & vec):ar(vec),tree(vec.size()) {
        length = vec.size();
        for(size_t i = 0; i<length; ++i) mp[ar[i]].insert(i);
        for(auto& [_,st]: mp) {
            st.insert(length);
            int cnt=0;
            size_t l=length,r=length; //このl,rは閉区間 [l,r]
            for(size_t idx: st) {
                r=idx;
                if(cnt) {
                    tree.update(l,r);
                }
                l=r;
                cnt++;
            }
        }
    }
    //idx番目の要素をupdate
    void update(const size_t idx, const T val) { update_impl(idx,val); }
    //[l,r) range set size 
    size_t range_set_size(const int l, const int r) const {return range_set_size_impl(l,r);}
};