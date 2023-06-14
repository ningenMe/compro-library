template<class T, unsigned int bit_length=20> class RangeSetQuerySqrtTree {
    using size_t = unsigned int;
    RangeIntegerFrequencyQuerySqrtTree<bit_length> tree;
    unordered_map<T,set<size_t>> mp;
    vector<T> ar;
    size_t length;
    size_t range_set_size_impl(const int l, const int r) const {
        if (l < 0 || length <= l || r < 0 || length < r) return 0;
        return (r-l) - tree.range_freq_upper(l,r,r);
    }
    void update_impl(const size_t idx, const T next) {
        T prev = ar[idx];
        //更新前の1つ左に影響があるか確認
        {
            auto itr_r = mp[prev].lower_bound(idx);
            //左が存在するなら影響あり
            if(itr_r != mp[prev].begin()) {
                auto itr_l=itr_r;
                itr_l--;
                itr_r++;
                if(itr_r==mp[prev].end()) tree.erase((*itr_l));
                else tree.update((*itr_l),(*itr_r));
            }
            mp[prev].erase(idx);
        }
        //更新後の1つ左に影響があるか確認
        {
            mp[next].insert(idx);
            auto itr_r = mp[next].upper_bound(idx);
            if(itr_r==mp[next].end()) tree.erase(idx);
            else tree.update(idx,(*itr_r));

            //左が存在するなら影響あり
            auto itr_l = mp[next].lower_bound(idx);
            if(itr_l != mp[next].begin()) {
                itr_l--;
                tree.update((*itr_l),idx);
            }
        }
        ar[idx] = next;
    }
public:
    RangeSetQuerySqrtTree(const vector<T> & vec):ar(vec),tree(vec.size()) {
        length = vec.size();
        for(size_t i = 0; i<length; ++i) mp[ar[i]].insert(i);
        for(auto& [_,st]: mp) {
            size_t l=length,r=length; //このl,rは閉区間 [l,r]
            for(size_t idx: st) {
                r=idx;
                if(l<length && r<length) tree.update(l,r);
                l=r; 
            }
        }
    }
    //idx番目の要素をupdate
    void update(const size_t idx, const T val) { update_impl(idx,val); }
    //[l,r) range set size 
    size_t range_set_size(const int l, const int r) const {return range_set_size_impl(l,r);}
};