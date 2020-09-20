---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/code-festival-2018-final/tasks/code_festival_2018_final_e
  bundledCode: "#line 1 \"old/Lazy_Segment_Tree_Range_Minimum_Query.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n\ntemplate<class T> class Lazy_Segment_Tree_Range_Minimum_Query\
    \ {\n\tsize_t N, M;\n\tT ini;\n\tvector<T> node, lazy;\n\tvector<bool> lazyflag;\n\
    \npublic:\n\tLazy_Segment_Tree_Range_Minimum_Query(const vector<T>& ar, const\
    \ T ini) : M(ar.size()), ini(ini) {\n\t\tfor (N = 1; N < M; N *= 2);\n\t\tnode.resize(2\
    \ * N - 1);\n\t\tlazy.resize(2 * N - 1, ini);\n\t\tlazyflag.resize(2 * N - 1,\
    \ false);\n\t\tfor (int i = 0; i<M; ++i) node[i + N - 1] = ar[i];\n\t\tfor (int\
    \ i = N - 2; i >= 0; --i) node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);\n\t\
    }\n\n\tLazy_Segment_Tree_Range_Minimum_Query(const size_t M, const T ini) : M(M),\
    \ ini(ini) {\n\t\tfor (N = 1; N < M; N *= 2);\n\t\tnode.resize(2 * N - 1, ini);\n\
    \t\tlazy.resize(2 * N - 1, ini);\n\t\tlazyflag.resize(2 * N - 1, false);\n\t}\n\
    \n\tvoid eval(int k, int l, int r) {\n\t\tif (lazyflag[k]) {\n\t\t\tnode[k] =\
    \ lazy[k];\n\t\t\tif (r - l > 1) {\n\t\t\t\tlazy[k * 2 + 1] = lazy[k];\n\t\t\t\
    \tlazy[k * 2 + 2] = lazy[k];\n\t\t\t\tlazyflag[k * 2 + 1] = lazyflag[k * 2 + 2]\
    \ = true;\n\t\t\t}\n\t\t\tlazyflag[k] = false;\n\t\t}\n\t}\n\n\tvoid update(int\
    \ a, int b, T x, int k = 0, int l = 0, int r = -1) {\n\t\tif (r < 0) r = N;\n\t\
    \teval(k, l, r);\n\t\tif (b <= l || r <= a) return;\n\t\tif (a <= l && r <= b)\
    \ {\n\t\t\tlazy[k] = x;\n\t\t\tlazyflag[k] = true;\n\t\t\teval(k, l, r);\n\t\t\
    }\n\t\telse {\n\t\t\tupdate(a, b, x, 2 * k + 1, l, (l + r) / 2);\n\t\t\tupdate(a,\
    \ b, x, 2 * k + 2, (l + r) / 2, r);\n\t\t\tnode[k] = min(node[2 * k + 1], node[2\
    \ * k + 2]);\n\t\t}\n\t}\n\n\tT getvar(int a, int b, int k = 0, int l = 0, int\
    \ r = -1) {\n\t\tif (r < 0) r = N;\n\t\teval(k, l, r);\n\t\tif (b <= l || r <=\
    \ a) return ini;\n\t\tif (a <= l && r <= b) return node[k];\n\t\tT vl = getvar(a,\
    \ b, 2 * k + 1, l, (l + r) / 2);\n\t\tT vr = getvar(a, b, 2 * k + 2, (l + r) /\
    \ 2, r);\n\t\treturn min(vl, vr);\n\t}\n\n\tT operator[](size_t idx) {\n\t\treturn\
    \ getvar(idx, idx + 1);\n\t}\n\n\tT operator[](pair<size_t, size_t> p) {\n\t\t\
    return getvar(p.first, p.second);\n\t}\n\n\tvoid print() {\n\t\tcout << \"{ \"\
    \ << getvar(0, 1);\n\t\tfor (int i = 1; i < M; ++i) cout << \", \" << getvar(i,\
    \ i + 1);\n\t\tcout << \" }\" << endl;\n\t}\n};\n\n\n//verify https://atcoder.jp/contests/code-festival-2018-final/tasks/code_festival_2018_final_e\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n\ntemplate<class T> class\
    \ Lazy_Segment_Tree_Range_Minimum_Query {\n\tsize_t N, M;\n\tT ini;\n\tvector<T>\
    \ node, lazy;\n\tvector<bool> lazyflag;\n\npublic:\n\tLazy_Segment_Tree_Range_Minimum_Query(const\
    \ vector<T>& ar, const T ini) : M(ar.size()), ini(ini) {\n\t\tfor (N = 1; N <\
    \ M; N *= 2);\n\t\tnode.resize(2 * N - 1);\n\t\tlazy.resize(2 * N - 1, ini);\n\
    \t\tlazyflag.resize(2 * N - 1, false);\n\t\tfor (int i = 0; i<M; ++i) node[i +\
    \ N - 1] = ar[i];\n\t\tfor (int i = N - 2; i >= 0; --i) node[i] = min(node[i *\
    \ 2 + 1], node[i * 2 + 2]);\n\t}\n\n\tLazy_Segment_Tree_Range_Minimum_Query(const\
    \ size_t M, const T ini) : M(M), ini(ini) {\n\t\tfor (N = 1; N < M; N *= 2);\n\
    \t\tnode.resize(2 * N - 1, ini);\n\t\tlazy.resize(2 * N - 1, ini);\n\t\tlazyflag.resize(2\
    \ * N - 1, false);\n\t}\n\n\tvoid eval(int k, int l, int r) {\n\t\tif (lazyflag[k])\
    \ {\n\t\t\tnode[k] = lazy[k];\n\t\t\tif (r - l > 1) {\n\t\t\t\tlazy[k * 2 + 1]\
    \ = lazy[k];\n\t\t\t\tlazy[k * 2 + 2] = lazy[k];\n\t\t\t\tlazyflag[k * 2 + 1]\
    \ = lazyflag[k * 2 + 2] = true;\n\t\t\t}\n\t\t\tlazyflag[k] = false;\n\t\t}\n\t\
    }\n\n\tvoid update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {\n\t\t\
    if (r < 0) r = N;\n\t\teval(k, l, r);\n\t\tif (b <= l || r <= a) return;\n\t\t\
    if (a <= l && r <= b) {\n\t\t\tlazy[k] = x;\n\t\t\tlazyflag[k] = true;\n\t\t\t\
    eval(k, l, r);\n\t\t}\n\t\telse {\n\t\t\tupdate(a, b, x, 2 * k + 1, l, (l + r)\
    \ / 2);\n\t\t\tupdate(a, b, x, 2 * k + 2, (l + r) / 2, r);\n\t\t\tnode[k] = min(node[2\
    \ * k + 1], node[2 * k + 2]);\n\t\t}\n\t}\n\n\tT getvar(int a, int b, int k =\
    \ 0, int l = 0, int r = -1) {\n\t\tif (r < 0) r = N;\n\t\teval(k, l, r);\n\t\t\
    if (b <= l || r <= a) return ini;\n\t\tif (a <= l && r <= b) return node[k];\n\
    \t\tT vl = getvar(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tT vr = getvar(a, b, 2\
    \ * k + 2, (l + r) / 2, r);\n\t\treturn min(vl, vr);\n\t}\n\n\tT operator[](size_t\
    \ idx) {\n\t\treturn getvar(idx, idx + 1);\n\t}\n\n\tT operator[](pair<size_t,\
    \ size_t> p) {\n\t\treturn getvar(p.first, p.second);\n\t}\n\n\tvoid print() {\n\
    \t\tcout << \"{ \" << getvar(0, 1);\n\t\tfor (int i = 1; i < M; ++i) cout << \"\
    , \" << getvar(i, i + 1);\n\t\tcout << \" }\" << endl;\n\t}\n};\n\n\n//verify\
    \ https://atcoder.jp/contests/code-festival-2018-final/tasks/code_festival_2018_final_e"
  dependsOn: []
  isVerificationFile: false
  path: old/Lazy_Segment_Tree_Range_Minimum_Query.cpp
  requiredBy: []
  timestamp: '2019-09-22 01:50:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Lazy_Segment_Tree_Range_Minimum_Query.cpp
layout: document
redirect_from:
- /library/old/Lazy_Segment_Tree_Range_Minimum_Query.cpp
- /library/old/Lazy_Segment_Tree_Range_Minimum_Query.cpp.html
title: old/Lazy_Segment_Tree_Range_Minimum_Query.cpp
---
