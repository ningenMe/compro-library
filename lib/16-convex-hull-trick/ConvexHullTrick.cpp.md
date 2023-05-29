---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/convex-hull-trick/ConvexHullTrick.md
    document_title: "ConvexHullTrick - \u975E\u5358\u8ABFCHT"
    links: []
  bundledCode: "#line 1 \"lib/16-convex-hull-trick/ConvexHullTrick.cpp\"\n/*\n * @title\
    \ ConvexHullTrick - \u975E\u5358\u8ABFCHT\n * @docs md/convex-hull-trick/ConvexHullTrick.md\n\
    \ */\ntemplate<class Operator> class ConvexHullTrick {\nprivate:\n    using TypeValue\
    \ = typename Operator::TypeValue;\n    using Line = pair<TypeValue,TypeValue>;\n\
    \    struct Monoid {\n        using TypeNode = Line;\n        inline static constexpr\
    \ TypeNode unit_node = {0,0};\n        inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return {0,0};}\n    };\n    RandomizedBinarySearchTree<Monoid>\
    \ lines;\n\n    //3\u76F4\u7DDA\u306B\u95A2\u3057\u3066line2\u304C\u5FC5\u8981\
    \u304B\u78BA\u8A8D (\u3053\u306E\u3068\u304D a1 < a2 < a3\u304C\u5FC5\u8981=rbst\u306E\
    \u9806\u305D\u306E\u307E\u307E)\n    inline int is_required(const Line& line1,\
    \ const Line& line2, const Line& line3) {\n        return Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \    }\n\n    //y=ax+b\u306E\u5024\n    inline TypeValue y(const Line line, TypeValue\
    \ x) {\n        return line.first * x + line.second;\n    }\n\npublic:\n    ConvexHullTrick()\
    \ {\n        // do nothing\n    }\n\n    //ax+b\u3092\u8FFD\u52A0\n    void insert(const\
    \ TypeValue a, const TypeValue b) {\n        insert({a,b});\n    }\n    //ax+b\u3092\
    \u8FFD\u52A0 armortized O(log(N))\n    void insert(const Line line) {\n      \
    \  int k=lines.lower_bound(line), flg=1;\n        Line l,r;\n        if(0 <= k-1)\
    \ {\n            l = lines.get(k-1);\n            //l\u3068\u50BE\u304D\u304C\u540C\
    \u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n            if(l.first==line.first)\
    \ {\n                if(Operator::func_compare(l.second,line.second)) return;\n\
    \                else lines.erase(l);\n            }\n        }\n        if(k\
    \ < lines.size()) {\n            r = lines.get(k);\n            //r\u3068\u50BE\
    \u304D\u304C\u540C\u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n\
    \            if(r.first==line.first) {\n                if(Operator::func_compare(r.second,line.second))\
    \ return;\n                else lines.erase(r);\n            }\n        }\n  \
    \      //\u81EA\u8EAB\u304C\u5FC5\u8981\u304B\u5224\u5B9A\n        if(0 <= k-1\
    \ && k < lines.size() && !is_required(l,line,r)) return;\n        //\u50BE\u304D\
    \u304C\u5C0F\u3055\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\u76F4\u7DDA\u3092\
    \u53D6\u308A\u9664\u304F\n        for(k=lines.lower_bound(line);k>=2&&!is_required(lines.get(k-2),\
    \ lines.get(k-1), line);k=lines.lower_bound(line)) lines.erase(lines.get(k-1));\n\
    \        //\u50BE\u304D\u304C\u5927\u304D\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n        for(k=lines.lower_bound(line);k+1<lines.size()&&!is_required(line,lines.get(k),lines.get(k+1));k=lines.lower_bound(line))\
    \ lines.erase(lines.get(k));\n        lines.insert(line);\n    }\n\n    //O(log(N)^2)\n\
    \    TypeValue get(TypeValue x) {\n        int ng = -1, ok = (int)lines.size()-1,\
    \ md;\n        while (ok - ng > 1) {\n            md = (ok + ng) >> 1;\n     \
    \       ( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x)) ?ok:ng)=md;\n\
    \        }\n        return y(lines.get(ok),x);\n    }\n\n    //O(log(N)^2)\n \
    \   Line get_line(TypeValue x) {\n        int ng = -1, ok = (int)lines.size()-1,\
    \ md;\n        while (ok - ng > 1) {\n            md = (ok + ng) >> 1;\n     \
    \       ( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x)) ?ok:ng)=md;\n\
    \        }\n        return lines.get(ok);\n    }\n\n    void print() {\n     \
    \   lines.print();\n    }\n};\n"
  code: "/*\n * @title ConvexHullTrick - \u975E\u5358\u8ABFCHT\n * @docs md/convex-hull-trick/ConvexHullTrick.md\n\
    \ */\ntemplate<class Operator> class ConvexHullTrick {\nprivate:\n    using TypeValue\
    \ = typename Operator::TypeValue;\n    using Line = pair<TypeValue,TypeValue>;\n\
    \    struct Monoid {\n        using TypeNode = Line;\n        inline static constexpr\
    \ TypeNode unit_node = {0,0};\n        inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return {0,0};}\n    };\n    RandomizedBinarySearchTree<Monoid>\
    \ lines;\n\n    //3\u76F4\u7DDA\u306B\u95A2\u3057\u3066line2\u304C\u5FC5\u8981\
    \u304B\u78BA\u8A8D (\u3053\u306E\u3068\u304D a1 < a2 < a3\u304C\u5FC5\u8981=rbst\u306E\
    \u9806\u305D\u306E\u307E\u307E)\n    inline int is_required(const Line& line1,\
    \ const Line& line2, const Line& line3) {\n        return Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \    }\n\n    //y=ax+b\u306E\u5024\n    inline TypeValue y(const Line line, TypeValue\
    \ x) {\n        return line.first * x + line.second;\n    }\n\npublic:\n    ConvexHullTrick()\
    \ {\n        // do nothing\n    }\n\n    //ax+b\u3092\u8FFD\u52A0\n    void insert(const\
    \ TypeValue a, const TypeValue b) {\n        insert({a,b});\n    }\n    //ax+b\u3092\
    \u8FFD\u52A0 armortized O(log(N))\n    void insert(const Line line) {\n      \
    \  int k=lines.lower_bound(line), flg=1;\n        Line l,r;\n        if(0 <= k-1)\
    \ {\n            l = lines.get(k-1);\n            //l\u3068\u50BE\u304D\u304C\u540C\
    \u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n            if(l.first==line.first)\
    \ {\n                if(Operator::func_compare(l.second,line.second)) return;\n\
    \                else lines.erase(l);\n            }\n        }\n        if(k\
    \ < lines.size()) {\n            r = lines.get(k);\n            //r\u3068\u50BE\
    \u304D\u304C\u540C\u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n\
    \            if(r.first==line.first) {\n                if(Operator::func_compare(r.second,line.second))\
    \ return;\n                else lines.erase(r);\n            }\n        }\n  \
    \      //\u81EA\u8EAB\u304C\u5FC5\u8981\u304B\u5224\u5B9A\n        if(0 <= k-1\
    \ && k < lines.size() && !is_required(l,line,r)) return;\n        //\u50BE\u304D\
    \u304C\u5C0F\u3055\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\u76F4\u7DDA\u3092\
    \u53D6\u308A\u9664\u304F\n        for(k=lines.lower_bound(line);k>=2&&!is_required(lines.get(k-2),\
    \ lines.get(k-1), line);k=lines.lower_bound(line)) lines.erase(lines.get(k-1));\n\
    \        //\u50BE\u304D\u304C\u5927\u304D\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n        for(k=lines.lower_bound(line);k+1<lines.size()&&!is_required(line,lines.get(k),lines.get(k+1));k=lines.lower_bound(line))\
    \ lines.erase(lines.get(k));\n        lines.insert(line);\n    }\n\n    //O(log(N)^2)\n\
    \    TypeValue get(TypeValue x) {\n        int ng = -1, ok = (int)lines.size()-1,\
    \ md;\n        while (ok - ng > 1) {\n            md = (ok + ng) >> 1;\n     \
    \       ( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x)) ?ok:ng)=md;\n\
    \        }\n        return y(lines.get(ok),x);\n    }\n\n    //O(log(N)^2)\n \
    \   Line get_line(TypeValue x) {\n        int ng = -1, ok = (int)lines.size()-1,\
    \ md;\n        while (ok - ng > 1) {\n            md = (ok + ng) >> 1;\n     \
    \       ( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x)) ?ok:ng)=md;\n\
    \        }\n        return lines.get(ok);\n    }\n\n    void print() {\n     \
    \   lines.print();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/16-convex-hull-trick/ConvexHullTrick.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/16-convex-hull-trick/ConvexHullTrick.cpp
layout: document
redirect_from:
- /library/lib/16-convex-hull-trick/ConvexHullTrick.cpp
- /library/lib/16-convex-hull-trick/ConvexHullTrick.cpp.html
title: "ConvexHullTrick - \u975E\u5358\u8ABFCHT"
---
