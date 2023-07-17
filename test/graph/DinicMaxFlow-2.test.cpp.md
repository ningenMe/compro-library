---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/40-graph/DinicMaxFlow.cpp
    title: "DinicMaxFlow - Dinic\u30D5\u30ED\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/957
    links:
    - https://yukicoder.me/problems/no/957
  bundledCode: "#line 1 \"test/graph/DinicMaxFlow-2.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/957\"\n\n#include <vector>\n#include <iostream>\n\
    #include <queue>\nusing namespace std;\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n\
    \ * @title FastIO\n * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n\
    \    inline static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    inline static constexpr int ch_n='-';\n    inline static constexpr int ch_s='\
    \ ';\n    inline static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
    \ ch) {\n        while(ch==ch_l) ch=getchar();\n    }\n    template<typename T>\
    \ inline static void read_integer(T &x) {\n        int neg=0; char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        if(ch==ch_n) neg=1,ch=getchar();\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \        if(neg) x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \    }\n    inline static void read_string(string &x) {\n        char ch; x=\"\
    \";\n        ch=getchar();\n        endline_skip(ch);\n        for(;(ch != ch_s\
    \ && ch!=ch_l); ch = getchar()) x.push_back(ch);\n    }\n    inline static char\
    \ ar[40];\n    inline static char *ch_ar;\n    template<typename T> inline static\
    \ void write_integer(T x) {\n        ch_ar=ar;\n        if(x< 0) putchar(ch_n),\
    \ x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n\
    \        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\npublic:\n    inline static\
    \ void read(int &x) {read_integer<int>(x);}\n    inline static void read(long\
    \ long &x) {read_integer<long long>(x);}\n    inline static void read(unsigned\
    \ int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline static void read(unsigned\
    \ long long &x) {read_unsigned_integer<unsigned long long>(x);}\n    inline static\
    \ void read(string &x) {read_string(x);}\n    inline static void read(__int128_t\
    \ &x) {read_integer<__int128_t>(x);}\n    inline static void write(__int128_t\
    \ x) {write_integer<__int128_t>(x);}\n    inline static void write(char x) {putchar(x);}\n\
    };\n#define read(arg) FastIO::read(arg)\n#define write(arg) FastIO::write(arg)\n\
    #line 1 \"lib/40-graph/DinicMaxFlow.cpp\"\n\n/*\n * @title DinicMaxFlow - Dinic\u30D5\
    \u30ED\u30FC\n * @docs md/graph/DinicMaxFlow.md\n */\ntemplate <class TypeFlow>\
    \ class DinicMaxFlow {\n\tstruct Edge {\n\t\tsize_t to, rev;\n\t\tTypeFlow cap;\n\
    \t};\n\tvector<vector<Edge>> edge;\n\tvector<int> level, iter;\n    TypeFlow inf_flow;\n\
    \n\tinline void bfs(const size_t start) {\n\t\tfor (int i = 0; i < level.size();\
    \ ++i) level[i] = -1;\n\t\tqueue<size_t> q;\n\t\tlevel[start] = 0;\n\t\tq.push(start);\n\
    \t\twhile (q.size()) {\n\t\t\tauto from = q.front();\n\t\t\tq.pop();\n\t\t\tfor\
    \ (auto& e : edge[from]) {\n\t\t\t\tif (e.cap > 0 && level[e.to] < 0) {\n\t\t\t\
    \t\tlevel[e.to] = level[from] + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n\n\tinline TypeFlow dfs(size_t from, size_t goal, TypeFlow flow)\
    \ {\n\t\tif (from == goal) return flow;\n\t\tfor (int& i = iter[from]; i < edge[from].size();\
    \ ++i) {\n            //TODO \u53C2\u7167\u304C\u52B9\u3044\u3066\u306A\u304F\u3066\
    \u5197\u9577\n\t\t\tauto& e = edge[from][i];\n\t\t\tif (e.cap <= 0 || level[from]\
    \ >= level[e.to]) continue;\n\t\t\tTypeFlow dflow = dfs(e.to, goal, min(flow,\
    \ e.cap));\n\t\t\tif (dflow <= 0) continue;\n\t\t\te.cap -= dflow;\n\t\t\tedge[e.to][e.rev].cap\
    \ += dflow;\n\t\t\treturn dflow;\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\tDinicMaxFlow(const\
    \ size_t N) : edge(N), level(N), iter(N), inf_flow(0) {\n\t\t// do nothing\n\t\
    }\n\n\tinline void make_edge(const size_t from,const size_t to, TypeFlow cap)\
    \ {\n\t\tedge[from].push_back({ to, edge[to].size(), cap });\n\t\tedge[to].push_back({\
    \ from, edge[from].size() - 1, 0});\n        inf_flow += cap;\n\t}\n\n\tinline\
    \ TypeFlow flow(const size_t start,const size_t goal) {\n\t\tTypeFlow max_flow\
    \ = 0;\n\t\twhile (1) {\n\t\t\tbfs(start);\n\t\t\tif (level[goal] < 0) return\
    \ max_flow;\n\t\t\tfor (int i = 0; i < iter.size(); ++i) iter[i] = 0;\n\t\t\t\
    TypeFlow flow;\n\t\t\twhile ((flow = dfs(start, goal, inf_flow))>0) max_flow +=\
    \ flow;\n\t\t}\n\t}\n};\n#line 9 \"test/graph/DinicMaxFlow-2.test.cpp\"\n\nint\
    \ main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int H,W; read(H),read(W);\n\
    \    vector<vector<long long>> grid(H,vector<long long>(W));\n    for(int i=0;i<H;++i)\
    \ for(int j=0;j<W;++j) read(grid[i][j]);    \n    vector<long long> R(H),C(W);\n\
    \    for(int i=0;i<H;++i) read(R[i]);\n    for(int j=0;j<W;++j) read(C[j]);  \
    \  \n\n    //\u884C/\u5217\u306B\u5BFE\u3057\u3066\u300C\u690D\u3048\u308B\u300D\
    :0, \u300C\u690D\u3048\u306A\u3044\u300D:1 ,\u3068\u5272\u308A\u5F53\u3066\u308B\
    \n    //\u52A0\u3048\u3066\u3001\u554F\u984C\u306E\u6027\u8CEA\u7684\u306Bi\u884C\
    \u76EE\u306B\u95A2\u3057\u3066\u306F\u30D5\u30ED\u30FC\u3092\u6D41\u3059\u524D\
    \u306B\u8CAA\u6B32\u306B\u9078\u3093\u3067\u3057\u307E\u3046\n    //\u305D\u3046\
    \u3059\u308B\u3053\u3068\u3067\u3001\u8FBA\u306E\u6570\u304C2\u4E57\u30AA\u30FC\
    \u30C0\u30FC\u304B\u3089\u843D\u3061\u308B\n    DinicMaxFlow<long long> di(H+W+2);\n\
    \    int S = H+W, G = H+W+1;\n\n    long long ans = 0;\n    for(int i=0;i<H;++i)\
    \ {\n        //i\u884C\u76EE\u3092\u5168\u90E8\u690D\u3048\u305F\u3068\u304D\u306E\
    \u30B3\u30B9\u30C8\u3092\u8A08\u7B97\n        long long cost = 0;\n        for(int\
    \ j=0;j<W;++j) cost += grid[i][j];        \n        //\u5DEE\u5206\u304C\u6B63\
    \u306E\u3068\u304D\n        if(R[i]-cost >= 0) ans += R[i]-cost;\n        //\u5DEE\
    \u5206\u304C\u8CA0\u306E\u3068\u304D\u2192 i\u304C0\u306E\u3068\u304D|cost-R[i]|\u5931\
    \u3046\n        else di.make_edge(i,G,abs(R[i]-cost));\n    }\n    for(int j=0;j<W;++j)\
    \ {\n        //j\u5217\u76EE\u3092\u5168\u90E8\u690D\u3048\u305F\u3068\u304D\u306E\
    \u30B3\u30B9\u30C8\n        long long cost = C[j];\n        //j\u304C0\u306E\u3068\
    \u304D|cost|\u5F97\u308B\n        ans += cost, di.make_edge(S,j+H,cost);\n   \
    \ }\n    for(int i=0;i<H;++i) for(int j=0;j<W;++j) {\n        //i\u304C1,j\u304C\
    0\u306E\u3068\u304D\u3001grid[i][j]\u5931\u3046\n        di.make_edge(j+H,i,grid[i][j]);\n\
    \    }\n    cout << ans - di.flow(S,G) << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/957\"\n\n#include <vector>\n\
    #include <iostream>\n#include <queue>\nusing namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\
    \n#include \"../../lib/40-graph/DinicMaxFlow.cpp\"\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    int H,W; read(H),read(W);\n    vector<vector<long long>> grid(H,vector<long\
    \ long>(W));\n    for(int i=0;i<H;++i) for(int j=0;j<W;++j) read(grid[i][j]);\
    \    \n    vector<long long> R(H),C(W);\n    for(int i=0;i<H;++i) read(R[i]);\n\
    \    for(int j=0;j<W;++j) read(C[j]);    \n\n    //\u884C/\u5217\u306B\u5BFE\u3057\
    \u3066\u300C\u690D\u3048\u308B\u300D:0, \u300C\u690D\u3048\u306A\u3044\u300D:1\
    \ ,\u3068\u5272\u308A\u5F53\u3066\u308B\n    //\u52A0\u3048\u3066\u3001\u554F\u984C\
    \u306E\u6027\u8CEA\u7684\u306Bi\u884C\u76EE\u306B\u95A2\u3057\u3066\u306F\u30D5\
    \u30ED\u30FC\u3092\u6D41\u3059\u524D\u306B\u8CAA\u6B32\u306B\u9078\u3093\u3067\
    \u3057\u307E\u3046\n    //\u305D\u3046\u3059\u308B\u3053\u3068\u3067\u3001\u8FBA\
    \u306E\u6570\u304C2\u4E57\u30AA\u30FC\u30C0\u30FC\u304B\u3089\u843D\u3061\u308B\
    \n    DinicMaxFlow<long long> di(H+W+2);\n    int S = H+W, G = H+W+1;\n\n    long\
    \ long ans = 0;\n    for(int i=0;i<H;++i) {\n        //i\u884C\u76EE\u3092\u5168\
    \u90E8\u690D\u3048\u305F\u3068\u304D\u306E\u30B3\u30B9\u30C8\u3092\u8A08\u7B97\
    \n        long long cost = 0;\n        for(int j=0;j<W;++j) cost += grid[i][j];\
    \        \n        //\u5DEE\u5206\u304C\u6B63\u306E\u3068\u304D\n        if(R[i]-cost\
    \ >= 0) ans += R[i]-cost;\n        //\u5DEE\u5206\u304C\u8CA0\u306E\u3068\u304D\
    \u2192 i\u304C0\u306E\u3068\u304D|cost-R[i]|\u5931\u3046\n        else di.make_edge(i,G,abs(R[i]-cost));\n\
    \    }\n    for(int j=0;j<W;++j) {\n        //j\u5217\u76EE\u3092\u5168\u90E8\u690D\
    \u3048\u305F\u3068\u304D\u306E\u30B3\u30B9\u30C8\n        long long cost = C[j];\n\
    \        //j\u304C0\u306E\u3068\u304D|cost|\u5F97\u308B\n        ans += cost,\
    \ di.make_edge(S,j+H,cost);\n    }\n    for(int i=0;i<H;++i) for(int j=0;j<W;++j)\
    \ {\n        //i\u304C1,j\u304C0\u306E\u3068\u304D\u3001grid[i][j]\u5931\u3046\
    \n        di.make_edge(j+H,i,grid[i][j]);\n    }\n    cout << ans - di.flow(S,G)\
    \ << endl;\n    return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/40-graph/DinicMaxFlow.cpp
  isVerificationFile: true
  path: test/graph/DinicMaxFlow-2.test.cpp
  requiredBy: []
  timestamp: '2023-07-18 04:41:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/DinicMaxFlow-2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/DinicMaxFlow-2.test.cpp
- /verify/test/graph/DinicMaxFlow-2.test.cpp.html
title: test/graph/DinicMaxFlow-2.test.cpp
---
