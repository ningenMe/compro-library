---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/13-static-range-query/LongestIncreasingSubsequence.cpp
    title: LongestIncreasingSubsequence - LIS
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"test/static-range-query/LongestIncreasingSubsequence-size.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\nusing namespace\
    \ std;\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n\
    \ */\nclass FastIO{\nprivate:\n    inline static constexpr int ch_0='0';\n   \
    \ inline static constexpr int ch_9='9';\n    inline static constexpr int ch_n='-';\n\
    \    inline static constexpr int ch_s=' ';\n    inline static constexpr int ch_l='\\\
    n';\n    inline static void endline_skip(char& ch) {\n        while(ch==ch_l)\
    \ ch=getchar();\n    }\n    template<typename T> inline static void read_integer(T\
    \ &x) {\n        int neg=0; char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        if(ch==ch_n) neg=1,ch=getchar();\n        for(;(ch_0 <= ch && ch <= ch_9);\
    \ ch = getchar()) x = x*10 + (ch-ch_0);\n        if(neg) x*=-1;\n    }\n    template<typename\
    \ T> inline static void read_unsigned_integer(T &x) {\n        char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        for(;(ch_0 <= ch &&\
    \ ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n    }\n    inline static\
    \ void read_string(string &x) {\n        char ch; x=\"\";\n        ch=getchar();\n\
    \        endline_skip(ch);\n        for(;(ch != ch_s && ch!=ch_l); ch = getchar())\
    \ x.push_back(ch);\n    }\n    inline static char ar[40];\n    inline static char\
    \ *ch_ar;\n    template<typename T> inline static void write_integer(T x) {\n\
    \        ch_ar=ar;\n        if(x< 0) putchar(ch_n), x=-x;\n        if(x==0) putchar(ch_0);\n\
    \        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n        while(ch_ar--!=ar) putchar(*ch_ar);\n\
    \    }\npublic:\n    inline static void read(int &x) {read_integer<int>(x);}\n\
    \    inline static void read(long long &x) {read_integer<long long>(x);}\n   \
    \ inline static void read(unsigned int &x) {read_unsigned_integer<unsigned int>(x);}\n\
    \    inline static void read(unsigned long long &x) {read_unsigned_integer<unsigned\
    \ long long>(x);}\n    inline static void read(string &x) {read_string(x);}\n\
    \    inline static void read(__int128_t &x) {read_integer<__int128_t>(x);}\n \
    \   inline static void write(__int128_t x) {write_integer<__int128_t>(x);}\n \
    \   inline static void write(char x) {putchar(x);}\n};\n#define read(arg) FastIO::read(arg)\n\
    #define write(arg) FastIO::write(arg)\n#line 1 \"lib/13-static-range-query/LongestIncreasingSubsequence.cpp\"\
    \n/*\n * @title LongestIncreasingSubsequence - LIS\n * @docs md/13-static-range-query/LongestIncreasingSubsequence.md\n\
    \ */\ntemplate<class T> class LongestIncreasingSubsequence {\n    size_t length;\n\
    \    size_t sz;\n    vector<size_t> dp_key;\n    vector<T> dp_val;\n    vector<size_t>\
    \ pre;\npublic:\n    LongestIncreasingSubsequence(const vector<T> & ar, T inf=3e18)\
    \ {\n        length = ar.size();\n        dp_key.resize(length, length);\n   \
    \     dp_val.resize(length, inf);\n        pre.resize(length);\n        for (int\
    \ i = 0; i < length; ++i) {\n            int key = lower_bound(dp_val.begin(),\
    \ dp_val.end(), ar[i]) - dp_val.begin();\n            dp_val[key] = ar[i];\n \
    \           dp_key[key] = i;\n            pre[i] = (key ? dp_key[key-1] : length);\n\
    \        };\n        sz = lower_bound(dp_val.begin(), dp_val.end(), inf) - dp_val.begin();\n\
    \    }\n\n    int size() {\n        return sz;\n    }\n\n    vector<int> index()\
    \ {\n        vector<int> res;\n        for(size_t idx = dp_key[sz-1]; idx != length;\
    \ idx = pre[idx]) {\n            res.push_back(idx);\n        }\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n \n};\n#line 9 \"test/static-range-query/LongestIncreasingSubsequence-size.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; read(N);\n\
    \    vector<long long> a(N);\n    for(int i=0;i<N;++i) read(a[i]);\n    LongestIncreasingSubsequence\
    \ lis(a);\n    cout << lis.size() << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\nusing namespace\
    \ std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/13-static-range-query/LongestIncreasingSubsequence.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; read(N);\n\
    \    vector<long long> a(N);\n    for(int i=0;i<N;++i) read(a[i]);\n    LongestIncreasingSubsequence\
    \ lis(a);\n    cout << lis.size() << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/13-static-range-query/LongestIncreasingSubsequence.cpp
  isVerificationFile: true
  path: test/static-range-query/LongestIncreasingSubsequence-size.test.cpp
  requiredBy: []
  timestamp: '2023-07-09 01:40:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static-range-query/LongestIncreasingSubsequence-size.test.cpp
layout: document
redirect_from:
- /verify/test/static-range-query/LongestIncreasingSubsequence-size.test.cpp
- /verify/test/static-range-query/LongestIncreasingSubsequence-size.test.cpp.html
title: test/static-range-query/LongestIncreasingSubsequence-size.test.cpp
---
