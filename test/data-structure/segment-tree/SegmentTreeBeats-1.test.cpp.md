---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/segment-tree/SegmentTreeBeats.cpp
    title: SegmentTreeBeats
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/data-structure/segment-tree/SegmentTreeBeats-1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <stack>\nusing namespace\
    \ std;\n#line 1 \"lib/data-structure/segment-tree/SegmentTreeBeats.cpp\"\n/*\n\
    \ * @title SegmentTreeBeats\n * @docs md/data-structure/segment-tree/SegmentTreeBeats.md\n\
    \ */\ntemplate<class T> class SegmentTreeBeats {\n    T inf;\n    size_t length;\n\
    \    vector<T>\n            node_max_first,node_max_second,count_max_first,\n\
    \            node_min_first,node_min_second,count_min_first,\n            node_sum,lazy_add,lazy_update;\n\
    \    vector<pair<int,int>> range;\n    stack<int> down,up;\n    inline void internal_chmax(int\
    \ k, long long x) {\n        node_sum[k] += (x - node_max_first[k]) * count_max_first[k];\n\
    \        if(node_max_first[k] == node_min_first[k]) node_max_first[k] = node_min_first[k]\
    \ = x;\n        else if(node_max_first[k] == node_min_second[k]) node_max_first[k]\
    \ = node_min_second[k] = x;\n        else node_max_first[k] = x;\n        if(lazy_update[k]\
    \ != inf && x < lazy_update[k]) lazy_update[k] = x;\n    }\n    inline void internal_chmin(int\
    \ k, long long x) {\n        node_sum[k] += (x - node_min_first[k]) * count_min_first[k];\n\
    \        if(node_max_first[k] == node_min_first[k]) node_max_first[k] = node_min_first[k]\
    \ = x;\n        else if(node_max_second[k] == node_min_first[k]) node_min_first[k]\
    \ = node_max_second[k] = x;\n        else node_min_first[k] = x;\n        if(lazy_update[k]\
    \ != inf && lazy_update[k] < x) lazy_update[k] = x;\n    }\n    inline void internal_add(int\
    \ k, long long x) {\n        node_max_first[k] += x;\n        if(node_max_second[k]\
    \ != -inf) node_max_second[k] += x;\n        node_min_first[k] += x;\n       \
    \ if(node_min_second[k] != inf) node_min_second[k] += x;\n        node_sum[k]\
    \ += x * (range[k].second - range[k].first);\n        (lazy_update[k] != inf ?\
    \ lazy_update[k]:lazy_add[k]) += x;\n    }\n    inline void internal_update(int\
    \ k, long long x) {\n        node_max_first[k] = x; node_max_second[k] = -inf;\n\
    \        node_min_first[k] = x; node_min_second[k] = inf;\n        count_max_first[k]\
    \ = count_min_first[k] = (range[k].second - range[k].first);\n        node_sum[k]\
    \ = x * (range[k].second - range[k].first);\n        lazy_update[k] = x;\n   \
    \     lazy_add[k] = 0;\n    }\n    inline void propagate(int k) {\n        if(length-1\
    \ <= k) return;\n        if(lazy_update[k] != inf) {\n            internal_update(2*k+0,\
    \ lazy_update[k]);\n            internal_update(2*k+1, lazy_update[k]);\n    \
    \        lazy_update[k] = inf;\n            return;\n        }\n        if(lazy_add[k]\
    \ != 0) {\n            internal_add(2*k+0, lazy_add[k]);\n            internal_add(2*k+1,\
    \ lazy_add[k]);\n            lazy_add[k] = 0;\n        }\n        if(node_max_first[k]\
    \ < node_max_first[2*k+0]) {\n            internal_chmax(2*k+0, node_max_first[k]);\n\
    \        }\n        if(node_min_first[2*k+0] < node_min_first[k]) {\n        \
    \    internal_chmin(2*k+0, node_min_first[k]);\n        }\n        if(node_max_first[k]\
    \ < node_max_first[2*k+1]) {\n            internal_chmax(2*k+1, node_max_first[k]);\n\
    \        }\n        if(node_min_first[2*k+1] < node_min_first[k]) {\n        \
    \    internal_chmin(2*k+1, node_min_first[k]);\n        }\n    }\n    inline void\
    \ merge(int k) {\n        node_sum[k] = node_sum[2*k+0] + node_sum[2*k+1];\n \
    \       if(node_max_first[2*k+0] < node_max_first[2*k+1]) {\n            node_max_first[k]\
    \ = node_max_first[2*k+1];\n            count_max_first[k] = count_max_first[2*k+1];\n\
    \            node_max_second[k] = max(node_max_first[2*k+0], node_max_second[2*k+1]);\n\
    \        }\n        else if(node_max_first[2*k+0] > node_max_first[2*k+1]) {\n\
    \            node_max_first[k] = node_max_first[2*k+0];\n            count_max_first[k]\
    \ = count_max_first[2*k+0];\n            node_max_second[k] = max(node_max_second[2*k+0],\
    \ node_max_first[2*k+1]);\n        }\n        else {\n            node_max_first[k]\
    \ = node_max_first[2*k+0];\n            count_max_first[k] = count_max_first[2*k+0]\
    \ + count_max_first[2*k+1];\n            node_max_second[k] = max(node_max_second[2*k+0],\
    \ node_max_second[2*k+1]);\n        }\n        if(node_min_first[2*k+0] < node_min_first[2*k+1])\
    \ {\n            node_min_first[k] = node_min_first[2*k+0];\n            count_min_first[k]\
    \ = count_min_first[2*k+0];\n            node_min_second[k] = min(node_min_second[2*k+0],\
    \ node_min_first[2*k+1]);\n        }\n        else if(node_min_first[2*k+0] >\
    \ node_min_first[2*k+1]) {\n            node_min_first[k] = node_min_first[2*k+1];\n\
    \            count_min_first[k] = count_min_first[2*k+1];\n            node_min_second[k]\
    \ = min(node_min_first[2*k+0], node_min_second[2*k+1]);\n        }\n        else\
    \ {\n            node_min_first[k] = node_min_first[2*k+0];\n            count_min_first[k]\
    \ = count_min_first[2*k+0] + count_min_first[2*k+1];\n            node_min_second[k]\
    \ = min(node_min_second[2*k+0], node_min_second[2*k+1]);\n        }\n    }\n \
    \   inline void up_merge(void){\n        while(up.size()) {\n            merge(up.top());\n\
    \            up.pop();\n        }\n    }\n    inline void down_propagate(const\
    \ int& k) {\n        propagate(k);\n        down.push(2*k+0);\n        down.push(2*k+1);\n\
    \    }\npublic:\n    SegmentTreeBeats(const int num,const T inf = (1LL<<60)) {\n\
    \        vector<T> a(num,0);\n        *this = SegmentTreeBeats(a,inf);\n    }\n\
    \    SegmentTreeBeats(const vector<T>& a,const T inf = (1LL<<60)) : inf(inf){\n\
    \        int num = a.size();\n        for (length = 1; length <= num; length *=\
    \ 2);\n        node_max_first.resize(2*length);\n        node_max_second.resize(2*length);\n\
    \        count_max_first.resize(2*length);\n        node_min_first.resize(2*length);\n\
    \        node_min_second.resize(2*length);\n        count_min_first.resize(2*length);\n\
    \        node_sum.resize(2*length);\n        range.resize(2*length);\n       \
    \ lazy_add.resize(2*length);\n        lazy_update.resize(2*length);\n\n      \
    \  for(int i=0; i<2*length; ++i) lazy_add[i] = 0, lazy_update[i] = inf;\n    \
    \    for(int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n   \
    \     for(int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \n        for(int i=0; i<num; ++i) {\n            node_max_first[length+i] = node_min_first[length+i]\
    \ = node_sum[length+i] = a[i];\n            node_max_second[length+i] = -inf;\n\
    \            node_min_second[length+i] = inf;\n            count_max_first[length+i]\
    \ = count_min_first[length+i] = 1;\n        }\n        for(int i=num; i<length;\
    \ ++i) {\n            node_max_first[length+i] = node_max_second[length+i] = -inf;\n\
    \            node_min_first[length+i] = node_min_second[length+i] = inf;\n   \
    \         count_max_first[length+i] = count_min_first[length+i] = 0;\n       \
    \ }\n        for(int i=length-1; i; --i) merge(i);\n    }\n    inline void range_chmin(int\
    \ a, int b, long long x) {\n        down.push(1);\n        while(down.size())\
    \ {\n            int k = down.top();\n            down.pop();\n            if(b\
    \ <= range[k].first || range[k].second <= a || node_max_first[k] <= x) continue;\n\
    \            if(a <= range[k].first && range[k].second <= b && node_max_second[k]\
    \ < x) {\n                internal_chmax(k, x);\n                continue;\n \
    \           }\n            down_propagate(k);\n            up.push(k);\n     \
    \   }\n        up_merge();\n    }\n    inline void range_chmax(int a, int b, long\
    \ long x,int k = 1) {\n        down.push(1);\n        while(down.size()) {\n \
    \           int k = down.top();\n            down.pop();\n            if(b <=\
    \ range[k].first || range[k].second <= a || x <= node_min_first[k]) continue;\n\
    \            if(a <= range[k].first && range[k].second <= b && x < node_min_second[k])\
    \ {\n                internal_chmin(k, x);\n                continue;\n      \
    \      }\n            down_propagate(k);\n            up.push(k);\n        }\n\
    \        up_merge();\n    }\n    inline void range_add(int a, int b, long long\
    \ x,int k = 1) {\n        down.push(1);\n        while(down.size()) {\n      \
    \      int k = down.top();\n            down.pop();\n            if(b <= range[k].first\
    \ || range[k].second <= a) continue;\n            if(a <= range[k].first && range[k].second\
    \ <= b) {\n                internal_add(k, x);\n                continue;\n  \
    \          }\n            down_propagate(k);\n            up.push(k);\n      \
    \  }\n        up_merge();\n    }\n    inline void range_update(int a, int b, long\
    \ long x,int k = 1) {\n        down.push(1);\n        while(down.size()) {\n \
    \           int k = down.top();\n            down.pop();\n            if(b <=\
    \ range[k].first || range[k].second <= a) continue;\n            if(a <= range[k].first\
    \ && range[k].second <= b) {\n                internal_update(k, x);\n       \
    \         continue;\n            }\n            down_propagate(k);\n         \
    \   up.push(k);\n        }\n        up_merge();\n    }\n    inline T get_max(int\
    \ a, int b, int k = 1) {\n        down.push(1);\n        long long v = inf;\n\
    \        while(down.size()) {\n            int k = down.top();\n            down.pop();\n\
    \            if(b <= range[k].first || range[k].second <= a) continue;\n     \
    \       if(a <= range[k].first && range[k].second <= b) {\n                v =\
    \ max(v,node_max_first[k]);\n                continue;\n            }\n      \
    \      down_propagate(k);\n        }\n        return v;\n    }\n    inline T get_min(int\
    \ a, int b, int k = 1) {\n        down.push(1);\n        long long v = inf;\n\
    \        while(down.size()) {\n            int k = down.top();\n            down.pop();\n\
    \            if(b <= range[k].first || range[k].second <= a) continue;\n     \
    \       if(a <= range[k].first && range[k].second <= b) {\n                v =\
    \ min(v,node_min_first[k]);\n                continue;\n            }\n      \
    \      down_propagate(k);\n        }\n        return v;\n    }\n    inline T get_sum(int\
    \ a, int b, int k=1) {\n        down.push(1);\n        long long v = 0;\n    \
    \    while(down.size()) {\n            int k = down.top();\n            down.pop();\n\
    \            if(b <= range[k].first || range[k].second <= a) continue;\n     \
    \       if(a <= range[k].first && range[k].second <= b) {\n                v +=\
    \ node_sum[k];\n                continue;\n            }\n            down_propagate(k);\n\
    \        }\n        return v;\n    }\n};\n#line 8 \"test/data-structure/segment-tree/SegmentTreeBeats-1.test.cpp\"\
    \n\nint main(void){\n\tint N,Q; cin >> N >> Q;\n\tvector<long long> A(N);\n\t\
    for(int i = 0; i < N; ++i) cin >> A[i];\n\tSegmentTreeBeats<long long> seg(A);\n\
    \twhile(Q--){\n\t\tlong long q,l,r,b;\n\t\tcin >> q >> l >> r;\n\t\tif(q==3){\n\
    \t\t\tcout << seg.get_sum(l,r) << endl;\n\t\t}\n\t\telse{\n\t\t\tcin >> b;\n\t\
    \t\tif(q==0) {\n\t\t\t\tseg.range_chmin(l,r,b);\n\t\t\t}\n\t\t\tif(q==1) {\n\t\
    \t\t\tseg.range_chmax(l,r,b);\n\t\t\t}\n\t\t\tif(q==2) {\n\t\t\t\tseg.range_add(l,r,b);\n\
    \t\t\t}\n\t\t}\n\t}\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <stack>\nusing namespace\
    \ std;\n#include \"../../../lib/data-structure/segment-tree/SegmentTreeBeats.cpp\"\
    \n\nint main(void){\n\tint N,Q; cin >> N >> Q;\n\tvector<long long> A(N);\n\t\
    for(int i = 0; i < N; ++i) cin >> A[i];\n\tSegmentTreeBeats<long long> seg(A);\n\
    \twhile(Q--){\n\t\tlong long q,l,r,b;\n\t\tcin >> q >> l >> r;\n\t\tif(q==3){\n\
    \t\t\tcout << seg.get_sum(l,r) << endl;\n\t\t}\n\t\telse{\n\t\t\tcin >> b;\n\t\
    \t\tif(q==0) {\n\t\t\t\tseg.range_chmin(l,r,b);\n\t\t\t}\n\t\t\tif(q==1) {\n\t\
    \t\t\tseg.range_chmax(l,r,b);\n\t\t\t}\n\t\t\tif(q==2) {\n\t\t\t\tseg.range_add(l,r,b);\n\
    \t\t\t}\n\t\t}\n\t}\n    return 0;\n}"
  dependsOn:
  - lib/data-structure/segment-tree/SegmentTreeBeats.cpp
  isVerificationFile: true
  path: test/data-structure/segment-tree/SegmentTreeBeats-1.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:44:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/segment-tree/SegmentTreeBeats-1.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/segment-tree/SegmentTreeBeats-1.test.cpp
- /verify/test/data-structure/segment-tree/SegmentTreeBeats-1.test.cpp.html
title: test/data-structure/segment-tree/SegmentTreeBeats-1.test.cpp
---
