/*
 * @title BitVector
 * @docs md/segment/BitVector.md
 */
class BitVector{
    inline static constexpr size_t BIT_BLOCK_SIZE = 5;
    inline static constexpr size_t BIT_BLOCK_NUM  = 1<<BIT_BLOCK_SIZE;
    inline static constexpr uint32 popcount(uint32 x) {return __builtin_popcount(x);}
    inline static constexpr uint32 popcount(uint64 x) {return __builtin_popcountll(x);}

    vector<uint32> vec, acc;
    bool is_builded = false;
public:
    BitVector(uint32 N) {
        uint32 tmp = (N + BIT_BLOCK_NUM-1) / BIT_BLOCK_NUM;
        vec.assign(tmp, 0);
        acc.assign(tmp, 0);
    }
    void build() {
        for (size_t i = 0,sum = 0; i < acc.size(); ++i) acc[i] = (sum += popcount(vec[i]) );
        is_builded = true;
    }
    //[0,r) count of bit
    uint32 rank(uint32 r, const bool bit) const {
        assert(is_builded);
        uint32 bit_r = r >> BIT_BLOCK_SIZE;
        uint32 sum = (bit_r ? acc[bit_r - 1] : 0) + popcount(vec[bit_r] & ((1U << (r & (BIT_BLOCK_NUM-1))) - 1));
        return bit ? sum : r - sum;
    }
    //[l,l+1) = bit
    void update(uint32 l, const bool bit) {
        uint32 bit_l = l >> BIT_BLOCK_SIZE;
        if (bit) vec[bit_l] |=   1U << (l & (BIT_BLOCK_NUM-1));
        else     vec[bit_l] &= ~(1U << (l & (BIT_BLOCK_NUM-1)));
    }
    //[l,l+1)
    bool operator[](uint32 l) const { 
        assert(is_builded);
        return ((vec[l >> BIT_BLOCK_SIZE] >> (l & (BIT_BLOCK_NUM-1))) & 1); 
    }
};