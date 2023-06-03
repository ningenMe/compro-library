---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/SegmentTreeBeats-1.test.cpp
    title: test/segment-tree/SegmentTreeBeats-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/SegmentTreeBeats-2.test.cpp
    title: test/segment-tree/SegmentTreeBeats-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment-tree/SegmentTreeBeats.md
    document_title: SegmentTreeBeats
    links: []
  bundledCode: "#line 1 \"lib/10-segment-tree/SegmentTreeBeats.cpp\"\n/*\n * @title\
    \ SegmentTreeBeats\n * @docs md/segment-tree/SegmentTreeBeats.md\n */\ntemplate<class\
    \ T> class SegmentTreeBeats {\n    T inf;\n    size_t length;\n    vector<T>\n\
    \            node_max_first,node_max_second,count_max_first,\n            node_min_first,node_min_second,count_min_first,\n\
    \            node_sum,lazy_add,lazy_update;\n    vector<pair<int,int>> range;\n\
    \    stack<int> down,up;\n    inline void internal_chmax(int k, long long x) {\n\
    \        node_sum[k] += (x - node_max_first[k]) * count_max_first[k];\n      \
    \  if(node_max_first[k] == node_min_first[k]) node_max_first[k] = node_min_first[k]\
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
    \        }\n        return v;\n    }\n};\n"
  code: "/*\n * @title SegmentTreeBeats\n * @docs md/segment-tree/SegmentTreeBeats.md\n\
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
    \        }\n        return v;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/10-segment-tree/SegmentTreeBeats.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment-tree/SegmentTreeBeats-2.test.cpp
  - test/segment-tree/SegmentTreeBeats-1.test.cpp
documentation_of: lib/10-segment-tree/SegmentTreeBeats.cpp
layout: document
redirect_from:
- /library/lib/10-segment-tree/SegmentTreeBeats.cpp
- /library/lib/10-segment-tree/SegmentTreeBeats.cpp.html
title: SegmentTreeBeats
---