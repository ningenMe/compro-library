---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/convex-hull-trick/ConvexHullTrickMonotone.cpp
    title: "ConvexHullTrickMonotone - \u5358\u8ABFCHT"
  - icon: ':heavy_check_mark:'
    path: lib/operator/operator/ValueMax.cpp
    title: lib/operator/operator/ValueMax.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/409
    links:
    - https://yukicoder.me/problems/no/409
  bundledCode: "#line 1 \"test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/409\"\n\n#include <iostream>\n\
    #include <vector>\n#include <queue>\n#include <cassert>\nusing namespace std;\n\
    #line 1 \"lib/operator/operator/ValueMax.cpp\"\n//\u6700\u5927\u5024\u30AF\u30A8\
    \u30EA\ntemplate<class T> struct ValueMax {\n\tusing TypeValue = T;\n\tinline\
    \ static constexpr TypeValue unit_value = -3e18;\n\tinline static constexpr bool\
    \ func_compare(TypeValue l,TypeValue r){return l>r;}\n};\n#line 1 \"lib/data-structure/convex-hull-trick/ConvexHullTrickMonotone.cpp\"\
    \n/*\n * @title ConvexHullTrickMonotone - \u5358\u8ABFCHT\n * @docs md/data-structure/convex-hull-trick/ConvexHullTrickMonotone.md\n\
    \ */\ntemplate<class Operator> class ConvexHullTrickMonotone {\nprivate:\n   \
    \ using TypeValue = typename Operator::TypeValue;\n\n    //front->back\u306B\u5411\
    \u304B\u3063\u3066\u50BE\u304D\u304Ca1<a2<...<aN\n    deque<pair<TypeValue,TypeValue>>\
    \ lines;\n\n    //3\u76F4\u7DDA\u306B\u95A2\u3057\u3066line2\u304C\u5FC5\u8981\
    \u304B\u78BA\u8A8D (\u3053\u306E\u3068\u304D a1 < a2 < a3\u304C\u5FC5\u8981=deque\u306E\
    \u9806\u305D\u306E\u307E\u307E)\n    inline int is_required(const pair<TypeValue,TypeValue>&\
    \ line1, const pair<TypeValue,TypeValue>& line2, const pair<TypeValue,TypeValue>&\
    \ line3) {\n        return Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \    }\n\n    //y=ax+b\u306E\u5024\n    inline TypeValue y(const pair<TypeValue,TypeValue>\
    \ line, TypeValue x) {\n        return line.first * x + line.second;\n    }\n\n\
    \    inline void insert_back(const pair<TypeValue,TypeValue> line){\n        //\u50BE\
    \u304D\u304C\u540C\u3058\u3068\u304D\n        if(lines.size() && lines.back().first\
    \ == line.first){\n            if(Operator::func_compare(lines.back().second,line.second))\
    \ return;\n            else lines.pop_back();\n        }\n        //\u4E0D\u5FC5\
    \u8981\u306A\u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n        while (lines.size()\
    \ > 1 && !is_required(lines[(int)lines.size()-2], lines[(int)lines.size()-1],line))\
    \ lines.pop_back();\n        //back\u306Binsert\n        lines.push_back(line);\n\
    \    }\n    inline void insert_front(const pair<TypeValue,TypeValue> line){\n\
    \        //\u50BE\u304D\u304C\u540C\u3058\u3068\u304D\n        if(lines.size()\
    \ && lines.front().first == line.first){\n            if(Operator::func_compare(lines.front().second,line.second))\
    \ return;\n            else lines.pop_front();\n        }\n        //\u4E0D\u5FC5\
    \u8981\u306A\u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n        while (lines.size()\
    \ > 1 && !is_required(line, lines[0], lines[1])) lines.pop_front();\n        //front\u306B\
    insert\n        lines.push_front(line);\n    }\npublic:\n    ConvexHullTrickMonotone()\
    \ {\n        // do nothing\n    }\n    inline void insert(const TypeValue a, const\
    \ TypeValue b) {\n        insert({a,b});\n    }\n    //\u50BE\u304D\u306E\u5927\
    \u304D\u3055\u304C\u5E38\u306B\u6700\u5927or\u6700\u5C0F\u306B\u306A\u308B\u3088\
    \u3046\u306Binsert\u3059\u308B\n    inline void insert(const pair<TypeValue,TypeValue>\
    \ line) {\n        if(lines.empty() || line.first <= lines.front().first) insert_front(line);\n\
    \        else if(lines.back().first <= line.first) insert_back(line);\n      \
    \  else assert(false);\n    }\n    //O(log(N))\n    inline TypeValue get(TypeValue\
    \ x) {\n        if(lines.empty()) return Operator::unit_value;\n        int ng\
    \ = -1, ok = (int)lines.size()-1, md;\n        while (ok - ng > 1) {\n       \
    \     md = (ok + ng) >> 1;\n            ( Operator::func_compare(y(lines[md],x),y(lines[md+1],x))\
    \ ?ok:ng)=md;\n        }\n        return y(lines[ok],x);\n    }\n    //O(log(N))\n\
    \    inline pair<TypeValue,TypeValue> get_line(TypeValue x) {\n        if(lines.empty())\
    \ return {0,Operator::unit_value};\n        int ng = -1, ok = (int)lines.size()-1,\
    \ md;\n        while (ok - ng > 1) {\n            md = (ok + ng) >> 1;\n     \
    \       ( Operator::func_compare(y(lines[md],x),y(lines[md+1],x)) ?ok:ng)=md;\n\
    \        }\n        return lines[ok];\n    }\n    //O(N)\n    inline void clear(void)\
    \ {\n        lines.clear();\n    }\n};\n#line 10 \"test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp\"\
    \nusing ll = long long;\n\nint main(void){\n\tll N,A,B,W; cin >> N >> A >> B >>\
    \ W;\n\tvector<ll> D(N+2,0);\n\tfor(int i = 1; i <= N; ++i) cin >> D[i];\n\t//\
    \ dp[i]=min{j:[0,i)} -> dp[j]+B*k*(k+1)/2-k*A+D[i] (k=i-j-1)\n\t//           \
    \         -> dp[j]+B*(i-j-1)*(i-j)/2-(i-j-1)*A+D[i]\n\t//                    ->\
    \ dp[j]+B/2*(i*i-2*i*j+j*j-i+j)-A*(i-j-1)+D[i]\n\t//                    -> (-B*j)*i\
    \  +  dp[j]+B/2*(j*j+j)+A*j  +  B/2*(i*i-i)-A*(i-1)+D[i] \n\t// dp[i]=-max{j:[0,i)}->\
    \ (B*j)*i  +  -{dp[j]+B/2*(j*j+j)+A*j} \n\t//                    ->\n\tvector<ll>\
    \ dp(N+2,1e15);\n\tdp[0]=W;\n\tConvexHullTrickMonotone<ValueMax<ll>> cht;\n\t\
    cht.insert(0,-dp[0]);\n\tfor(ll i=1;i<=N+1;++i){\n\t\tdp[i]=-cht.get(i) + B*(i*i-i)/2-A*(i-1)+D[i];\n\
    \t\tcht.insert(B*i,-(dp[i]+B*(i*i+i)/2+A*i));\n\t}\n\tcout << dp[N+1] << endl;\n\
    \treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/409\"\n\n#include <iostream>\n\
    #include <vector>\n#include <queue>\n#include <cassert>\nusing namespace std;\n\
    #include \"../../../lib/operator/operator/ValueMax.cpp\"\n#include \"../../../lib/data-structure/convex-hull-trick/ConvexHullTrickMonotone.cpp\"\
    \nusing ll = long long;\n\nint main(void){\n\tll N,A,B,W; cin >> N >> A >> B >>\
    \ W;\n\tvector<ll> D(N+2,0);\n\tfor(int i = 1; i <= N; ++i) cin >> D[i];\n\t//\
    \ dp[i]=min{j:[0,i)} -> dp[j]+B*k*(k+1)/2-k*A+D[i] (k=i-j-1)\n\t//           \
    \         -> dp[j]+B*(i-j-1)*(i-j)/2-(i-j-1)*A+D[i]\n\t//                    ->\
    \ dp[j]+B/2*(i*i-2*i*j+j*j-i+j)-A*(i-j-1)+D[i]\n\t//                    -> (-B*j)*i\
    \  +  dp[j]+B/2*(j*j+j)+A*j  +  B/2*(i*i-i)-A*(i-1)+D[i] \n\t// dp[i]=-max{j:[0,i)}->\
    \ (B*j)*i  +  -{dp[j]+B/2*(j*j+j)+A*j} \n\t//                    ->\n\tvector<ll>\
    \ dp(N+2,1e15);\n\tdp[0]=W;\n\tConvexHullTrickMonotone<ValueMax<ll>> cht;\n\t\
    cht.insert(0,-dp[0]);\n\tfor(ll i=1;i<=N+1;++i){\n\t\tdp[i]=-cht.get(i) + B*(i*i-i)/2-A*(i-1)+D[i];\n\
    \t\tcht.insert(B*i,-(dp[i]+B*(i*i+i)/2+A*i));\n\t}\n\tcout << dp[N+1] << endl;\n\
    \treturn 0;\n}"
  dependsOn:
  - lib/operator/operator/ValueMax.cpp
  - lib/data-structure/convex-hull-trick/ConvexHullTrickMonotone.cpp
  isVerificationFile: true
  path: test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 04:20:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp
- /verify/test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp.html
title: test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp
---
