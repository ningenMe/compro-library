/*
 * @title RadixHeap - 64bit型非負整数heap
 * @docs md/heap/RadixHeap.md
 */
template<class T> class RadixHeap{
    using TypeNode = pair<unsigned long long, T>;
    array<vector<TypeNode>,65> vq;
    unsigned long long size_num;
    TypeNode last;
    inline int bit(unsigned long long a) {
        return a ? 64 - __builtin_clzll(a) : 0;
    }
public:
    RadixHeap(T mini) : size_num(0), last(make_pair(0,mini)) {
        // do nothing
    }
    inline bool empty() {
        return size_num == 0;
    }
    inline size_t size(){
        return size_num;
    }
    inline void push(TypeNode x){
        ++size_num;
        vq[bit(x.first^last.first)].push_back(x);
    }
    inline void emplace(unsigned long long key,T val){
        ++size_num;
        vq[bit(key^last.first)].emplace_back(key,val);
    }
    inline TypeNode pop() {
        if(vq[0].empty()) {
            int i = 1;
            while(vq[i].empty()) ++i;
            last = *min_element(vq[i].begin(),vq[i].end());
            for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);
            vq[i].clear();
        }
        --size_num;
        auto res = vq[0].back();
        vq[0].pop_back();
        return res;
    }
};
