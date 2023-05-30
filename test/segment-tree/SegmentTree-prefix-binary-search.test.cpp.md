---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/10-segment-tree/SegmentTree.cpp
    title: "SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728"
  - icon: ':x:'
    path: lib/30-math/Prime.cpp
    title: "Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\
      \u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u30FBGcd\u30FBLcm"
  - icon: ':x:'
    path: lib/99-operator/monoid/MonoidRangeGcdPointUpdate.cpp
    title: "MonoidRangeGcdPointUpdate - [\u533A\u9593gcd, \u70B9\u66F4\u65B0]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/4072
    links:
    - https://yukicoder.me/problems/4072
  bundledCode: "#line 1 \"test/segment-tree/SegmentTree-prefix-binary-search.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/4072\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <array>\n#include <algorithm>\n\
    \nusing namespace std;\n#line 1 \"lib/10-segment-tree/SegmentTree.cpp\"\n/*\n\
    \ * @title SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n * @docs md/segment-tree/SegmentTree.md\n */\ntemplate<class\
    \ Monoid> class SegmentTree {\n    using TypeNode = typename Monoid::TypeNode;\n\
    \    size_t length;\n    size_t num;\n    vector<TypeNode> node;\n    vector<pair<int,int>>\
    \ range;\n    inline void build() {\n        for (int i = length - 1; i >= 0;\
    \ --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n        range.resize(2\
    \ * length);\n        for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \        for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \    }\npublic:\n\n    //unit\u3067\u521D\u671F\u5316\n    SegmentTree(const size_t\
    \ num): num(num) {\n        for (length = 1; length <= num; length *= 2);\n  \
    \      node.resize(2 * length, Monoid::unit_node);\n        build();\n    }\n\n\
    \    //vector\u3067\u521D\u671F\u5316\n    SegmentTree(const vector<TypeNode>\
    \ & vec) : num(vec.size()) {\n        for (length = 1; length <= vec.size(); length\
    \ *= 2);\n        node.resize(2 * length, Monoid::unit_node);\n        for (int\
    \ i = 0; i < vec.size(); ++i) node[i + length] = vec[i];\n        build();\n \
    \   }\n\n    //\u540C\u3058init\u3067\u521D\u671F\u5316\n    SegmentTree(const\
    \ size_t num, const TypeNode init) : num(num) {\n        for (length = 1; length\
    \ <= num; length *= 2);\n        node.resize(2 * length, Monoid::unit_node);\n\
    \        for (int i = 0; i < length; ++i) node[i+length] = init;\n        build();\n\
    \    }\n\n    //[idx,idx+1)\n    void operate(size_t idx, const TypeNode var)\
    \ {\n        if(idx < 0 || length <= idx) return;\n        idx += length;\n  \
    \      node[idx] = Monoid::func_operate(node[idx],var);\n        while(idx >>=\
    \ 1) node[idx] = Monoid::func_fold(node[(idx<<1)+0],node[(idx<<1)+1]);\n    }\n\
    \n    //[l,r)\n    TypeNode fold(int l, int r) {\n        if (l < 0 || length\
    \ <= l || r < 0 || length < r) return Monoid::unit_node;\n        TypeNode vl\
    \ = Monoid::unit_node, vr = Monoid::unit_node;\n        for(l += length, r +=\
    \ length; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Monoid::func_fold(vl,node[l++]);\n\
    \            if(r&1) vr = Monoid::func_fold(node[--r],vr);\n        }\n      \
    \  return Monoid::func_fold(vl,vr);\n    }\n\n    //range[l,r) return [l,r] search\
    \ max right\n    int prefix_binary_search(int l, int r, TypeNode var) {\n    \
    \    assert(0 <= l && l < length && 0 < r && r <= length);\n        TypeNode ret\
    \ = Monoid::unit_node;\n        size_t off = l;\n        for(size_t idx = l+length;\
    \ idx < 2*length && off < r; ){\n            if(range[idx].second<=r && !Monoid::func_check(Monoid::func_fold(ret,node[idx]),var))\
    \ {\n                ret = Monoid::func_fold(ret,node[idx]);\n               \
    \ off = range[idx++].second;\n                if(!(idx&1)) idx >>= 1;\n      \
    \      }\n            else{\n                idx <<=1;\n            }\n      \
    \  }\n        return off;\n    }\n\n    //range(l,r] return [l,r] search max left\n\
    \    int suffix_binary_search(const int l, const int r, const TypeNode var) {\n\
    \        assert(-1 <= l && l < (int)length-1 && 0 <= r && r < length);\n     \
    \   TypeNode ret = Monoid::unit_node;\n        int off = r;\n        for(size_t\
    \ idx = r+length; idx < 2*length && l < off; ){\n            if(l < range[idx].first\
    \ && !Monoid::func_check(Monoid::func_fold(node[idx],ret),var)) {\n          \
    \      ret = Monoid::func_fold(node[idx],ret);\n                off = range[idx--].first-1;\n\
    \                if(idx&1) idx >>= 1;\n            }\n            else{\n    \
    \            idx = (idx<<1)+1;\n            }\n        }\n        return off;\n\
    \    }\n\n    void print(){\n        // cout << \"node\" << endl;\n        //\
    \ for(int i = 1,j = 1; i < 2*length; ++i) {\n        // \tcout << node[i] << \"\
    \ \";\n        // \tif(i==((1<<j)-1) && ++j) cout << endl;\n        // }\n   \
    \     cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0,1);\n    \
    \    for(int i = 1; i < length; ++i) cout << \", \" << fold(i,i+1);\n        cout\
    \ << \" }\" << endl;\n    }\n};\n#line 1 \"lib/30-math/Prime.cpp\"\n/*\n * @title\
    \ Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\u30E9\
    \u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u30FBGcd\u30FBLcm\n * @docs md/math/Prime.md\n\
    \ */\nclass Prime{\n    using int128 = __int128_t;\n    using int64  = long long;\n\
    \    using u64 = unsigned long long;\n    using u32 = unsigned int;\n    inline\
    \ static long long gcd_impl(long long n, long long m) {\n        static constexpr\
    \ long long K = 5;\n        long long t,s;\n        for(int i = 0; t = n - m,\
    \ s = n - m * K, i < 80; ++i) {\n            if(t<m){\n                if(!t)\
    \ return m;\n                n = m, m = t;\n            }\n            else{\n\
    \                if(!m) return t;\n                n=t;\n                if(t\
    \ >= m * K) n = s;\n            }\n        }\n        return gcd_impl(m, n % m);\n\
    \    }\n    inline static constexpr long long pre(long long n, long long m) {\n\
    \        long long t = n - m;\n        for(int i = 0; t = n - m, i < 4; ++i) {\n\
    \            (t < m ? n=m,m=t : n=t);\n            if(!m) return n;\n        }\n\
    \        return gcd_impl(n, m);\n    }\n    inline static constexpr long long\
    \ pow(long long x, long long n, long long mod) {\n        long long res = 1;\n\
    \        for (x %= mod; n > 0; n >>= 1, x=(int128(x)*x)%mod) if (n & 1) res =\
    \ (int128(res)*x)%mod;\n        return res;\n    }\n    inline static constexpr\
    \ array<u64,3> ar1={2ULL, 7ULL, 61ULL};\n    inline static constexpr array<u64,7>\
    \ ar2={2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL};\n   \
    \ inline static constexpr int64 rho(int64 n){\n        if(miller_rabin(n)) return\
    \ n;\n        if(n%2 == 0) return 2;\n        for(int64 c=1,x=2,y=2,d=0;;c++){\n\
    \            do{\n                x=(int128(x)*x+c)%n;\n                y=(int128(y)*y+c)%n;\n\
    \                y=(int128(y)*y+c)%n;\n                d=gcd(x-y+n,n);\n     \
    \       }while(d==1);\n            if(d<n) return d;\n        }\n    }\n    inline\
    \ static vector<int64> factor(const int64 n) {\n        if(n <= 1) return {};\n\
    \        int64 p = rho(n);\n        if(p == n) return {p};\n        auto l = factor(p);\n\
    \        auto r = factor(n / p);\n        copy(r.begin(), r.end(), back_inserter(l));\n\
    \        return l;\n    }\n    template<size_t sz> inline static constexpr bool\
    \ miller_rabin(const u64& n, const array<u64,sz>& ar) {\n        u32 i,s=0; \n\
    \        u64 m = n - 1;\n        for (;!(m&1);++s,m>>=1);\n        for (const\
    \ u64& a: ar) {\n            if(a>=n) break;\n            u64 r=pow(a,m,n);\n\
    \            if(r != 1) {\n                for(i=0; i<s; ++i) {\n            \
    \        if(r == n-1) break;\n                    r = (int128(r)*r)%n;\n     \
    \           }\n                if(i==s) return false;\n            }\n       \
    \ }\n        return true;\n    }\n    inline static constexpr bool miller_rabin(const\
    \ u64 n) {\n        if(n <= 1) return false;\n        if(n == 2) return true;\n\
    \        if(n%2 == 0) return false;\n        if(n == 3) return true;\n       \
    \ if(n%3 == 0) return false;\n        if(n < 4759123141LL) return miller_rabin(n,\
    \ ar1);\n        return miller_rabin(n, ar2);\n    }\n    inline static vector<pair<int64,int64>>\
    \ factorization_impl(const int64 n) {\n        auto v = factor(n);\n        vector<pair<int64,int64>>\
    \ vp;\n        sort(v.begin(),v.end());\n        int64 prev = 0;\n        for(int64\
    \ p:v) {\n            if(p == prev) vp.back().second++;\n            else vp.emplace_back(p,1);\n\
    \            prev=p;\n        }\n        return vp;\n    }\npublic:\n    inline\
    \ static constexpr bool is_prime(const u64 n) { return is_prime(n); }\n    inline\
    \ static vector<pair<int64,int64>> factorization(const int64 n) {return factorization_impl(n);}\n\
    \    inline static constexpr long long gcd(long long n, long long m) { return\
    \ (n>m ? pre(n,m) : pre(m,n));}\n    inline static constexpr long long naive_gcd(long\
    \ long a, long long b) { return (b ? naive_gcd(b, a % b):a);}\n    inline static\
    \ constexpr long long lcm(long long a, long long b) {return (a*b ? (a / gcd(a,\
    \ b)*b): 0);}\n    inline static constexpr long long ext_gcd(long long a, long\
    \ long b, long long &x, long long &y) {\n        if (b == 0) return x = 1, y =\
    \ 0, a; long long d = ext_gcd(b, a%b, y, x); return y -= a / b * x, d;\n    }\n\
    };\n#line 1 \"lib/99-operator/monoid/MonoidRangeGcdPointUpdate.cpp\"\n/*\n * @title\
    \ MonoidRangeGcdPointUpdate - [\u533A\u9593gcd, \u70B9\u66F4\u65B0]\n * @docs\
    \ md/operator/monoid/MonoidRangeGcdPointUpdate.md\n */\ntemplate<class T> struct\
    \ MonoidRangeGcdPointUpdate {\n\tusing TypeNode = T;\n\tinline static constexpr\
    \ TypeNode unit_node = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return Prime::gcd(l,r);}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return r;}\n\tinline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n#line 13 \"test/segment-tree/SegmentTree-prefix-binary-search.test.cpp\"\
    \n\n// solution by binary search in prefix range on segment tree \nint main()\
    \ {\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tlong long N; cin >> N;\n\tvector<long\
    \ long> A(N);\n\tfor(int i = 0; i < N; ++i) cin >> A[i];\n\tSegmentTree<MonoidRangeGcdPointUpdate<long\
    \ long>> seg(A);\n\tlong long ans = 0;\n\tfor(int i = 0; i < N; ++i) {\n\t\tans\
    \ += N - seg.prefix_binary_search(i,N,1);\n\t}\n\tcout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/4072\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <array>\n#include <algorithm>\n\
    \nusing namespace std;\n#include \"../../lib/10-segment-tree/SegmentTree.cpp\"\
    \n#include \"../../lib/30-math/Prime.cpp\"\n#include \"../../lib/99-operator/monoid/MonoidRangeGcdPointUpdate.cpp\"\
    \n\n// solution by binary search in prefix range on segment tree \nint main()\
    \ {\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tlong long N; cin >> N;\n\tvector<long\
    \ long> A(N);\n\tfor(int i = 0; i < N; ++i) cin >> A[i];\n\tSegmentTree<MonoidRangeGcdPointUpdate<long\
    \ long>> seg(A);\n\tlong long ans = 0;\n\tfor(int i = 0; i < N; ++i) {\n\t\tans\
    \ += N - seg.prefix_binary_search(i,N,1);\n\t}\n\tcout << ans << endl;\n}\n"
  dependsOn:
  - lib/10-segment-tree/SegmentTree.cpp
  - lib/30-math/Prime.cpp
  - lib/99-operator/monoid/MonoidRangeGcdPointUpdate.cpp
  isVerificationFile: true
  path: test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
  requiredBy: []
  timestamp: '2023-05-31 05:05:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
- /verify/test/segment-tree/SegmentTree-prefix-binary-search.test.cpp.html
title: test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
---
