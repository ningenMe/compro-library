---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc077/tasks/arc077_c
  bundledCode: "#line 1 \"old/Segment_Tree_Range_Sum_Query.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<class T> class Segment_Tree_Range_Sum_Query {\n\
    \tsize_t N,M;\n\tT ini;\n\tvector<T> node;\n\npublic:\n\tSegment_Tree_Range_Sum_Query(const\
    \ vector<T> & ar, const T ini) : M(ar.size()), ini(ini) {\n\t\tfor (N = 1; N <\
    \ M; N *= 2);\n\t\tnode.resize(2 * N - 1, ini);\n\t\tfor (int i = 0; i < M; ++i)\
    \ node[i + N - 1] = ar[i];\n\t\tfor (int i = N - 2; i >= 0; --i) node[i] = node[2\
    \ * i + 1]+node[2 * i + 2];\n\t}\n \n\tSegment_Tree_Range_Sum_Query(const size_t\
    \ M, const T ini) : M(M), ini(ini) {\n\t\tfor (N = 1; N < M; N *= 2);\n\t\tnode.resize(2\
    \ * N - 1, ini);\n\t}\n\t\n\tvoid update(size_t idx, const T var) {\n\t\tidx +=\
    \ (N - 1);\n\t\tnode[idx] += var;\n\t\twhile (idx > 0) {\n\t\t\tidx = (idx - 1)\
    \ / 2;\n\t\t\tnode[idx] = node[2 * idx + 1]+node[2 * idx + 2];\n\t\t}\n\t}\n \n\
    \tT getvar(const int a, const int b, int k = 0, int l = 0, int r = -1) {\n\t\t\
    if (r < 0) r = N;\n\t\tif (r <= a || b <= l) return ini;\n\t\tif (a <= l && r\
    \ <= b) return node[k];\n\t\tT vl = getvar(a, b, 2 * k + 1, l, (l + r) / 2);\n\
    \t\tT vr = getvar(a, b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn vl+vr;\n\t}\n\t\
    \n\tT operator[](size_t idx) {\n\t\treturn node[idx + N - 1];\n\t}\n\n\tT operator[](pair<size_t,\
    \ size_t> p) {\n\t\treturn getvar(p.first, p.second);\n\t}\n\n \n\tvoid print(){\n\
    \t\tcout << \"{ \" << getvar(0,1);\n\t\tfor(int i = 1; i < M; ++i) cout << \"\
    , \" << getvar(i,i+1);\n\t\tcout << \" }\" << endl;\n\t}\n};\n\n//verify https://atcoder.jp/contests/arc077/tasks/arc077_c\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class T> class\
    \ Segment_Tree_Range_Sum_Query {\n\tsize_t N,M;\n\tT ini;\n\tvector<T> node;\n\
    \npublic:\n\tSegment_Tree_Range_Sum_Query(const vector<T> & ar, const T ini) :\
    \ M(ar.size()), ini(ini) {\n\t\tfor (N = 1; N < M; N *= 2);\n\t\tnode.resize(2\
    \ * N - 1, ini);\n\t\tfor (int i = 0; i < M; ++i) node[i + N - 1] = ar[i];\n\t\
    \tfor (int i = N - 2; i >= 0; --i) node[i] = node[2 * i + 1]+node[2 * i + 2];\n\
    \t}\n \n\tSegment_Tree_Range_Sum_Query(const size_t M, const T ini) : M(M), ini(ini)\
    \ {\n\t\tfor (N = 1; N < M; N *= 2);\n\t\tnode.resize(2 * N - 1, ini);\n\t}\n\t\
    \n\tvoid update(size_t idx, const T var) {\n\t\tidx += (N - 1);\n\t\tnode[idx]\
    \ += var;\n\t\twhile (idx > 0) {\n\t\t\tidx = (idx - 1) / 2;\n\t\t\tnode[idx]\
    \ = node[2 * idx + 1]+node[2 * idx + 2];\n\t\t}\n\t}\n \n\tT getvar(const int\
    \ a, const int b, int k = 0, int l = 0, int r = -1) {\n\t\tif (r < 0) r = N;\n\
    \t\tif (r <= a || b <= l) return ini;\n\t\tif (a <= l && r <= b) return node[k];\n\
    \t\tT vl = getvar(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tT vr = getvar(a, b, 2\
    \ * k + 2, (l + r) / 2, r);\n\t\treturn vl+vr;\n\t}\n\t\n\tT operator[](size_t\
    \ idx) {\n\t\treturn node[idx + N - 1];\n\t}\n\n\tT operator[](pair<size_t, size_t>\
    \ p) {\n\t\treturn getvar(p.first, p.second);\n\t}\n\n \n\tvoid print(){\n\t\t\
    cout << \"{ \" << getvar(0,1);\n\t\tfor(int i = 1; i < M; ++i) cout << \", \"\
    \ << getvar(i,i+1);\n\t\tcout << \" }\" << endl;\n\t}\n};\n\n//verify https://atcoder.jp/contests/arc077/tasks/arc077_c"
  dependsOn: []
  isVerificationFile: false
  path: old/Segment_Tree_Range_Sum_Query.cpp
  requiredBy: []
  timestamp: '2019-09-22 01:48:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Segment_Tree_Range_Sum_Query.cpp
layout: document
redirect_from:
- /library/old/Segment_Tree_Range_Sum_Query.cpp
- /library/old/Segment_Tree_Range_Sum_Query.cpp.html
title: old/Segment_Tree_Range_Sum_Query.cpp
---
