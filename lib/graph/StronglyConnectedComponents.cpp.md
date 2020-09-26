---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/StronglyConnectedComponents-2sat.test.cpp
    title: test/graph/StronglyConnectedComponents-2sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/StronglyConnectedComponents-2.test.cpp
    title: test/graph/StronglyConnectedComponents-2.test.cpp
  - icon: ':x:'
    path: test/graph/MinimumDirectedClosedCircuit.test.cpp
    title: test/graph/MinimumDirectedClosedCircuit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/StronglyConnectedComponents-1.test.cpp
    title: test/graph/StronglyConnectedComponents-1.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/graph/StronglyConnectedComponents.md
    document_title: "StronglyConnectedComponents - \u5F37\u9023\u7D50\u6210\u5206\u5206\
      \u89E3"
    links: []
  bundledCode: "#line 1 \"lib/graph/StronglyConnectedComponents.cpp\"\n/*\n * @title\
    \ StronglyConnectedComponents - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n *\
    \ @docs md/graph/StronglyConnectedComponents.md\n */\nclass StronglyConnectedComponents{\n\
    \tint num,is_2sat,half,max_id,cnt;\n\tvector<vector<int>> edge;\n\tvector<int>\
    \ label,order,low;\n    stack<size_t> st;\n\tinline int rev(int i) { return i\
    \ < half ? i + half : i - half; }\n    inline void dfs(int& from) {\n        low[from]=order[from]=cnt++;\n\
    \        st.push(from);\n        for(int& to:edge[from]) {\n            if(order[to]==-1)\
    \ {\n                dfs(to);\n                low[from]=min(low[from],low[to]);\n\
    \            }\n            else {\n                low[from]=min(low[from],order[to]);\n\
    \            }\n        }\n        if (low[from] == order[from]) {\n         \
    \   while(st.size()) {\n                int u = st.top();st.pop();\n         \
    \       order[u] = num;\n                label[u] = max_id;\n                if\
    \ (u == from) break;\n            }\n            max_id++;\n        }\n    }\n\
    public:\n\tStronglyConnectedComponents(const int n, bool is_2sat=0):num(n),max_id(0),cnt(0),is_2sat(is_2sat){\n\
    \t\tif(is_2sat) num<<=1;\n\t\tedge.resize(num);\n\t\tlabel.resize(num);\n    \
    \    order.resize(num,-1);\n        low.resize(num);\n        half=(num>>1);\n\
    \t}\n\tinline int operator[](int idx) {\n\t\treturn label[idx];\n\t}\n\tinline\
    \ void make_edge(const int from,const int to) {\n\t\tedge[from].push_back(to);\n\
    \t}\n    //x\u304Cflg_x\u306A\u3089\u3070y\u304Cflg_y\n\tinline void make_condition(int\
    \ x, bool flg_x, int y, bool flg_y) {\n\t\tif (!flg_x) x = rev(x);\n\t\tif (!flg_y)\
    \ y = rev(y);\n\t\tmake_edge(x, y);\n\t\tmake_edge(rev(y), rev(x));\n\t}\n   \
    \ //is_2sat=1\u306E\u3068\u304D\u306B\u30012sat\u3092\u6E80\u305F\u3059\u304B\u3092\
    \u8FD4\u5374\u3059\u308B\n\tinline bool solve(void) {\n        for (int i = 0;\
    \ i < num; i++) if (order[i] == -1) dfs(i);\n        for (int& id:label) id =\
    \ max_id-1-id;\n\t\tif(!is_2sat) return true;\n\t\tfor (int i = 0; i < num; ++i)\
    \ if (label[i] == label[rev(i)]) return false;\n\t\treturn true;\n\t}\n    vector<vector<int>>\
    \ topological_sort(void) {\n        vector<vector<int>> ret(max_id);\n       \
    \ for(int i=0;i<num;++i) ret[label[i]].push_back(i);\n        return ret;\n  \
    \  }\n\tint is_true(int i) {\n\t\treturn label[i] > label[rev(i)];\n\t}\n\tvoid\
    \ print(void) {\n\t\tfor(auto id:label) cout << id << \" \";\n\t\tcout << endl;\n\
    \t}\n};\n"
  code: "/*\n * @title StronglyConnectedComponents - \u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\n * @docs md/graph/StronglyConnectedComponents.md\n */\nclass StronglyConnectedComponents{\n\
    \tint num,is_2sat,half,max_id,cnt;\n\tvector<vector<int>> edge;\n\tvector<int>\
    \ label,order,low;\n    stack<size_t> st;\n\tinline int rev(int i) { return i\
    \ < half ? i + half : i - half; }\n    inline void dfs(int& from) {\n        low[from]=order[from]=cnt++;\n\
    \        st.push(from);\n        for(int& to:edge[from]) {\n            if(order[to]==-1)\
    \ {\n                dfs(to);\n                low[from]=min(low[from],low[to]);\n\
    \            }\n            else {\n                low[from]=min(low[from],order[to]);\n\
    \            }\n        }\n        if (low[from] == order[from]) {\n         \
    \   while(st.size()) {\n                int u = st.top();st.pop();\n         \
    \       order[u] = num;\n                label[u] = max_id;\n                if\
    \ (u == from) break;\n            }\n            max_id++;\n        }\n    }\n\
    public:\n\tStronglyConnectedComponents(const int n, bool is_2sat=0):num(n),max_id(0),cnt(0),is_2sat(is_2sat){\n\
    \t\tif(is_2sat) num<<=1;\n\t\tedge.resize(num);\n\t\tlabel.resize(num);\n    \
    \    order.resize(num,-1);\n        low.resize(num);\n        half=(num>>1);\n\
    \t}\n\tinline int operator[](int idx) {\n\t\treturn label[idx];\n\t}\n\tinline\
    \ void make_edge(const int from,const int to) {\n\t\tedge[from].push_back(to);\n\
    \t}\n    //x\u304Cflg_x\u306A\u3089\u3070y\u304Cflg_y\n\tinline void make_condition(int\
    \ x, bool flg_x, int y, bool flg_y) {\n\t\tif (!flg_x) x = rev(x);\n\t\tif (!flg_y)\
    \ y = rev(y);\n\t\tmake_edge(x, y);\n\t\tmake_edge(rev(y), rev(x));\n\t}\n   \
    \ //is_2sat=1\u306E\u3068\u304D\u306B\u30012sat\u3092\u6E80\u305F\u3059\u304B\u3092\
    \u8FD4\u5374\u3059\u308B\n\tinline bool solve(void) {\n        for (int i = 0;\
    \ i < num; i++) if (order[i] == -1) dfs(i);\n        for (int& id:label) id =\
    \ max_id-1-id;\n\t\tif(!is_2sat) return true;\n\t\tfor (int i = 0; i < num; ++i)\
    \ if (label[i] == label[rev(i)]) return false;\n\t\treturn true;\n\t}\n    vector<vector<int>>\
    \ topological_sort(void) {\n        vector<vector<int>> ret(max_id);\n       \
    \ for(int i=0;i<num;++i) ret[label[i]].push_back(i);\n        return ret;\n  \
    \  }\n\tint is_true(int i) {\n\t\treturn label[i] > label[rev(i)];\n\t}\n\tvoid\
    \ print(void) {\n\t\tfor(auto id:label) cout << id << \" \";\n\t\tcout << endl;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/StronglyConnectedComponents.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:13:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/StronglyConnectedComponents-2sat.test.cpp
  - test/graph/StronglyConnectedComponents-2.test.cpp
  - test/graph/MinimumDirectedClosedCircuit.test.cpp
  - test/graph/StronglyConnectedComponents-1.test.cpp
documentation_of: lib/graph/StronglyConnectedComponents.cpp
layout: document
redirect_from:
- /library/lib/graph/StronglyConnectedComponents.cpp
- /library/lib/graph/StronglyConnectedComponents.cpp.html
title: "StronglyConnectedComponents - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
