---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/StronglyConnectedComponents.cpp
    title: StronglyConnectedComponents
  - icon: ':x:'
    path: lib/graph/MinimumDirectedClosedCircuit.cpp
    title: MinimumDirectedClosedCircuit
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/graph/MinimumDirectedClosedCircuit.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n#define IGNORE\n\
    \n#include <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n\
    #include <queue>\n#include <map>\nusing namespace std;\n#line 1 \"lib/graph/StronglyConnectedComponents.cpp\"\
    \n/*\n * @title StronglyConnectedComponents\n */\nclass StronglyConnectedComponents{\n\
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
    \t}\n};\n#line 1 \"lib/graph/MinimumDirectedClosedCircuit.cpp\"\n/*\n * @title\
    \ MinimumDirectedClosedCircuit\n * @docs md/graph/MinimumDirectedClosedCircuit.md\n\
    \ */\nclass MinimumDirectedClosedCircuit {\n\tvector<vector<int>> edge,redge;\
    \  \n\tvector<int> dist;\n\tsize_t N;\npublic:\n\tMinimumDirectedClosedCircuit(size_t\
    \ N) : N(N),edge(N),redge(N),dist(N) {\n\t\t//do nothing\n\t}\n\tinline void make_edge(int\
    \ from,int to){\n\t\tedge[from].push_back(to);\n\t\tredge[to].push_back(from);\n\
    \t}\n\t//root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\u306E\u96C6\u5408\u3092\
    \u8FD4\u3059 O(N) \u9589\u8DEF\u304C\u306A\u3044\u3068\u304D\u306F\u7A7A\u96C6\
    \u5408\n\tinline vector<int> solve(int root,int inf = 123456789){\n\t\tint mini\
    \ = inf, last = -1;\n\t\tfor(int i = 0; i < N; ++i) dist[i] = -1;\n\t\tqueue<int>\
    \ q;\n\t\tq.push(root);\n\t\tdist[root] = 0;\n\t\twhile (q.size()) {\n\t\t\tint\
    \ curr = q.front();\n\t\t\tq.pop();\n\t\t\tfor(int next:edge[curr]){\n\t\t\t\t\
    if(next == root && mini > dist[curr]+1) mini = dist[curr]+1,last = curr;\n\t\t\
    \t\tif(dist[next]==-1) {\n\t\t\t\t\tdist[next] = dist[curr] + 1;\n\t\t\t\t\tq.push(next);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> res;\n\t\tif(last != -1){\n\t\t\tres.push_back(last);\n\
    \t\t\tint curr = last;\n\t\t\twhile(curr != root){\n\t\t\t\tfor(int next:redge[curr]){\n\
    \t\t\t\t\tif(dist[next]+1==dist[curr]) {\n\t\t\t\t\t\tres.push_back(next);\n\t\
    \t\t\t\t\tcurr = next;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\treverse(res.begin(),res.end());\n\t\t}\n\t\treturn res;\n\t}\n};\n#line 13\
    \ \"test/graph/MinimumDirectedClosedCircuit.test.cpp\"\n\nint main(){\n    int\
    \ N,M; cin >> N >> M;\n    StronglyConnectedComponents scc(N);\n    MinimumDirectedClosedCircuit\
    \ dcc(N);\n    map<pair<int,int>,int> mp;\n    for(int i = 0; i < M; ++i) {\n\
    \        int u,v; cin >> u >> v;\n        scc.make_edge(u,v);\n        dcc.make_edge(u,v);\n\
    \        mp[{u,v}]=i;\n    }\n    scc.solve();\n    vector<int> cnt(N,0);\n  \
    \  for(int i = 0; i < N; ++i) cnt[scc[i]]++;\n    if(*max_element(cnt.begin(),cnt.end())==1){\n\
    \t\tcout << -1 << endl;\n        return 0;\n    };\n    int label=max_element(cnt.begin(),cnt.end())-cnt.begin();\n\
    \    int root;\n    for(int i = 0; i < N; ++i) if(scc[i]==label) root=i;\n   \
    \ auto ans = dcc.solve(root);\n    int L = ans.size();\n    cout << L << endl;\n\
    \    for(int i = 0; i < L; ++i) cout << mp[{ans[i],ans[(i+1)%L]}] << endl;\n\t\
    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n#define\
    \ IGNORE\n\n#include <vector>\n#include <iostream>\n#include <numeric>\n#include\
    \ <algorithm>\n#include <queue>\n#include <map>\nusing namespace std;\n#include\
    \ \"../../lib/graph/StronglyConnectedComponents.cpp\"\n#include \"../../lib/graph/MinimumDirectedClosedCircuit.cpp\"\
    \n\nint main(){\n    int N,M; cin >> N >> M;\n    StronglyConnectedComponents\
    \ scc(N);\n    MinimumDirectedClosedCircuit dcc(N);\n    map<pair<int,int>,int>\
    \ mp;\n    for(int i = 0; i < M; ++i) {\n        int u,v; cin >> u >> v;\n   \
    \     scc.make_edge(u,v);\n        dcc.make_edge(u,v);\n        mp[{u,v}]=i;\n\
    \    }\n    scc.solve();\n    vector<int> cnt(N,0);\n    for(int i = 0; i < N;\
    \ ++i) cnt[scc[i]]++;\n    if(*max_element(cnt.begin(),cnt.end())==1){\n\t\tcout\
    \ << -1 << endl;\n        return 0;\n    };\n    int label=max_element(cnt.begin(),cnt.end())-cnt.begin();\n\
    \    int root;\n    for(int i = 0; i < N; ++i) if(scc[i]==label) root=i;\n   \
    \ auto ans = dcc.solve(root);\n    int L = ans.size();\n    cout << L << endl;\n\
    \    for(int i = 0; i < L; ++i) cout << mp[{ans[i],ans[(i+1)%L]}] << endl;\n\t\
    return 0;\n}\n"
  dependsOn:
  - lib/graph/StronglyConnectedComponents.cpp
  - lib/graph/MinimumDirectedClosedCircuit.cpp
  isVerificationFile: true
  path: test/graph/MinimumDirectedClosedCircuit.test.cpp
  requiredBy: []
  timestamp: '2020-09-10 02:59:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/MinimumDirectedClosedCircuit.test.cpp
layout: document
redirect_from:
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp.html
title: test/graph/MinimumDirectedClosedCircuit.test.cpp
---
