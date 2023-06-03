---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/WordSizeTreeSet.test.cpp
    title: test/data-structure/WordSizeTreeSet.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/WordSizeTreeSet.md
    document_title: "WordSizeTreeSet - 64\u5206\u6728"
    links: []
  bundledCode: "#line 1 \"lib/14-data-structure/WordSizeTreeSet.cpp\"\n/*\n * @title\
    \ WordSizeTreeSet - 64\u5206\u6728\n * @docs md/data-structure/WordSizeTreeSet.md\n\
    \ */\nclass WordSizeTreeSet {\npublic:\n    using u64 = unsigned long long;\n\
    \    inline static constexpr u64 max_length=(1ULL<<24);\nprivate:\n    inline\
    \ static constexpr u64 word_size=(1ULL<<6);\n    inline static constexpr array<u64,word_size>\
    \ pow2 = {1ULL, 2ULL, 4ULL, 8ULL, 16ULL, 32ULL, 64ULL, 128ULL, 256ULL, 512ULL,\
    \ 1024ULL, 2048ULL, 4096ULL, 8192ULL, 16384ULL, 32768ULL, 65536ULL, 131072ULL,\
    \ 262144ULL, 524288ULL, 1048576ULL, 2097152ULL, 4194304ULL, 8388608ULL, 16777216ULL,\
    \ 33554432ULL, 67108864ULL, 134217728ULL, 268435456ULL, 536870912ULL, 1073741824ULL,\
    \ 2147483648ULL, 4294967296ULL, 8589934592ULL, 17179869184ULL, 34359738368ULL,\
    \ 68719476736ULL, 137438953472ULL, 274877906944ULL, 549755813888ULL, 1099511627776ULL,\
    \ 2199023255552ULL, 4398046511104ULL, 8796093022208ULL, 17592186044416ULL, 35184372088832ULL,\
    \ 70368744177664ULL, 140737488355328ULL, 281474976710656ULL, 562949953421312ULL,\
    \ 1125899906842624ULL, 2251799813685248ULL, 4503599627370496ULL, 9007199254740992ULL,\
    \ 18014398509481984ULL, 36028797018963968ULL, 72057594037927936ULL, 144115188075855872ULL,\
    \ 288230376151711744ULL, 576460752303423488ULL, 1152921504606846976ULL, 2305843009213693952ULL,\
    \ 4611686018427387904ULL, 9223372036854775808ULL};\n    inline static constexpr\
    \ array<u64,word_size> next_lower_bound_mask = {18446744073709551615ULL, 18446744073709551614ULL,\
    \ 18446744073709551612ULL, 18446744073709551608ULL, 18446744073709551600ULL, 18446744073709551584ULL,\
    \ 18446744073709551552ULL, 18446744073709551488ULL, 18446744073709551360ULL, 18446744073709551104ULL,\
    \ 18446744073709550592ULL, 18446744073709549568ULL, 18446744073709547520ULL, 18446744073709543424ULL,\
    \ 18446744073709535232ULL, 18446744073709518848ULL, 18446744073709486080ULL, 18446744073709420544ULL,\
    \ 18446744073709289472ULL, 18446744073709027328ULL, 18446744073708503040ULL, 18446744073707454464ULL,\
    \ 18446744073705357312ULL, 18446744073701163008ULL, 18446744073692774400ULL, 18446744073675997184ULL,\
    \ 18446744073642442752ULL, 18446744073575333888ULL, 18446744073441116160ULL, 18446744073172680704ULL,\
    \ 18446744072635809792ULL, 18446744071562067968ULL, 18446744069414584320ULL, 18446744065119617024ULL,\
    \ 18446744056529682432ULL, 18446744039349813248ULL, 18446744004990074880ULL, 18446743936270598144ULL,\
    \ 18446743798831644672ULL, 18446743523953737728ULL, 18446742974197923840ULL, 18446741874686296064ULL,\
    \ 18446739675663040512ULL, 18446735277616529408ULL, 18446726481523507200ULL, 18446708889337462784ULL,\
    \ 18446673704965373952ULL, 18446603336221196288ULL, 18446462598732840960ULL, 18446181123756130304ULL,\
    \ 18445618173802708992ULL, 18444492273895866368ULL, 18442240474082181120ULL, 18437736874454810624ULL,\
    \ 18428729675200069632ULL, 18410715276690587648ULL, 18374686479671623680ULL, 18302628885633695744ULL,\
    \ 18158513697557839872ULL, 17870283321406128128ULL, 17293822569102704640ULL, 16140901064495857664ULL,\
    \ 13835058055282163712ULL, 9223372036854775808ULL};\n    inline static constexpr\
    \ array<u64,word_size> prev_lower_bound_mask = {1ULL, 3ULL, 7ULL, 15ULL, 31ULL,\
    \ 63ULL, 127ULL, 255ULL, 511ULL, 1023ULL, 2047ULL, 4095ULL, 8191ULL, 16383ULL,\
    \ 32767ULL, 65535ULL, 131071ULL, 262143ULL, 524287ULL, 1048575ULL, 2097151ULL,\
    \ 4194303ULL, 8388607ULL, 16777215ULL, 33554431ULL, 67108863ULL, 134217727ULL,\
    \ 268435455ULL, 536870911ULL, 1073741823ULL, 2147483647ULL, 4294967295ULL, 8589934591ULL,\
    \ 17179869183ULL, 34359738367ULL, 68719476735ULL, 137438953471ULL, 274877906943ULL,\
    \ 549755813887ULL, 1099511627775ULL, 2199023255551ULL, 4398046511103ULL, 8796093022207ULL,\
    \ 17592186044415ULL, 35184372088831ULL, 70368744177663ULL, 140737488355327ULL,\
    \ 281474976710655ULL, 562949953421311ULL, 1125899906842623ULL, 2251799813685247ULL,\
    \ 4503599627370495ULL, 9007199254740991ULL, 18014398509481983ULL, 36028797018963967ULL,\
    \ 72057594037927935ULL, 144115188075855871ULL, 288230376151711743ULL, 576460752303423487ULL,\
    \ 1152921504606846975ULL, 2305843009213693951ULL, 4611686018427387903ULL, 9223372036854775807ULL,\
    \ 18446744073709551615ULL};\n    inline static constexpr array<u64,word_size>\
    \ next_upper_bound_mask = {18446744073709551614ULL, 18446744073709551612ULL, 18446744073709551608ULL,\
    \ 18446744073709551600ULL, 18446744073709551584ULL, 18446744073709551552ULL, 18446744073709551488ULL,\
    \ 18446744073709551360ULL, 18446744073709551104ULL, 18446744073709550592ULL, 18446744073709549568ULL,\
    \ 18446744073709547520ULL, 18446744073709543424ULL, 18446744073709535232ULL, 18446744073709518848ULL,\
    \ 18446744073709486080ULL, 18446744073709420544ULL, 18446744073709289472ULL, 18446744073709027328ULL,\
    \ 18446744073708503040ULL, 18446744073707454464ULL, 18446744073705357312ULL, 18446744073701163008ULL,\
    \ 18446744073692774400ULL, 18446744073675997184ULL, 18446744073642442752ULL, 18446744073575333888ULL,\
    \ 18446744073441116160ULL, 18446744073172680704ULL, 18446744072635809792ULL, 18446744071562067968ULL,\
    \ 18446744069414584320ULL, 18446744065119617024ULL, 18446744056529682432ULL, 18446744039349813248ULL,\
    \ 18446744004990074880ULL, 18446743936270598144ULL, 18446743798831644672ULL, 18446743523953737728ULL,\
    \ 18446742974197923840ULL, 18446741874686296064ULL, 18446739675663040512ULL, 18446735277616529408ULL,\
    \ 18446726481523507200ULL, 18446708889337462784ULL, 18446673704965373952ULL, 18446603336221196288ULL,\
    \ 18446462598732840960ULL, 18446181123756130304ULL, 18445618173802708992ULL, 18444492273895866368ULL,\
    \ 18442240474082181120ULL, 18437736874454810624ULL, 18428729675200069632ULL, 18410715276690587648ULL,\
    \ 18374686479671623680ULL, 18302628885633695744ULL, 18158513697557839872ULL, 17870283321406128128ULL,\
    \ 17293822569102704640ULL, 16140901064495857664ULL, 13835058055282163712ULL, 9223372036854775808ULL,\
    \ 0ULL};\n    inline static constexpr array<u64,word_size> prev_upper_bound_mask\
    \ = {0ULL, 1ULL, 3ULL, 7ULL, 15ULL, 31ULL, 63ULL, 127ULL, 255ULL, 511ULL, 1023ULL,\
    \ 2047ULL, 4095ULL, 8191ULL, 16383ULL, 32767ULL, 65535ULL, 131071ULL, 262143ULL,\
    \ 524287ULL, 1048575ULL, 2097151ULL, 4194303ULL, 8388607ULL, 16777215ULL, 33554431ULL,\
    \ 67108863ULL, 134217727ULL, 268435455ULL, 536870911ULL, 1073741823ULL, 2147483647ULL,\
    \ 4294967295ULL, 8589934591ULL, 17179869183ULL, 34359738367ULL, 68719476735ULL,\
    \ 137438953471ULL, 274877906943ULL, 549755813887ULL, 1099511627775ULL, 2199023255551ULL,\
    \ 4398046511103ULL, 8796093022207ULL, 17592186044415ULL, 35184372088831ULL, 70368744177663ULL,\
    \ 140737488355327ULL, 281474976710655ULL, 562949953421311ULL, 1125899906842623ULL,\
    \ 2251799813685247ULL, 4503599627370495ULL, 9007199254740991ULL, 18014398509481983ULL,\
    \ 36028797018963967ULL, 72057594037927935ULL, 144115188075855871ULL, 288230376151711743ULL,\
    \ 576460752303423487ULL, 1152921504606846975ULL, 2305843009213693951ULL, 4611686018427387903ULL,\
    \ 9223372036854775807ULL};\n\n    inline static constexpr u64 ctz(const u64& value){\n\
    \        // 1010100010101000101010001010100010101000101010001010100010101000 ->\
    \ 3\n        // 1010100010101000101010001010100010101000101010001010100010101001\
    \ -> 0\n        // 1010100010101000101010001010100010101000101010001010100010100000\
    \ -> 5\n        // 0000000000000000000000000000000000000000000000000000000000000000\
    \ -> undef\n        return __builtin_ctzll(value);\n    }\n    inline static constexpr\
    \ u64 clz(const u64& value){\n        // 0000100010101000101010001010100010101000101010001010100010101000\
    \ -> 63 - 4 = 59\n        // 1000100010101000101010001010100010101000101010001010100010101000\
    \ -> 63 - 0 = 63\n        // 0000000010101000101010001010100010101000101010001010100010101000\
    \ -> 63 - 9 = 54\n        // 0000000000000000000000000000000000000000000000000000000000000000\
    \ -> undef\n        return word_size - 1 - __builtin_clzll(value);\n    }\n\n\
    \    template<u64 length, u64 ZZ=length> class Inner{\n    private:        \n\
    \        static_assert(length%word_size==0);\n        inline static constexpr\
    \ u64 child_length = length/word_size;\n        u64 node;\n        array<Inner<child_length,\
    \ child_length>, word_size> child;\n    public:\n        Inner(): node(0ULL),child()\
    \ {}\n        bool insert_impl(const u64& value) {\n            u64 idx = value\
    \ / (child_length);\n            node |= pow2[idx];\n            return child[idx].insert_impl(value\
    \ % child_length);\n        }\n        bool erase_impl(const u64& value) {\n \
    \           u64 idx = value / (child_length);\n            bool is_exist_child_node\
    \ = child[idx].erase_impl(value % child_length);\n            if(!is_exist_child_node)\
    \ node &= ~pow2[idx];\n            return node;\n        }\n        bool count_impl(const\
    \ u64& value) const {\n            u64 idx = value / (child_length);\n       \
    \     return (node & pow2[idx]) && child[idx].count_impl(value % child_length);\n\
    \        }\n        u64 next_lower_bound_impl(const u64& value) const {\n    \
    \        u64 idx = value / (child_length);\n            if(node & pow2[idx]) {\n\
    \                const u64 res = child[idx].next_lower_bound_impl(value % child_length);\n\
    \                if(res != max_length) return idx*child_length + res;\n      \
    \      }\n            u64 masked_node = (node & next_upper_bound_mask[idx]);\n\
    \            if(masked_node==0) return max_length;\n            {\n          \
    \      u64 idx2=ctz(masked_node);\n                u64 res = child[idx2].next_lower_bound_impl(0);\n\
    \                return idx2*child_length + res;\n            }\n        }\n \
    \       u64 prev_lower_bound_impl(const u64& value) const {\n            u64 idx\
    \ = value / (child_length);\n            if(node & pow2[idx]) {\n            \
    \    const u64 res = child[idx].prev_lower_bound_impl(value % child_length);\n\
    \                if(res != max_length) return idx*child_length + res;\n      \
    \      }\n            u64 masked_node = (node & prev_upper_bound_mask[idx]);\n\
    \            if(masked_node==0) return max_length;\n            {\n          \
    \      u64 idx2=clz(masked_node);\n                u64 res = child[idx2].prev_lower_bound_impl(child_length\
    \ - 1);\n                return idx2*child_length + res;\n            }\n    \
    \    }\n    };\n    template<unsigned long long length> class Inner<length, word_size>{\n\
    \    private:\n        u64 node;\n    public:\n        Inner(): node(0ULL){}\n\
    \        bool insert_impl(const u64& idx) {\n            bool is_inserted = (node\
    \ & pow2[idx]);\n            node |= pow2[idx];\n            return !is_inserted;\
    \        \n        }\n        bool erase_impl(const u64& idx) {\n            bool\
    \ is_inserted = (node & pow2[idx]);\n            node &= ~pow2[idx];\n       \
    \     return node;\n        }\n        bool count_impl(const u64& idx) const {\n\
    \            return (node & pow2[idx]);\n        }\n        u64 next_lower_bound_impl(const\
    \ u64& idx) const {\n            u64 masked_node = (node & next_lower_bound_mask[idx]);\n\
    \            if(masked_node==0) return max_length;\n            return ctz(masked_node);\n\
    \        }\n        u64 prev_lower_bound_impl(const u64& idx) const {\n      \
    \      u64 masked_node = (node & prev_lower_bound_mask[idx]);\n            if(masked_node==0)\
    \ return max_length;\n            return clz(masked_node);\n        }\n    };\n\
    \    Inner<max_length> inner;\npublic:\n    WordSizeTreeSet():inner(){}\n    void\
    \ insert(const u64& value){inner.insert_impl(value);}\n    void erase(const u64&\
    \ value){inner.erase_impl(value);}\n    bool count(const u64& value) const {return\
    \ inner.count_impl(value);}\n    u64 next_lower_bound(const u64& value) const\
    \ {return inner.next_lower_bound_impl(value);}\n    u64 prev_lower_bound(const\
    \ u64& value) const {return inner.prev_lower_bound_impl(value);}\n};\n"
  code: "/*\n * @title WordSizeTreeSet - 64\u5206\u6728\n * @docs md/data-structure/WordSizeTreeSet.md\n\
    \ */\nclass WordSizeTreeSet {\npublic:\n    using u64 = unsigned long long;\n\
    \    inline static constexpr u64 max_length=(1ULL<<24);\nprivate:\n    inline\
    \ static constexpr u64 word_size=(1ULL<<6);\n    inline static constexpr array<u64,word_size>\
    \ pow2 = {1ULL, 2ULL, 4ULL, 8ULL, 16ULL, 32ULL, 64ULL, 128ULL, 256ULL, 512ULL,\
    \ 1024ULL, 2048ULL, 4096ULL, 8192ULL, 16384ULL, 32768ULL, 65536ULL, 131072ULL,\
    \ 262144ULL, 524288ULL, 1048576ULL, 2097152ULL, 4194304ULL, 8388608ULL, 16777216ULL,\
    \ 33554432ULL, 67108864ULL, 134217728ULL, 268435456ULL, 536870912ULL, 1073741824ULL,\
    \ 2147483648ULL, 4294967296ULL, 8589934592ULL, 17179869184ULL, 34359738368ULL,\
    \ 68719476736ULL, 137438953472ULL, 274877906944ULL, 549755813888ULL, 1099511627776ULL,\
    \ 2199023255552ULL, 4398046511104ULL, 8796093022208ULL, 17592186044416ULL, 35184372088832ULL,\
    \ 70368744177664ULL, 140737488355328ULL, 281474976710656ULL, 562949953421312ULL,\
    \ 1125899906842624ULL, 2251799813685248ULL, 4503599627370496ULL, 9007199254740992ULL,\
    \ 18014398509481984ULL, 36028797018963968ULL, 72057594037927936ULL, 144115188075855872ULL,\
    \ 288230376151711744ULL, 576460752303423488ULL, 1152921504606846976ULL, 2305843009213693952ULL,\
    \ 4611686018427387904ULL, 9223372036854775808ULL};\n    inline static constexpr\
    \ array<u64,word_size> next_lower_bound_mask = {18446744073709551615ULL, 18446744073709551614ULL,\
    \ 18446744073709551612ULL, 18446744073709551608ULL, 18446744073709551600ULL, 18446744073709551584ULL,\
    \ 18446744073709551552ULL, 18446744073709551488ULL, 18446744073709551360ULL, 18446744073709551104ULL,\
    \ 18446744073709550592ULL, 18446744073709549568ULL, 18446744073709547520ULL, 18446744073709543424ULL,\
    \ 18446744073709535232ULL, 18446744073709518848ULL, 18446744073709486080ULL, 18446744073709420544ULL,\
    \ 18446744073709289472ULL, 18446744073709027328ULL, 18446744073708503040ULL, 18446744073707454464ULL,\
    \ 18446744073705357312ULL, 18446744073701163008ULL, 18446744073692774400ULL, 18446744073675997184ULL,\
    \ 18446744073642442752ULL, 18446744073575333888ULL, 18446744073441116160ULL, 18446744073172680704ULL,\
    \ 18446744072635809792ULL, 18446744071562067968ULL, 18446744069414584320ULL, 18446744065119617024ULL,\
    \ 18446744056529682432ULL, 18446744039349813248ULL, 18446744004990074880ULL, 18446743936270598144ULL,\
    \ 18446743798831644672ULL, 18446743523953737728ULL, 18446742974197923840ULL, 18446741874686296064ULL,\
    \ 18446739675663040512ULL, 18446735277616529408ULL, 18446726481523507200ULL, 18446708889337462784ULL,\
    \ 18446673704965373952ULL, 18446603336221196288ULL, 18446462598732840960ULL, 18446181123756130304ULL,\
    \ 18445618173802708992ULL, 18444492273895866368ULL, 18442240474082181120ULL, 18437736874454810624ULL,\
    \ 18428729675200069632ULL, 18410715276690587648ULL, 18374686479671623680ULL, 18302628885633695744ULL,\
    \ 18158513697557839872ULL, 17870283321406128128ULL, 17293822569102704640ULL, 16140901064495857664ULL,\
    \ 13835058055282163712ULL, 9223372036854775808ULL};\n    inline static constexpr\
    \ array<u64,word_size> prev_lower_bound_mask = {1ULL, 3ULL, 7ULL, 15ULL, 31ULL,\
    \ 63ULL, 127ULL, 255ULL, 511ULL, 1023ULL, 2047ULL, 4095ULL, 8191ULL, 16383ULL,\
    \ 32767ULL, 65535ULL, 131071ULL, 262143ULL, 524287ULL, 1048575ULL, 2097151ULL,\
    \ 4194303ULL, 8388607ULL, 16777215ULL, 33554431ULL, 67108863ULL, 134217727ULL,\
    \ 268435455ULL, 536870911ULL, 1073741823ULL, 2147483647ULL, 4294967295ULL, 8589934591ULL,\
    \ 17179869183ULL, 34359738367ULL, 68719476735ULL, 137438953471ULL, 274877906943ULL,\
    \ 549755813887ULL, 1099511627775ULL, 2199023255551ULL, 4398046511103ULL, 8796093022207ULL,\
    \ 17592186044415ULL, 35184372088831ULL, 70368744177663ULL, 140737488355327ULL,\
    \ 281474976710655ULL, 562949953421311ULL, 1125899906842623ULL, 2251799813685247ULL,\
    \ 4503599627370495ULL, 9007199254740991ULL, 18014398509481983ULL, 36028797018963967ULL,\
    \ 72057594037927935ULL, 144115188075855871ULL, 288230376151711743ULL, 576460752303423487ULL,\
    \ 1152921504606846975ULL, 2305843009213693951ULL, 4611686018427387903ULL, 9223372036854775807ULL,\
    \ 18446744073709551615ULL};\n    inline static constexpr array<u64,word_size>\
    \ next_upper_bound_mask = {18446744073709551614ULL, 18446744073709551612ULL, 18446744073709551608ULL,\
    \ 18446744073709551600ULL, 18446744073709551584ULL, 18446744073709551552ULL, 18446744073709551488ULL,\
    \ 18446744073709551360ULL, 18446744073709551104ULL, 18446744073709550592ULL, 18446744073709549568ULL,\
    \ 18446744073709547520ULL, 18446744073709543424ULL, 18446744073709535232ULL, 18446744073709518848ULL,\
    \ 18446744073709486080ULL, 18446744073709420544ULL, 18446744073709289472ULL, 18446744073709027328ULL,\
    \ 18446744073708503040ULL, 18446744073707454464ULL, 18446744073705357312ULL, 18446744073701163008ULL,\
    \ 18446744073692774400ULL, 18446744073675997184ULL, 18446744073642442752ULL, 18446744073575333888ULL,\
    \ 18446744073441116160ULL, 18446744073172680704ULL, 18446744072635809792ULL, 18446744071562067968ULL,\
    \ 18446744069414584320ULL, 18446744065119617024ULL, 18446744056529682432ULL, 18446744039349813248ULL,\
    \ 18446744004990074880ULL, 18446743936270598144ULL, 18446743798831644672ULL, 18446743523953737728ULL,\
    \ 18446742974197923840ULL, 18446741874686296064ULL, 18446739675663040512ULL, 18446735277616529408ULL,\
    \ 18446726481523507200ULL, 18446708889337462784ULL, 18446673704965373952ULL, 18446603336221196288ULL,\
    \ 18446462598732840960ULL, 18446181123756130304ULL, 18445618173802708992ULL, 18444492273895866368ULL,\
    \ 18442240474082181120ULL, 18437736874454810624ULL, 18428729675200069632ULL, 18410715276690587648ULL,\
    \ 18374686479671623680ULL, 18302628885633695744ULL, 18158513697557839872ULL, 17870283321406128128ULL,\
    \ 17293822569102704640ULL, 16140901064495857664ULL, 13835058055282163712ULL, 9223372036854775808ULL,\
    \ 0ULL};\n    inline static constexpr array<u64,word_size> prev_upper_bound_mask\
    \ = {0ULL, 1ULL, 3ULL, 7ULL, 15ULL, 31ULL, 63ULL, 127ULL, 255ULL, 511ULL, 1023ULL,\
    \ 2047ULL, 4095ULL, 8191ULL, 16383ULL, 32767ULL, 65535ULL, 131071ULL, 262143ULL,\
    \ 524287ULL, 1048575ULL, 2097151ULL, 4194303ULL, 8388607ULL, 16777215ULL, 33554431ULL,\
    \ 67108863ULL, 134217727ULL, 268435455ULL, 536870911ULL, 1073741823ULL, 2147483647ULL,\
    \ 4294967295ULL, 8589934591ULL, 17179869183ULL, 34359738367ULL, 68719476735ULL,\
    \ 137438953471ULL, 274877906943ULL, 549755813887ULL, 1099511627775ULL, 2199023255551ULL,\
    \ 4398046511103ULL, 8796093022207ULL, 17592186044415ULL, 35184372088831ULL, 70368744177663ULL,\
    \ 140737488355327ULL, 281474976710655ULL, 562949953421311ULL, 1125899906842623ULL,\
    \ 2251799813685247ULL, 4503599627370495ULL, 9007199254740991ULL, 18014398509481983ULL,\
    \ 36028797018963967ULL, 72057594037927935ULL, 144115188075855871ULL, 288230376151711743ULL,\
    \ 576460752303423487ULL, 1152921504606846975ULL, 2305843009213693951ULL, 4611686018427387903ULL,\
    \ 9223372036854775807ULL};\n\n    inline static constexpr u64 ctz(const u64& value){\n\
    \        // 1010100010101000101010001010100010101000101010001010100010101000 ->\
    \ 3\n        // 1010100010101000101010001010100010101000101010001010100010101001\
    \ -> 0\n        // 1010100010101000101010001010100010101000101010001010100010100000\
    \ -> 5\n        // 0000000000000000000000000000000000000000000000000000000000000000\
    \ -> undef\n        return __builtin_ctzll(value);\n    }\n    inline static constexpr\
    \ u64 clz(const u64& value){\n        // 0000100010101000101010001010100010101000101010001010100010101000\
    \ -> 63 - 4 = 59\n        // 1000100010101000101010001010100010101000101010001010100010101000\
    \ -> 63 - 0 = 63\n        // 0000000010101000101010001010100010101000101010001010100010101000\
    \ -> 63 - 9 = 54\n        // 0000000000000000000000000000000000000000000000000000000000000000\
    \ -> undef\n        return word_size - 1 - __builtin_clzll(value);\n    }\n\n\
    \    template<u64 length, u64 ZZ=length> class Inner{\n    private:        \n\
    \        static_assert(length%word_size==0);\n        inline static constexpr\
    \ u64 child_length = length/word_size;\n        u64 node;\n        array<Inner<child_length,\
    \ child_length>, word_size> child;\n    public:\n        Inner(): node(0ULL),child()\
    \ {}\n        bool insert_impl(const u64& value) {\n            u64 idx = value\
    \ / (child_length);\n            node |= pow2[idx];\n            return child[idx].insert_impl(value\
    \ % child_length);\n        }\n        bool erase_impl(const u64& value) {\n \
    \           u64 idx = value / (child_length);\n            bool is_exist_child_node\
    \ = child[idx].erase_impl(value % child_length);\n            if(!is_exist_child_node)\
    \ node &= ~pow2[idx];\n            return node;\n        }\n        bool count_impl(const\
    \ u64& value) const {\n            u64 idx = value / (child_length);\n       \
    \     return (node & pow2[idx]) && child[idx].count_impl(value % child_length);\n\
    \        }\n        u64 next_lower_bound_impl(const u64& value) const {\n    \
    \        u64 idx = value / (child_length);\n            if(node & pow2[idx]) {\n\
    \                const u64 res = child[idx].next_lower_bound_impl(value % child_length);\n\
    \                if(res != max_length) return idx*child_length + res;\n      \
    \      }\n            u64 masked_node = (node & next_upper_bound_mask[idx]);\n\
    \            if(masked_node==0) return max_length;\n            {\n          \
    \      u64 idx2=ctz(masked_node);\n                u64 res = child[idx2].next_lower_bound_impl(0);\n\
    \                return idx2*child_length + res;\n            }\n        }\n \
    \       u64 prev_lower_bound_impl(const u64& value) const {\n            u64 idx\
    \ = value / (child_length);\n            if(node & pow2[idx]) {\n            \
    \    const u64 res = child[idx].prev_lower_bound_impl(value % child_length);\n\
    \                if(res != max_length) return idx*child_length + res;\n      \
    \      }\n            u64 masked_node = (node & prev_upper_bound_mask[idx]);\n\
    \            if(masked_node==0) return max_length;\n            {\n          \
    \      u64 idx2=clz(masked_node);\n                u64 res = child[idx2].prev_lower_bound_impl(child_length\
    \ - 1);\n                return idx2*child_length + res;\n            }\n    \
    \    }\n    };\n    template<unsigned long long length> class Inner<length, word_size>{\n\
    \    private:\n        u64 node;\n    public:\n        Inner(): node(0ULL){}\n\
    \        bool insert_impl(const u64& idx) {\n            bool is_inserted = (node\
    \ & pow2[idx]);\n            node |= pow2[idx];\n            return !is_inserted;\
    \        \n        }\n        bool erase_impl(const u64& idx) {\n            bool\
    \ is_inserted = (node & pow2[idx]);\n            node &= ~pow2[idx];\n       \
    \     return node;\n        }\n        bool count_impl(const u64& idx) const {\n\
    \            return (node & pow2[idx]);\n        }\n        u64 next_lower_bound_impl(const\
    \ u64& idx) const {\n            u64 masked_node = (node & next_lower_bound_mask[idx]);\n\
    \            if(masked_node==0) return max_length;\n            return ctz(masked_node);\n\
    \        }\n        u64 prev_lower_bound_impl(const u64& idx) const {\n      \
    \      u64 masked_node = (node & prev_lower_bound_mask[idx]);\n            if(masked_node==0)\
    \ return max_length;\n            return clz(masked_node);\n        }\n    };\n\
    \    Inner<max_length> inner;\npublic:\n    WordSizeTreeSet():inner(){}\n    void\
    \ insert(const u64& value){inner.insert_impl(value);}\n    void erase(const u64&\
    \ value){inner.erase_impl(value);}\n    bool count(const u64& value) const {return\
    \ inner.count_impl(value);}\n    u64 next_lower_bound(const u64& value) const\
    \ {return inner.next_lower_bound_impl(value);}\n    u64 prev_lower_bound(const\
    \ u64& value) const {return inner.prev_lower_bound_impl(value);}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/14-data-structure/WordSizeTreeSet.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/WordSizeTreeSet.test.cpp
documentation_of: lib/14-data-structure/WordSizeTreeSet.cpp
layout: document
redirect_from:
- /library/lib/14-data-structure/WordSizeTreeSet.cpp
- /library/lib/14-data-structure/WordSizeTreeSet.cpp.html
title: "WordSizeTreeSet - 64\u5206\u6728"
---
### WordSizeTreeSet
- 64分木
- セグ木の要領でデータを管理するが、葉の部分を u64 の bitで管理することでメモリが小さく高速
- `[0,1<<24)` の区間の整数データしか管理できない

### reference
- https://ningenme.net/compro-category/topic/topic_7F5IZI/problem