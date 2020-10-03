---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc068/tasks/arc068_c
  bundledCode: "#line 1 \"old/Lazy_Segment_Tree_Range_Sum_Query.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<class T> class Lazy_Segment_Tree_Range_Sum_Query\
    \ {\n \tsize_t N, M;\n\tT ini;\n\tvector<T> node,lazy;\n\npublic:\n    Lazy_Segment_Tree_Range_Sum_Query(const\
    \ vector<T> & ar, const T ini) : M(ar.size()),ini(ini){\n        for (N = 1; N\
    \ < M; N *= 2);\n        node.resize(2 * N - 1, ini);\n        lazy.resize(2 *\
    \ N - 1, ini);\n\t\tfor (int i = 0; i<M; ++i) node[i + N - 1] = ar[i];\n\t\tfor\
    \ (int i = N - 2; i >= 0; --i) node[i] = node[2 * i + 1]+node[2 * i + 2];\n  \
    \  }\n\n\tLazy_Segment_Tree_Range_Sum_Query(const size_t M, const T ini) : M(M),ini(ini){\n\
    \        for (N = 1; N < M; N *= 2);\n        node.resize(2 * N - 1, ini);\n \
    \       lazy.resize(2 * N - 1, ini);\n    }\n\n    void eval(int k, int l, int\
    \ r) {\n\t\tnode[k] += lazy[k];\n\t\tif(r - l > 1) lazy[2*k+1] += lazy[k] / 2;\n\
    \t\tif(r - l > 1) lazy[2*k+2] += lazy[k] / 2;\n\t\tlazy[k] = ini;\n    }\n\n \
    \   void update(int a, int b, T x, int k=0, int l=0, int r=-1) {\n        if(r\
    \ < 0) r = N;\n        eval(k, l, r);\n        if(b <= l || r <= a) return;\n\
    \        if(a <= l && r <= b) {\n            lazy[k] += (r - l) * x;\n       \
    \     eval(k, l, r);\n        }\n        else {\n            update(a, b, x, 2*k+1,\
    \ l, (l+r)/2);\n            update(a, b, x, 2*k+2, (l+r)/2, r);\n            node[k]\
    \ = node[2*k+1] + node[2*k+2];\n        }\n    }\n\n    T getvar(int a, int b,\
    \ int k=0, int l=0, int r=-1) {\n        if(r < 0) r = N;\n        eval(k, l,\
    \ r);\n        if(b <= l || r <= a) return 0;\n        if(a <= l && r <= b) return\
    \ node[k];\n        T vl = getvar(a, b, 2*k+1, l, (l+r)/2);\n        T vr = getvar(a,\
    \ b, 2*k+2, (l+r)/2, r);\n        return vl + vr;\n    }\n\n\tT operator[](size_t\
    \ idx) {\n\t\treturn getvar(idx, idx + 1);\n\t}\n\n\tT operator[](pair<size_t,\
    \ size_t> p) {\n\t\treturn getvar(p.first, p.second);\n\t}\n\n\tvoid print(){\n\
    \t\tcout << \"{ \" << getvar(0,1);\n\t\tfor(int i = 1; i < M; ++i) cout << \"\
    , \" << getvar(i,i+1);\n\t\tcout << \" }\" << endl;\n\t}\n};\n\n\n//verify https://atcoder.jp/contests/arc068/tasks/arc068_c\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class T> class\
    \ Lazy_Segment_Tree_Range_Sum_Query {\n \tsize_t N, M;\n\tT ini;\n\tvector<T>\
    \ node,lazy;\n\npublic:\n    Lazy_Segment_Tree_Range_Sum_Query(const vector<T>\
    \ & ar, const T ini) : M(ar.size()),ini(ini){\n        for (N = 1; N < M; N *=\
    \ 2);\n        node.resize(2 * N - 1, ini);\n        lazy.resize(2 * N - 1, ini);\n\
    \t\tfor (int i = 0; i<M; ++i) node[i + N - 1] = ar[i];\n\t\tfor (int i = N - 2;\
    \ i >= 0; --i) node[i] = node[2 * i + 1]+node[2 * i + 2];\n    }\n\n\tLazy_Segment_Tree_Range_Sum_Query(const\
    \ size_t M, const T ini) : M(M),ini(ini){\n        for (N = 1; N < M; N *= 2);\n\
    \        node.resize(2 * N - 1, ini);\n        lazy.resize(2 * N - 1, ini);\n\
    \    }\n\n    void eval(int k, int l, int r) {\n\t\tnode[k] += lazy[k];\n\t\t\
    if(r - l > 1) lazy[2*k+1] += lazy[k] / 2;\n\t\tif(r - l > 1) lazy[2*k+2] += lazy[k]\
    \ / 2;\n\t\tlazy[k] = ini;\n    }\n\n    void update(int a, int b, T x, int k=0,\
    \ int l=0, int r=-1) {\n        if(r < 0) r = N;\n        eval(k, l, r);\n   \
    \     if(b <= l || r <= a) return;\n        if(a <= l && r <= b) {\n         \
    \   lazy[k] += (r - l) * x;\n            eval(k, l, r);\n        }\n        else\
    \ {\n            update(a, b, x, 2*k+1, l, (l+r)/2);\n            update(a, b,\
    \ x, 2*k+2, (l+r)/2, r);\n            node[k] = node[2*k+1] + node[2*k+2];\n \
    \       }\n    }\n\n    T getvar(int a, int b, int k=0, int l=0, int r=-1) {\n\
    \        if(r < 0) r = N;\n        eval(k, l, r);\n        if(b <= l || r <= a)\
    \ return 0;\n        if(a <= l && r <= b) return node[k];\n        T vl = getvar(a,\
    \ b, 2*k+1, l, (l+r)/2);\n        T vr = getvar(a, b, 2*k+2, (l+r)/2, r);\n  \
    \      return vl + vr;\n    }\n\n\tT operator[](size_t idx) {\n\t\treturn getvar(idx,\
    \ idx + 1);\n\t}\n\n\tT operator[](pair<size_t, size_t> p) {\n\t\treturn getvar(p.first,\
    \ p.second);\n\t}\n\n\tvoid print(){\n\t\tcout << \"{ \" << getvar(0,1);\n\t\t\
    for(int i = 1; i < M; ++i) cout << \", \" << getvar(i,i+1);\n\t\tcout << \" }\"\
    \ << endl;\n\t}\n};\n\n\n//verify https://atcoder.jp/contests/arc068/tasks/arc068_c"
  dependsOn: []
  isVerificationFile: false
  path: old/Lazy_Segment_Tree_Range_Sum_Query.cpp
  requiredBy: []
  timestamp: '2019-09-22 01:50:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Lazy_Segment_Tree_Range_Sum_Query.cpp
layout: document
redirect_from:
- /library/old/Lazy_Segment_Tree_Range_Sum_Query.cpp
- /library/old/Lazy_Segment_Tree_Range_Sum_Query.cpp.html
title: old/Lazy_Segment_Tree_Range_Sum_Query.cpp
---
