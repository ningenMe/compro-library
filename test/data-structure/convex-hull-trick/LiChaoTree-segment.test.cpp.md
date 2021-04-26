---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/convex-hull-trick/LiChaoTree.cpp
    title: LiChaoTree
  - icon: ':heavy_check_mark:'
    path: lib/operator/operator/ValueMin.cpp
    title: lib/operator/operator/ValueMin.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n\
    #include <vector>\n#include <iostream>\n#include <algorithm>\nusing namespace\
    \ std;\n#line 1 \"lib/operator/operator/ValueMin.cpp\"\n//\u6700\u5C0F\u5024\u30AF\
    \u30A8\u30EA\ntemplate<class T> struct ValueMin {\n\tusing TypeValue = T;\n\t\
    inline static constexpr TypeValue unit_value = 3e18;\n\tinline static constexpr\
    \ bool func_compare(TypeValue l,TypeValue r){return l<r;}\n};\n#line 1 \"lib/data-structure/convex-hull-trick/LiChaoTree.cpp\"\
    \n/*\n * @title LiChaoTree\n * @docs md/data-structure/segment/convex-hull-trick/LiChaoTree.md\n\
    \ */\ntemplate <typename Operator> class LiChaoTree{\n\tusing TypeValue = typename\
    \ Operator::TypeValue;\n\tusing Line = pair<TypeValue,TypeValue>;\n\tvector<TypeValue>\
    \ x;\n\tvector<Line> node;\n\tvector<int> clz;\n\tsize_t length;\n\tconst size_t\
    \ bit;\npublic:\t\n\tLiChaoTree(const size_t bit=30):bit(bit){\n\t\t//do nothing\n\
    \t}\n\tinline void build(){\n\t\tsort(x.begin(),x.end());\n\t\tx.erase(unique(x.begin(),x.end()),x.end());\n\
    \t\tTypeValue maxi = x.back() + 1;\n\t\tfor (length = 1; length < x.size(); length\
    \ *= 2);\n\t\tx.resize(length, maxi);\n\t\tnode.resize(2*length,make_pair(0,Operator::unit_value));\n\
    \t\tclz.resize(2*length,32);\n\t\tfor(size_t i = 1; i < 2*length; ++i) {\n\t\t\
    \t// for(int j = 0; j < bit; ++j) if(i&(1<<j)) clz[i] = 31-j;\n\t\t\tclz[i] =\
    \ __builtin_clz(i);\n\t\t}\n\t}\n\n\tvoid x_push_back(TypeValue argx){\n\t\tx.push_back(argx);\n\
    \t}\n\n\t//return y = ax+b\n\tinline static constexpr TypeValue f(Line& line,TypeValue&\
    \ t)\t{\n\t\treturn line.first*t + line.second;\n\t}\n\t\t\n\tinline void update(Line\
    \ line,int i = 1){\n\t\twhile(i < 2*length){\n\t\t\tint l = (i<<(clz[i]-clz[length]))-length;\n\
    \t\t\tint r = l + (length>>(31-clz[i])) - 1;\n\t\t\tint m = (l+r)>>1;\n\t\t\t\
    bool flgl = Operator::func_compare(f(line,x[l]),f(node[i],x[l]));\n\t\t\tbool\
    \ flgm = Operator::func_compare(f(line,x[m]),f(node[i],x[m]));\n\t\t\tbool flgr\
    \ = Operator::func_compare(f(line,x[r]),f(node[i],x[r]));\n\n\t\t\tif(flgl&&flgr)\
    \ node[i] = line;\n\t\t\tif(flgl==flgr) break;\n\t\t\tif(flgm) swap(node[i],line),swap(flgl,flgr);\n\
    \t\t\ti = (i<<1)+flgr;\n\t\t}\n\t}\n\tinline void update(Line line,TypeValue l,TypeValue\
    \ r){\n\t\tl = distance(x.begin(),lower_bound(x.begin(),x.end(),l))+length;\n\t\
    \tr = distance(x.begin(),lower_bound(x.begin(),x.end(),r))+length;\n\t\tfor(;\
    \ l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1) update(line,l),l++;\n\t\t\tif(r&1) --r,update(line,r);\n\
    \t\t}\n\t}\n\t\n\tinline TypeValue get(TypeValue t){\n\t\tint i = distance(x.begin(),lower_bound(x.begin(),x.end(),t))+length;\n\
    \t\tTypeValue res = Operator::unit_value;\n\t\tfor(;1<=i;i>>=1) if(!Operator::func_compare(res,f(node[i],t)))\
    \ res = f(node[i],t);\n\t\treturn res;\n\t}\n};\n#line 9 \"test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint length,Q;\
    \ cin >> length >> Q;\n\tvector<long long> A(length),B(length),L(length),R(length),E(Q),F(Q),C(Q),D(Q),S(Q),TypeValue(Q);\n\
    \tfor(int i = 0; i < length; ++i) {\n\t\tcin >> L[i] >> R[i] >> A[i] >> B[i];\n\
    \t}\n\tLiChaoTree<ValueMin<long long>> lct;\n\tfor(int i = 0; i < length; ++i)\
    \ lct.x_push_back(L[i]),lct.x_push_back(R[i]);\n\tfor(int i = 0; i < Q; ++i) {\n\
    \t\tcin >> E[i];\n\t\tif(E[i]) {\n\t\t\tcin >> F[i];\n\t\t\tlct.x_push_back(F[i]);\n\
    \t\t}\n\t\telse {\n\t\t\tcin >> S[i] >> TypeValue[i] >> C[i] >> D[i];\n\t\t\t\
    lct.x_push_back(S[i]);\n\t\t\tlct.x_push_back(TypeValue[i]);\n\t\t}\n\t}\n\tlct.build();\n\
    \tlong long inf = 3e18;\n\tfor(int i = 0; i < length; ++i) lct.update({A[i],B[i]},L[i],R[i]);\n\
    \tfor(int i = 0; i < Q; ++i) {\n\t\tif(E[i]) {\n\t\t\tlong long ans = lct.get(F[i]);\n\
    \t\t\tif(ans!=inf) cout << ans << endl;\n\t\t\telse cout << \"INFINITY\" << endl;\n\
    \t\t}\n\t\telse {\n\t\t\tlct.update({C[i],D[i]},S[i],TypeValue[i]);\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include <vector>\n#include <iostream>\n#include <algorithm>\nusing namespace\
    \ std;\n#include \"../../../lib/operator/operator/ValueMin.cpp\"\n#include \"\
    ../../../lib/data-structure/convex-hull-trick/LiChaoTree.cpp\"\n\nint main(void){\n\
    \tcin.tie(0);ios::sync_with_stdio(false);\n\tint length,Q; cin >> length >> Q;\n\
    \tvector<long long> A(length),B(length),L(length),R(length),E(Q),F(Q),C(Q),D(Q),S(Q),TypeValue(Q);\n\
    \tfor(int i = 0; i < length; ++i) {\n\t\tcin >> L[i] >> R[i] >> A[i] >> B[i];\n\
    \t}\n\tLiChaoTree<ValueMin<long long>> lct;\n\tfor(int i = 0; i < length; ++i)\
    \ lct.x_push_back(L[i]),lct.x_push_back(R[i]);\n\tfor(int i = 0; i < Q; ++i) {\n\
    \t\tcin >> E[i];\n\t\tif(E[i]) {\n\t\t\tcin >> F[i];\n\t\t\tlct.x_push_back(F[i]);\n\
    \t\t}\n\t\telse {\n\t\t\tcin >> S[i] >> TypeValue[i] >> C[i] >> D[i];\n\t\t\t\
    lct.x_push_back(S[i]);\n\t\t\tlct.x_push_back(TypeValue[i]);\n\t\t}\n\t}\n\tlct.build();\n\
    \tlong long inf = 3e18;\n\tfor(int i = 0; i < length; ++i) lct.update({A[i],B[i]},L[i],R[i]);\n\
    \tfor(int i = 0; i < Q; ++i) {\n\t\tif(E[i]) {\n\t\t\tlong long ans = lct.get(F[i]);\n\
    \t\t\tif(ans!=inf) cout << ans << endl;\n\t\t\telse cout << \"INFINITY\" << endl;\n\
    \t\t}\n\t\telse {\n\t\t\tlct.update({C[i],D[i]},S[i],TypeValue[i]);\n\t\t}\n\t\
    }\n}"
  dependsOn:
  - lib/operator/operator/ValueMin.cpp
  - lib/data-structure/convex-hull-trick/LiChaoTree.cpp
  isVerificationFile: true
  path: test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp
  requiredBy: []
  timestamp: '2021-04-26 09:17:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp
- /verify/test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp.html
title: test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp
---
