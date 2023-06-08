/*
 * @title WaveletMatrix
 * @docs md/data-structure/WaveletMatrix.md
 */
template<class T> class WaveletMatrix{
    using u64 = unsigned long long;
    using u32 = unsigned int;
    class BitVector{
        inline static constexpr size_t BIT_BLOCK_SIZE = 5;
        inline static constexpr size_t BIT_BLOCK_NUM  = 1<<BIT_BLOCK_SIZE;
        inline static constexpr u32 popcount(u32 x) {return __builtin_popcount(x);}
        inline static constexpr u32 popcount(u64 x) {return __builtin_popcountll(x);}
        vector<u32> vec, acc;
    public:
        BitVector(const u32 N) {
            u32 tmp = (N + BIT_BLOCK_NUM-1) / BIT_BLOCK_NUM;
            vec.assign(tmp, 0);
            acc.assign(tmp, 0);
        }
        void build() { for (size_t i = 0,sum = 0; i < acc.size(); ++i) acc[i] = (sum += popcount(vec[i]) );}
        //[0,r) count of bit
        u32 rank(const u32 r, const bool bit) const {
            u32 bit_r = r >> BIT_BLOCK_SIZE; 
            u32 sum = (bit_r ? acc[bit_r - 1] : 0) + popcount(vec[bit_r] & ((1U << (r & (BIT_BLOCK_NUM-1))) - 1));
            return bit ? sum : r - sum;
        }
        //[l,l+1) = bit
        void update(const u32 l, const bool bit) {
            u32 bit_l = l >> BIT_BLOCK_SIZE;
            if (bit) vec[bit_l] |=   1U << (l & (BIT_BLOCK_NUM-1));
            else     vec[bit_l] &= ~(1U << (l & (BIT_BLOCK_NUM-1)));
        }
        //[l,l+1)
        bool operator[](const u32 l) const {
            return ((vec[l >> BIT_BLOCK_SIZE] >> (l & (BIT_BLOCK_NUM-1))) & 1);
        }
    };
    vector<u32> Zarts(const vector<T>& ar) {
        vector<u32> ord(ar.size()),compressed(ar.size());
        iota(ord.begin(),ord.end(),0);
        sort(ord.begin(),ord.end(),[&](size_t l, size_t r){return ar[l]<ar[r];});
        u32 cnt = 0;
        compressed.front() = 0;
        T pre = ar[ord.front()];
        for(size_t i=1;i<ord.size();++i) {
            size_t j=ord[i];
            if(pre < ar[j]) ++cnt;
            compressed[j] = cnt;
            pre = ar[j];
        }
        return compressed;
    }
    size_t length;
    size_t depth;
    vector<BitVector> multi_bit_vector;
    vector<u32> sum_bit_off;
    vector<T> vec;

    inline T get_impl(u32 l) const {
        u32 val = 0;
        for (u32 j = 0; j < depth; ++j) {
            const bool bit = multi_bit_vector[j][l];
            val = ((val << 1) | bit);
            l = multi_bit_vector[j].rank(l, bit);
            if(bit) l += sum_bit_off[j];
        }
        return vec[val];
    }
    inline T range_kth_smallest_impl(u32 l, u32 r, u32 k) const {
        u32 val = 0;
        for (u32 j = 0; j < depth; ++j) {
            u32 cnt_bit_off = multi_bit_vector[j].rank(r, 0) - multi_bit_vector[j].rank(l, 0);
            const bool bit = (k >= cnt_bit_off);
            val = ((val << 1) | bit);
            l = multi_bit_vector[j].rank(l, bit);
            r = multi_bit_vector[j].rank(r, bit);
            if (bit) l += sum_bit_off[j], r += sum_bit_off[j], k -= cnt_bit_off;
        }
        return vec[val];
    }
    void build() {
        length = vec.size();
        auto compressed = Zarts(vec);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        u32 maxi = *max_element(compressed.begin(),compressed.end()) + 1;
        for(depth=0; (1<<depth) <= maxi; ++depth );

        multi_bit_vector.assign(depth, BitVector(length));
        sum_bit_off.assign(depth, 0UL);
        vector<u32> prev = compressed, next = prev;
        for(u32 j = 0; j < depth; ++j,swap(prev,next)) {
            u32 bit = 1UL << (depth - j - 1);
            for(u32 i = 0; i < length; ++i) sum_bit_off[j] += !(prev[i] & bit);
            u32 idx_bit_off = 0, idx_bit_on = sum_bit_off[j];
            for(u32 i = 0; i < length; ++i) {
                if (prev[i] & bit) multi_bit_vector[j].update(i,1), next[idx_bit_on++] = prev[i];
                else next[idx_bit_off++] = prev[i];
            }
            multi_bit_vector[j].build();
        }
    }
    //[l,r) range count of more and less than c (c'<c, c'=c, c<c')
    // tuple<uint32, uint32, uint32> rank_all(T c, uint32 l, uint32 r) const
    // {
    // 	if (c > vec.back()) return make_tuple(r - l, 0U, 0U);
    // 	array<uint32,2> more_and_less = {0,0};
    // 	for (uint32 j = 0; j < depth; ++j) {
    // 		const bool bit = (c >> (depth - j - 1)) & 1;
    // 		more_and_less[bit] += r - l;
    // 		l = multi_bit_vector[j].rank(l, bit);
    // 		r = multi_bit_vector[j].rank(r, bit);
    // 		if (bit) l += sum_bit_off[j], r += sum_bit_off[j];
    // 		more_and_less[bit] -= r - l;
    // 	}
    // 	return make_tuple(more_and_less[1], r - l, more_and_less[0]);
    // }
public:
    WaveletMatrix(const vector<T> &vec): vec(vec) { build(); }
    //[l,l+1) element
    inline T get(const u32 l) const {return get_impl(l);}
    //[l,r) range k (0-indexed) th smallest number
    T range_kth_smallest(const u32 l, const u32 r, const u32 k) const {return range_kth_smallest_impl(l,r,k);}
    T range_kth_largest(const u32 l, const u32 r, const u32 k) const {return range_kth_smallest_impl(l,r,(r-l)-(k+1));}
};