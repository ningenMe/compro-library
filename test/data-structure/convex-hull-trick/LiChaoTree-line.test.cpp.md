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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <algorithm>\nusing namespace std;\n\n\
    #line 1 \"lib/operator/operator/ValueMin.cpp\"\n//\u6700\u5C0F\u5024\u30AF\u30A8\
    \u30EA\ntemplate<class T> struct ValueMin {\n\tusing TypeValue = T;\n\tinline\
    \ static constexpr TypeValue unit_value = 3e18;\n\tinline static constexpr bool\
    \ func_compare(TypeValue l,TypeValue r){return l<r;}\n};\n#line 1 \"lib/data-structure/convex-hull-trick/LiChaoTree.cpp\"\
    \n/*\n * @title LiChaoTree\n * @docs md/data-structure/segment/convex-hull-trick/LiChaoTree.md\n\
    \ */\ntemplate <typename Operator> class LiChaoTree{\n    using TypeValue = typename\
    \ Operator::TypeValue;\n    using Line = pair<TypeValue,TypeValue>;\n    vector<TypeValue>\
    \ x;\n    vector<Line> node;\n    vector<int> clz;\n    size_t length;\n    const\
    \ size_t bit;\npublic:\n    LiChaoTree(const size_t bit=30):bit(bit){\n      \
    \  //do nothing\n    }\n    inline void build(){\n        sort(x.begin(),x.end());\n\
    \        x.erase(unique(x.begin(),x.end()),x.end());\n        TypeValue maxi =\
    \ x.back() + 1;\n        for (length = 1; length < x.size(); length *= 2);\n \
    \       x.resize(length, maxi);\n        node.resize(2*length,make_pair(0,Operator::unit_value));\n\
    \        clz.resize(2*length,32);\n        for(size_t i = 1; i < 2*length; ++i)\
    \ {\n            // for(int j = 0; j < bit; ++j) if(i&(1<<j)) clz[i] = 31-j;\n\
    \            clz[i] = __builtin_clz(i);\n        }\n    }\n\n    void x_push_back(TypeValue\
    \ argx){\n        x.push_back(argx);\n    }\n\n    //return y = ax+b\n    inline\
    \ static constexpr TypeValue f(Line& line,TypeValue& t)\t{\n        return line.first*t\
    \ + line.second;\n    }\n\n    inline void update(Line line,int i = 1){\n    \
    \    while(i < 2*length){\n            int l = (i<<(clz[i]-clz[length]))-length;\n\
    \            int r = l + (length>>(31-clz[i])) - 1;\n            int m = (l+r)>>1;\n\
    \            bool flgl = Operator::func_compare(f(line,x[l]),f(node[i],x[l]));\n\
    \            bool flgm = Operator::func_compare(f(line,x[m]),f(node[i],x[m]));\n\
    \            bool flgr = Operator::func_compare(f(line,x[r]),f(node[i],x[r]));\n\
    \n            if(flgl&&flgr) node[i] = line;\n            if(flgl==flgr) break;\n\
    \            if(flgm) swap(node[i],line),swap(flgl,flgr);\n            i = (i<<1)+flgr;\n\
    \        }\n    }\n    inline void update(Line line,TypeValue l,TypeValue r){\n\
    \        l = distance(x.begin(),lower_bound(x.begin(),x.end(),l))+length;\n  \
    \      r = distance(x.begin(),lower_bound(x.begin(),x.end(),r))+length;\n    \
    \    for(; l < r; l >>=1, r >>=1) {\n            if(l&1) update(line,l),l++;\n\
    \            if(r&1) --r,update(line,r);\n        }\n    }\n\n    inline TypeValue\
    \ get(TypeValue t){\n        int i = distance(x.begin(),lower_bound(x.begin(),x.end(),t))+length;\n\
    \        TypeValue res = Operator::unit_value;\n        for(;1<=i;i>>=1) if(!Operator::func_compare(res,f(node[i],t)))\
    \ res = f(node[i],t);\n        return res;\n    }\n};\n#line 10 \"test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin\
    \ >> N >> Q;\n\tvector<long long> A(N),B(N),C(Q),D(Q),E(Q);\n\tfor(int i = 0;\
    \ i < N; ++i) cin >> A[i] >> B[i];\n\tLiChaoTree<ValueMin<long long>> lct;\n\t\
    for(int i = 0; i < Q; ++i) {\n\t\tcin >> C[i];\n\t\tif(C[i]) {\n\t\t\tcin >> D[i];\n\
    \t\t\tlct.x_push_back(D[i]);\n\t\t}\n\t\telse {\n\t\t\tcin >> D[i] >> E[i];\n\t\
    \t}\n\t}\n\tlct.build();\n\tfor(int i = 0; i < N; ++i) lct.update({A[i],B[i]});\n\
    \tlong long inf = 3e18;\n\tfor(int i = 0; i < Q; ++i) {\n\t\tif(C[i]) {\n\t\t\t\
    long long ans = lct.get(D[i]);\n\t\t\tif(ans!=inf) cout << ans << endl;\n\t\t\t\
    else cout << \"INFINITY\" << endl;\n\t\t}\n\t\telse {\n\t\t\tlct.update({D[i],E[i]});\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <vector>\n#include <iostream>\n#include <algorithm>\nusing namespace\
    \ std;\n\n#include \"../../../lib/operator/operator/ValueMin.cpp\"\n#include \"\
    ../../../lib/data-structure/convex-hull-trick/LiChaoTree.cpp\"\n\nint main(void){\n\
    \tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin >> N >> Q;\n\tvector<long\
    \ long> A(N),B(N),C(Q),D(Q),E(Q);\n\tfor(int i = 0; i < N; ++i) cin >> A[i] >>\
    \ B[i];\n\tLiChaoTree<ValueMin<long long>> lct;\n\tfor(int i = 0; i < Q; ++i)\
    \ {\n\t\tcin >> C[i];\n\t\tif(C[i]) {\n\t\t\tcin >> D[i];\n\t\t\tlct.x_push_back(D[i]);\n\
    \t\t}\n\t\telse {\n\t\t\tcin >> D[i] >> E[i];\n\t\t}\n\t}\n\tlct.build();\n\t\
    for(int i = 0; i < N; ++i) lct.update({A[i],B[i]});\n\tlong long inf = 3e18;\n\
    \tfor(int i = 0; i < Q; ++i) {\n\t\tif(C[i]) {\n\t\t\tlong long ans = lct.get(D[i]);\n\
    \t\t\tif(ans!=inf) cout << ans << endl;\n\t\t\telse cout << \"INFINITY\" << endl;\n\
    \t\t}\n\t\telse {\n\t\t\tlct.update({D[i],E[i]});\n\t\t}\n\t}\n}"
  dependsOn:
  - lib/operator/operator/ValueMin.cpp
  - lib/data-structure/convex-hull-trick/LiChaoTree.cpp
  isVerificationFile: true
  path: test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 04:20:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp
- /verify/test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp.html
title: test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp
---
