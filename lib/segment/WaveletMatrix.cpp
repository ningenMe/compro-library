/*
 * @title WaveletMatrix
 * @docs md/segment/WaveletMatrix.md
 */
template<class T> class WaveletMatrix{
    size_t length;
    size_t depth;
    vector<BitVector> multi_bit_vector;
    vector<uint32> sum_bit_off;
    vector<T> vec;
    vector<uint32> zarts(const vector<T>& ar) {
        vector<uint32> ord(ar.size()),compressed(ar.size());
        iota(ord.begin(),ord.end(),0);
        sort(ord.begin(),ord.end(),[&](size_t l, size_t r){return ar[l]<ar[r];});
        uint32 cnt = 0;
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
public:
    WaveletMatrix(const vector<T> &arg_vec): vec(arg_vec) {
        length = vec.size();
        auto compressed = zarts(vec);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        uint32 maxi = *max_element(compressed.begin(),compressed.end()) + 1;
        for(depth=0; (1<<depth) <= maxi; ++depth );

        multi_bit_vector.assign(depth, BitVector(length));
        sum_bit_off.assign(depth, 0UL);
        vector<uint32> prev = compressed, next = prev;
        for(uint32 j = 0; j < depth; ++j,swap(prev,next)) {
            uint32 bit = 1UL << (depth - j - 1);
            for(uint32 i = 0; i < length; ++i) sum_bit_off[j] += !(prev[i] & bit);

            uint32 idx_bit_off = 0, idx_bit_on = sum_bit_off[j];
            for(uint32 i = 0; i < length; ++i) {
                if (prev[i] & bit) multi_bit_vector[j].update(i,1), next[idx_bit_on++] = prev[i];
                else next[idx_bit_off++] = prev[i];
            }
            multi_bit_vector[j].build();
        }
    }
    //[l,l+1) element
    T operator[](uint32 l) const {
        uint32 val = 0;
        for (uint32 j = 0; j < depth; ++j) {
            const bool bit = multi_bit_vector[j][l];
            val = ((val << 1) | bit);
            l = multi_bit_vector[j].rank(l, bit);
            if(bit) l += sum_bit_off[j];
        }
        return vec[val];
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

    //[l,r) range k (0-indexed) th smallest number
    T quantile(uint32 l, uint32 r, uint32 k) const {
        uint32 val = 0;
        for (uint32 j = 0; j < depth; ++j) {
            uint32 cnt_bit_off = multi_bit_vector[j].rank(r, 0) - multi_bit_vector[j].rank(l, 0);
            const bool bit = (k >= cnt_bit_off);
            val = ((val << 1) | bit);
            l = multi_bit_vector[j].rank(l, bit);
            r = multi_bit_vector[j].rank(r, bit);
            if (bit) l += sum_bit_off[j], r += sum_bit_off[j], k -= cnt_bit_off;
        }
        return vec[val];
    }
};