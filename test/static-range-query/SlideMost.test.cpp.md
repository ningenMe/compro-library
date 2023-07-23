---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/13-static-range-query/SlideMost.cpp
    title: "SlideMost - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024/\u6700\u5927\u5024"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/static-range-query/SlideMost.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <deque>\nusing namespace std;\n#line\
    \ 1 \"lib/13-static-range-query/SlideMost.cpp\"\n/*\n * @title SlideMost - \u30B9\
    \u30E9\u30A4\u30C9\u6700\u5C0F\u5024/\u6700\u5927\u5024\n * @docs md/static-range-query/SlideMost.md\n\
    \ */\ntemplate<class Operator> class SlideMost {\n    using TypeValue = typename\
    \ Operator::TypeValue;\npublic:\n    SlideMost(void){\n    }\n    vector<TypeValue>\
    \ window(vector<TypeValue>& vec, const int& width){\n        vector<TypeValue>\
    \ res(vec.size());\n        deque<TypeValue> deq;\n        for(int i = 0; i <\
    \ vec.size(); ++i) {\n            while(deq.size() && Operator::func_compare(vec[deq.back()],vec[i])\
    \ ) deq.pop_back();\n            deq.push_back(i);\n            res[i] = vec[deq.front()];\n\
    \            if(i+1>=width && deq.front()==i+1-width) deq.pop_front();\n     \
    \   }\n        return res;\n    }\n};\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\n\
    template<class T> struct ValueMin {\n    using TypeValue = T;\n    inline static\
    \ constexpr bool func_compare(TypeValue l,TypeValue r){return l>=r;}\n};\n//\u6700\
    \u5927\u5024\u30AF\u30A8\u30EA\ntemplate<class T> struct ValueMax {\n    using\
    \ TypeValue = T;\n    inline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l<=r;}\n};\n#line 8 \"test/static-range-query/SlideMost.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,L;\
    \ cin >> N >> L;\n    vector<int> A(N);\n    for(int i=0;i<N;++i) cin >> A[i];\n\
    \    SlideMost<ValueMin<int>> sld;\n    auto B = sld.window(A,L);\n    for(int\
    \ i=L-1;i<N;++i) cout << B[i] << \" \\n\"[i==N-1];\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include <vector>\n#include <iostream>\n#include <deque>\nusing namespace\
    \ std;\n#include \"../../lib/13-static-range-query/SlideMost.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    int N,L; cin >> N >> L;\n  \
    \  vector<int> A(N);\n    for(int i=0;i<N;++i) cin >> A[i];\n    SlideMost<ValueMin<int>>\
    \ sld;\n    auto B = sld.window(A,L);\n    for(int i=L-1;i<N;++i) cout << B[i]\
    \ << \" \\n\"[i==N-1];\n    return 0;\n}"
  dependsOn:
  - lib/13-static-range-query/SlideMost.cpp
  isVerificationFile: true
  path: test/static-range-query/SlideMost.test.cpp
  requiredBy: []
  timestamp: '2023-06-13 08:02:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static-range-query/SlideMost.test.cpp
layout: document
redirect_from:
- /verify/test/static-range-query/SlideMost.test.cpp
- /verify/test/static-range-query/SlideMost.test.cpp.html
title: test/static-range-query/SlideMost.test.cpp
---