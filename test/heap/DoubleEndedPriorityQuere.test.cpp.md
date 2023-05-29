---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/heap/DoubleEndedPriorityQuere.cpp
    title: "DoubleEndedPriorityQuere - \u4E21\u7AEFpriority queue"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/heap/DoubleEndedPriorityQuere.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\n\n#include\
    \ <iostream>\n#include <queue>\nusing namespace std;\n#line 1 \"lib/00-util/FastIO.cpp\"\
    \n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n\
    \    inline static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    inline static constexpr int ch_n='-';\n    inline static constexpr int ch_s='\
    \ ';\n    inline static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
    \ ch) {\n        while(ch==ch_l) ch=getchar();\n    }\n    template<typename T>\
    \ inline static void read_integer(T &x) {\n        int neg=0; char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        if(ch==ch_n) neg=1,ch=getchar();\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \        if(neg) x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \    }\n    inline static void read_string(string &x) {\n        char ch; x=\"\
    \";\n        ch=getchar();\n        endline_skip(ch);\n        for(;(ch != ch_s\
    \ && ch!=ch_l); ch = getchar()) x.push_back(ch);\n    }\n    inline static char\
    \ ar[40];\n    inline static char *ch_ar;\n    template<typename T> inline static\
    \ void write_integer(T x) {\n        ch_ar=ar;\n        if(x< 0) putchar(ch_n),\
    \ x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n\
    \        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\npublic:\n    inline static\
    \ void read(int &x) {read_integer<int>(x);}\n    inline static void read(long\
    \ long &x) {read_integer<long long>(x);}\n    inline static void read(unsigned\
    \ int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline static void read(unsigned\
    \ long long &x) {read_unsigned_integer<unsigned long long>(x);}\n    inline static\
    \ void read(string &x) {read_string(x);}\n    inline static void read(__int128_t\
    \ &x) {read_integer<__int128_t>(x);}\n    inline static void write(__int128_t\
    \ x) {write_integer<__int128_t>(x);}\n    inline static void write(char x) {putchar(x);}\n\
    };\n#define read(arg) FastIO::read(arg)\n#define write(arg) FastIO::write(arg)\n\
    #line 1 \"lib/heap/DoubleEndedPriorityQuere.cpp\"\n/*\n * @title DoubleEndedPriorityQuere\
    \ - \u4E21\u7AEFpriority queue\n * @docs md/heap/DoubleEndedPriorityQuere.md\n\
    \ */\ntemplate<class T> class DoubleEndedPriorityQuere {\n\tstd::priority_queue<T>\
    \ max_pq,poped_max_pq;\n\tstd::priority_queue<T, vector<T>, greater<T> > min_pq,\
    \ poped_min_pq;\npublic:\n\tDoubleEndedPriorityQuere() {\n    }\n\tinline void\
    \ push(const T &v) {\n\t\tmax_pq.push(v);\n\t\tmin_pq.push(v);\n\t}\n\tinline\
    \ T front() {\n        while(poped_min_pq.size() && min_pq.top()==poped_min_pq.top())\
    \ min_pq.pop(),poped_min_pq.pop();\n\t\treturn min_pq.top();\n\t}\n\tinline T\
    \ back() {\n        while(poped_max_pq.size() && max_pq.top()==poped_max_pq.top())\
    \ max_pq.pop(),poped_max_pq.pop();\n\t\treturn max_pq.top();\n\t}\n\tinline void\
    \ pop_front() {\n        while(poped_min_pq.size() && min_pq.top()==poped_min_pq.top())\
    \ min_pq.pop(),poped_min_pq.pop();\n\t\tpoped_max_pq.push(min_pq.top());\n\t\t\
    min_pq.pop();\n\t}\n\tinline void pop_back() {\n        while(poped_max_pq.size()\
    \ && max_pq.top()==poped_max_pq.top()) max_pq.pop(),poped_max_pq.pop();\n\t\t\
    poped_min_pq.push(max_pq.top());\n\t\tmax_pq.pop();\n\t}\n\tinline size_t size()\
    \ const { return max_pq.size(); }\n};\n#line 8 \"test/heap/DoubleEndedPriorityQuere.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int N,Q; read(N);read(Q);\n\
    \    DoubleEndedPriorityQuere<long long> pq;\n    while(N--) {\n        long long\
    \ s; read(s); pq.push(s);\n    }\n    while(Q--) {\n        int q; read(q); \n\
    \        if(q==0) {\n            long long x; read(x);\n            pq.push(x);\n\
    \        }\n        if(q==1) {\n            long long x = pq.front(); pq.pop_front();\n\
    \            cout << x << \"\\n\";\n        }\n        if(q==2) {\n          \
    \  long long x = pq.back(); pq.pop_back();\n            cout << x << \"\\n\";\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include <iostream>\n#include <queue>\nusing namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\
    \n#include \"../../lib/heap/DoubleEndedPriorityQuere.cpp\"\n\nint main() {\n \
    \   cin.tie(0)->sync_with_stdio(0);\n    int N,Q; read(N);read(Q);\n    DoubleEndedPriorityQuere<long\
    \ long> pq;\n    while(N--) {\n        long long s; read(s); pq.push(s);\n   \
    \ }\n    while(Q--) {\n        int q; read(q); \n        if(q==0) {\n        \
    \    long long x; read(x);\n            pq.push(x);\n        }\n        if(q==1)\
    \ {\n            long long x = pq.front(); pq.pop_front();\n            cout <<\
    \ x << \"\\n\";\n        }\n        if(q==2) {\n            long long x = pq.back();\
    \ pq.pop_back();\n            cout << x << \"\\n\";\n        }\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/heap/DoubleEndedPriorityQuere.cpp
  isVerificationFile: true
  path: test/heap/DoubleEndedPriorityQuere.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 03:51:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/heap/DoubleEndedPriorityQuere.test.cpp
layout: document
redirect_from:
- /verify/test/heap/DoubleEndedPriorityQuere.test.cpp
- /verify/test/heap/DoubleEndedPriorityQuere.test.cpp.html
title: test/heap/DoubleEndedPriorityQuere.test.cpp
---
