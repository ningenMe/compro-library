---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/StronglyConnectedComponents.cpp
    title: "StronglyConnectedComponents - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: lib/graph/UnionFindTree.cpp
    title: "UnionFindTree - Union Find \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1023
    links:
    - https://yukicoder.me/problems/no/1023
  bundledCode: "#line 1 \"test/graph/StronglyConnectedComponents-1.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1023\"\n\n#include <vector>\n#include\
    \ <iostream>\n#include <numeric>\n#include <algorithm>\n#include <stack>\nusing\
    \ namespace std;\n#line 1 \"lib/graph/UnionFindTree.cpp\"\n/*\n * @title UnionFindTree\
    \ - Union Find \u6728\n * @docs md/graph/UnionFindTree.md\n */\nclass UnionFindTree\
    \ {\n    vector<int> parent,maxi,mini;\n    inline int root(int n) {\n       \
    \ return (parent[n]<0?n:parent[n] = root(parent[n]));\n    }\npublic:\n    UnionFindTree(int\
    \ N = 1) : parent(N,-1),maxi(N),mini(N){\n        iota(maxi.begin(),maxi.end(),0);\n\
    \        iota(mini.begin(),mini.end(),0);\n    }\n    inline bool connected(int\
    \ n, int m) {\n        return root(n) == root(m);\n    }\n    inline void merge(int\
    \ n, int m) {\n        n = root(n);\n        m = root(m);\n        if (n == m)\
    \ return;\n        if(parent[n]>parent[m]) swap(n, m);\n        parent[n] += parent[m];\n\
    \        parent[m] = n;\n        maxi[n] = std::max(maxi[n],maxi[m]);\n      \
    \  mini[n] = std::min(mini[n],mini[m]);\n    }\n    inline int min(int n) {\n\
    \        return mini[root(n)];\n    }\n    inline int max(int n) {\n        return\
    \ maxi[root(n)];\n    }\n    inline int size(int n){\n        return (-parent[root(n)]);\n\
    \    }\n    inline int operator[](int n) {\n        return root(n);\n    }\n \
    \   inline void print() {\n        for(int i = 0; i < parent.size(); ++i) cout\
    \ << root(i) << \" \";\n        cout << endl;\n    }\n};\n#line 1 \"lib/graph/StronglyConnectedComponents.cpp\"\
    \n/*\n * @title StronglyConnectedComponents - \u5F37\u9023\u7D50\u6210\u5206\u5206\
    \u89E3\n * @docs md/graph/StronglyConnectedComponents.md\n */\nclass StronglyConnectedComponents{\n\
    \    int num,is_2sat,half,max_id,cnt;\n    vector<vector<int>> edge;\n    vector<int>\
    \ label,order,low;\n    stack<size_t> st;\n    inline int rev(int i) { return\
    \ i < half ? i + half : i - half; }\n    inline void dfs(int& from) {\n      \
    \  low[from]=order[from]=cnt++;\n        st.push(from);\n        for(int& to:edge[from])\
    \ {\n            if(order[to]==-1) {\n                dfs(to);\n             \
    \   low[from]=min(low[from],low[to]);\n            }\n            else {\n   \
    \             low[from]=min(low[from],order[to]);\n            }\n        }\n\
    \        if (low[from] == order[from]) {\n            while(st.size()) {\n   \
    \             int u = st.top();st.pop();\n                order[u] = num;\n  \
    \              label[u] = max_id;\n                if (u == from) break;\n   \
    \         }\n            max_id++;\n        }\n    }\npublic:\n    StronglyConnectedComponents(const\
    \ int n, bool is_2sat=0):num(n),max_id(0),cnt(0),is_2sat(is_2sat){\n        if(is_2sat)\
    \ num<<=1;\n        edge.resize(num);\n        label.resize(num);\n        order.resize(num,-1);\n\
    \        low.resize(num);\n        half=(num>>1);\n    }\n    inline int operator[](int\
    \ idx) {\n        return label[idx];\n    }\n    inline void make_edge(const int\
    \ from,const int to) {\n        edge[from].push_back(to);\n    }\n    //x\u304C\
    flg_x\u306A\u3089\u3070y\u304Cflg_y\n    inline void make_condition(int x, bool\
    \ flg_x, int y, bool flg_y) {\n        if (!flg_x) x = rev(x);\n        if (!flg_y)\
    \ y = rev(y);\n        make_edge(x, y);\n        make_edge(rev(y), rev(x));\n\
    \    }\n    //is_2sat=1\u306E\u3068\u304D\u306B\u30012sat\u3092\u6E80\u305F\u3059\
    \u304B\u3092\u8FD4\u5374\u3059\u308B\n    inline bool solve(void) {\n        for\
    \ (int i = 0; i < num; i++) if (order[i] == -1) dfs(i);\n        for (int& id:label)\
    \ id = max_id-1-id;\n        if(!is_2sat) return true;\n        for (int i = 0;\
    \ i < num; ++i) if (label[i] == label[rev(i)]) return false;\n        return true;\n\
    \    }\n    vector<vector<int>> topological_sort(void) {\n        vector<vector<int>>\
    \ ret(max_id);\n        for(int i=0;i<num;++i) ret[label[i]].push_back(i);\n \
    \       return ret;\n    }\n    int is_true(int i) {\n        return label[i]\
    \ > label[rev(i)];\n    }\n    void print(void) {\n        for(auto id:label)\
    \ cout << id << \" \";\n        cout << endl;\n    }\n};\n#line 11 \"test/graph/StronglyConnectedComponents-1.test.cpp\"\
    \n\nint main(){\n    int N,M; cin >> N >> M;\n    vector<pair<int,int>> edge;\n\
    \    vector<pair<int,int>> bedge;\n    for(int i = 0; i < M; ++i) {\n        int\
    \ a,b; cin >> a >> b;\n        a--,b--;\n        int c; cin >> c;\n        if(c==1){\n\
    \            bedge.push_back({a,b});\n        }\n        else{\n            edge.push_back({a,b});\n\
    \        }\n    }\n    UnionFindTree uf(N);\n    for(auto& e:bedge){\n       \
    \ int a = e.first,b = e.second;\n        if(uf.connected(a,b)){\n            cout\
    \ << \"Yes\" << endl;\n            return 0;\n        }\n        uf.merge(a,b);\n\
    \    }\n    StronglyConnectedComponents scc(N);\n    for(auto& e:edge){\n    \
    \    int a = e.first,b = e.second;\n        if(uf.connected(a,b)){\n         \
    \   cout << \"Yes\" << endl;\n            return 0;\n        }\n        scc.make_edge(uf[a],uf[b]);\n\
    \    }\n    scc.solve();\n    vector<int> cnt(N,0);\n    for(int i = 0; i < N;\
    \ ++i) cnt[scc[i]]++;\n    for(int i = 0; i < N; ++i) if(cnt[i] > 1){\n      \
    \  cout << \"Yes\" << endl;\n        return 0;\n    }\n    cout << \"No\" << endl;\
    \ \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1023\"\n\n#include <vector>\n\
    #include <iostream>\n#include <numeric>\n#include <algorithm>\n#include <stack>\n\
    using namespace std;\n#include \"../../lib/graph/UnionFindTree.cpp\"\n#include\
    \ \"../../lib/graph/StronglyConnectedComponents.cpp\"\n\nint main(){\n    int\
    \ N,M; cin >> N >> M;\n    vector<pair<int,int>> edge;\n    vector<pair<int,int>>\
    \ bedge;\n    for(int i = 0; i < M; ++i) {\n        int a,b; cin >> a >> b;\n\
    \        a--,b--;\n        int c; cin >> c;\n        if(c==1){\n            bedge.push_back({a,b});\n\
    \        }\n        else{\n            edge.push_back({a,b});\n        }\n   \
    \ }\n    UnionFindTree uf(N);\n    for(auto& e:bedge){\n        int a = e.first,b\
    \ = e.second;\n        if(uf.connected(a,b)){\n            cout << \"Yes\" <<\
    \ endl;\n            return 0;\n        }\n        uf.merge(a,b);\n    }\n   \
    \ StronglyConnectedComponents scc(N);\n    for(auto& e:edge){\n        int a =\
    \ e.first,b = e.second;\n        if(uf.connected(a,b)){\n            cout << \"\
    Yes\" << endl;\n            return 0;\n        }\n        scc.make_edge(uf[a],uf[b]);\n\
    \    }\n    scc.solve();\n    vector<int> cnt(N,0);\n    for(int i = 0; i < N;\
    \ ++i) cnt[scc[i]]++;\n    for(int i = 0; i < N; ++i) if(cnt[i] > 1){\n      \
    \  cout << \"Yes\" << endl;\n        return 0;\n    }\n    cout << \"No\" << endl;\
    \ \n    return 0;\n}\n"
  dependsOn:
  - lib/graph/UnionFindTree.cpp
  - lib/graph/StronglyConnectedComponents.cpp
  isVerificationFile: true
  path: test/graph/StronglyConnectedComponents-1.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:35:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/StronglyConnectedComponents-1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/StronglyConnectedComponents-1.test.cpp
- /verify/test/graph/StronglyConnectedComponents-1.test.cpp.html
title: test/graph/StronglyConnectedComponents-1.test.cpp
---
