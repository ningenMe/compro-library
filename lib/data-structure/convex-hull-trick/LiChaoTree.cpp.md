---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/data-structure/segment/convex-hull-trick/LiChaoTree.md
    document_title: LiChaoTree
    links: []
  bundledCode: "#line 1 \"lib/data-structure/convex-hull-trick/LiChaoTree.cpp\"\n\
    /*\n * @title LiChaoTree\n * @docs md/data-structure/segment/convex-hull-trick/LiChaoTree.md\n\
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
    \ res = f(node[i],t);\n        return res;\n    }\n};\n"
  code: "/*\n * @title LiChaoTree\n * @docs md/data-structure/segment/convex-hull-trick/LiChaoTree.md\n\
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
    \ res = f(node[i],t);\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/convex-hull-trick/LiChaoTree.cpp
  requiredBy: []
  timestamp: '2021-09-21 03:50:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/convex-hull-trick/LiChaoTree.cpp
layout: document
redirect_from:
- /library/lib/data-structure/convex-hull-trick/LiChaoTree.cpp
- /library/lib/data-structure/convex-hull-trick/LiChaoTree.cpp.html
title: LiChaoTree
---
