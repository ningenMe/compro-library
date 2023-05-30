
/*
 * @title RadixHeap - 非負整数heap
 * @docs md/heap/RadixHeap.md
 */
template<class T, class Key = unsigned long long> class RadixHeap{
    using TypeNode = pair<Key, T>;
    template<class InnerKey, class ZZ=InnerKey> class Inner{};
    template<class InnerKey> class Inner<InnerKey, unsigned long long>{
        array<vector<TypeNode>,65> vq;
        unsigned long long size_num;
        TypeNode last;
        inline int bit(unsigned long long a) { return a ? 64 - __builtin_clzll(a) : 0;}
    public:
        Inner(T mini) : size_num(0), last(make_pair(0, mini)) {}
        inline bool empty() { return size_num == 0; }
        inline size_t size(){ return size_num; }
        inline void push(TypeNode x){ ++size_num; vq[bit(x.first^last.first)].push_back(x);}
        inline void emplace(unsigned long long key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}
        inline TypeNode pop() {
            if(vq[0].empty()) {
                int i = 1;
                while(vq[i].empty()) ++i;
                last = *min_element(vq[i].begin(),vq[i].end());
                for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);
                vq[i].clear();
            }
            --size_num;
            auto res = vq[0].back(); vq[0].pop_back();
            return res;
        }
    };
    template<class InnerKey> class Inner<InnerKey, unsigned int>{
        array<vector<TypeNode>,33> vq;
        unsigned int size_num;
        TypeNode last;
        inline int bit(unsigned int a) { return a ? 32 - __builtin_clz(a) : 0;}
    public:
        Inner(T mini) : size_num(0), last(make_pair(0, mini)) {}
        inline bool empty() { return size_num == 0; }
        inline size_t size(){ return size_num; }
        inline void push(TypeNode x){ ++size_num; vq[bit(x.first^last.first)].push_back(x);}
        inline void emplace(unsigned int key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}
        inline TypeNode pop() {
            if(vq[0].empty()) {
                int i = 1;
                while(vq[i].empty()) ++i;
                last = *min_element(vq[i].begin(),vq[i].end());
                for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);
                vq[i].clear();
            }
            --size_num;
            auto res = vq[0].back(); vq[0].pop_back();
            return res;
        }
    };
    Inner<Key,Key> inner;
public:
    RadixHeap(T mini) : inner(mini) {}
    inline bool empty() { return inner.empty();}
    inline size_t size(){ return inner.size();}
    inline void push(TypeNode x){ inner.push(x);}
    inline void emplace(unsigned long long key,T val){ inner.emplace(key,val);}
    inline TypeNode pop() { return inner.pop(); }
};