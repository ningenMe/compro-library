---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/data-structure/WordSizeTreeSet.test.cpp
    title: test/data-structure/data-structure/WordSizeTreeSet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/util/FastIO-int128.test.cpp
    title: test/util/FastIO-int128.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/util/FastIO-int64.test.cpp
    title: test/util/FastIO-int64.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/util/FastIO.md
    document_title: FastIO
    links: []
  bundledCode: "#line 1 \"lib/util/FastIO.cpp\"\n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n\
    \ */\nclass FastIO{\nprivate:\n    inline static constexpr int ch_0='0';\n   \
    \ inline static constexpr int ch_9='9';\n    inline static constexpr int ch_n='-';\n\
    \    inline static constexpr int ch_s=' ';\n    inline static constexpr int ch_l='\\\
    n';\n    template<typename T> inline static void read_integer(T &x) {\n      \
    \  int neg=0; char ch; x=0;\n        ch=getchar();\n        if(ch==ch_n) neg=1,ch=getchar();\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \        if(neg) x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        for(;(ch_0 <= ch\
    \ && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n    }\n    inline static\
    \ void read_string(string &x) {\n        char ch; x=\"\";\n        ch=getchar();\n\
    \        for(;(ch != ch_s && ch!=ch_l); ch = getchar()) x.push_back(ch);\n   \
    \ }\n    inline static char ar[40];\n    inline static char *ch_ar;\n    template<typename\
    \ T> inline static void write_integer(T x) {\n        ch_ar=ar;\n        if(x<\
    \ 0) putchar(ch_n), x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10)\
    \ *ch_ar++=(ch_0+x%10);\n        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\n\
    public:\n    inline static void read(int &x) {read_integer<int>(x);}\n    inline\
    \ static void read(long long &x) {read_integer<long long>(x);}\n    inline static\
    \ void read(unsigned int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline\
    \ static void read(unsigned long long &x) {read_unsigned_integer<unsigned long\
    \ long>(x);}\n    inline static void read(string &x) {read_string(x);}\n    inline\
    \ static void read(__int128_t &x) {read_integer<__int128_t>(x);}\n    inline static\
    \ void write(__int128_t x) {write_integer<__int128_t>(x);}\n    inline static\
    \ void write(char x) {putchar(x);}\n};\n#define read(arg) FastIO::read(arg)\n\
    #define write(arg) FastIO::write(arg)\n"
  code: "/*\n * @title FastIO\n * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n\
    \    inline static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    inline static constexpr int ch_n='-';\n    inline static constexpr int ch_s='\
    \ ';\n    inline static constexpr int ch_l='\\n';\n    template<typename T> inline\
    \ static void read_integer(T &x) {\n        int neg=0; char ch; x=0;\n       \
    \ ch=getchar();\n        if(ch==ch_n) neg=1,ch=getchar();\n        for(;(ch_0\
    \ <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n        if(neg)\
    \ x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        for(;(ch_0 <= ch\
    \ && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n    }\n    inline static\
    \ void read_string(string &x) {\n        char ch; x=\"\";\n        ch=getchar();\n\
    \        for(;(ch != ch_s && ch!=ch_l); ch = getchar()) x.push_back(ch);\n   \
    \ }\n    inline static char ar[40];\n    inline static char *ch_ar;\n    template<typename\
    \ T> inline static void write_integer(T x) {\n        ch_ar=ar;\n        if(x<\
    \ 0) putchar(ch_n), x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10)\
    \ *ch_ar++=(ch_0+x%10);\n        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\n\
    public:\n    inline static void read(int &x) {read_integer<int>(x);}\n    inline\
    \ static void read(long long &x) {read_integer<long long>(x);}\n    inline static\
    \ void read(unsigned int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline\
    \ static void read(unsigned long long &x) {read_unsigned_integer<unsigned long\
    \ long>(x);}\n    inline static void read(string &x) {read_string(x);}\n    inline\
    \ static void read(__int128_t &x) {read_integer<__int128_t>(x);}\n    inline static\
    \ void write(__int128_t x) {write_integer<__int128_t>(x);}\n    inline static\
    \ void write(char x) {putchar(x);}\n};\n#define read(arg) FastIO::read(arg)\n\
    #define write(arg) FastIO::write(arg)\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/FastIO.cpp
  requiredBy: []
  timestamp: '2023-05-14 01:10:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/data-structure/WordSizeTreeSet.test.cpp
  - test/util/FastIO-int128.test.cpp
  - test/util/FastIO-int64.test.cpp
documentation_of: lib/util/FastIO.cpp
layout: document
redirect_from:
- /library/lib/util/FastIO.cpp
- /library/lib/util/FastIO.cpp.html
title: FastIO
---
### FastIO
- 自作の高速Input
- cinより速いはずだけど、上位層に比べると全然速くない
- writeは遅いので、int128をどうしても出力したい時のみ。

### reference
- https://ningenme.net/compro-category/topic/topic_U82LNT/problem

### TODO
- char, double, を受け取れるようにする