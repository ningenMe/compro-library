---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/SegmentTreeBeats.cpp
    title: SegmentTreeBeats
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1074
    links:
    - https://yukicoder.me/problems/no/1074
  bundledCode: "#line 1 \"test/segment/SegmentTreeBeats-2.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1074\"\n\n#include <vector>\n#include <iostream>\n\
    #include <stack>\nusing namespace std;\n#line 1 \"lib/segment/SegmentTreeBeats.cpp\"\
    \n/*\n * @title SegmentTreeBeats\n * @docs md/segment/SegmentTreeBeats.md\n */\n\
    template<class T> class SegmentTreeBeats {\n\tT inf;\n\tsize_t length;\n\tvector<T>\n\
    \tnode_max_first,node_max_second,count_max_first,\n\tnode_min_first,node_min_second,count_min_first,\n\
    \tnode_sum,lazy_add,lazy_update;\n\tvector<pair<int,int>> range;\n\tstack<int>\
    \ down,up;\n\tinline void internal_chmax(int k, long long x) {\n\t\tnode_sum[k]\
    \ += (x - node_max_first[k]) * count_max_first[k];\n\t\tif(node_max_first[k] ==\
    \ node_min_first[k]) node_max_first[k] = node_min_first[k] = x;\n\t\telse if(node_max_first[k]\
    \ == node_min_second[k]) node_max_first[k] = node_min_second[k] = x;\n\t\telse\
    \ node_max_first[k] = x;\n\t\tif(lazy_update[k] != inf && x < lazy_update[k])\
    \ lazy_update[k] = x;\n\t}\n\tinline void internal_chmin(int k, long long x) {\n\
    \t\tnode_sum[k] += (x - node_min_first[k]) * count_min_first[k];\n\t\tif(node_max_first[k]\
    \ == node_min_first[k]) node_max_first[k] = node_min_first[k] = x;\n\t\telse if(node_max_second[k]\
    \ == node_min_first[k]) node_min_first[k] = node_max_second[k] = x;\n\t\telse\
    \ node_min_first[k] = x;\n\t\tif(lazy_update[k] != inf && lazy_update[k] < x)\
    \ lazy_update[k] = x;\n\t}\n\tinline void internal_add(int k, long long x) {\n\
    \t\tnode_max_first[k] += x;\n\t\tif(node_max_second[k] != -inf) node_max_second[k]\
    \ += x;\n\t\tnode_min_first[k] += x;\n\t\tif(node_min_second[k] != inf) node_min_second[k]\
    \ += x;\n\t\tnode_sum[k] += x * (range[k].second - range[k].first);\n\t\t(lazy_update[k]\
    \ != inf ? lazy_update[k]:lazy_add[k]) += x;\n\t}\n\tinline void internal_update(int\
    \ k, long long x) {\n\t\tnode_max_first[k] = x; node_max_second[k] = -inf;\n\t\
    \tnode_min_first[k] = x; node_min_second[k] = inf;\n\t\tcount_max_first[k] = count_min_first[k]\
    \ = (range[k].second - range[k].first);\n\t\tnode_sum[k] = x * (range[k].second\
    \ - range[k].first);\n\t\tlazy_update[k] = x;\n\t\tlazy_add[k] = 0;\n\t}\n\tinline\
    \ void propagate(int k) {\n\t\tif(length-1 <= k) return;\n\t\tif(lazy_update[k]\
    \ != inf) {\n\t\t\tinternal_update(2*k+0, lazy_update[k]);\n\t\t\tinternal_update(2*k+1,\
    \ lazy_update[k]);\n\t\t\tlazy_update[k] = inf;\n\t\t\treturn;\n\t\t}\n\t\tif(lazy_add[k]\
    \ != 0) {\n\t\t\tinternal_add(2*k+0, lazy_add[k]);\n\t\t\tinternal_add(2*k+1,\
    \ lazy_add[k]);\n\t\t\tlazy_add[k] = 0;\n\t\t}\n\t\tif(node_max_first[k] < node_max_first[2*k+0])\
    \ {\n\t\t\tinternal_chmax(2*k+0, node_max_first[k]);\n\t\t}\n\t\tif(node_min_first[2*k+0]\
    \ < node_min_first[k]) {\n\t\t\tinternal_chmin(2*k+0, node_min_first[k]);\n\t\t\
    }\n\t\tif(node_max_first[k] < node_max_first[2*k+1]) {\n\t\t\tinternal_chmax(2*k+1,\
    \ node_max_first[k]);\n\t\t}\n\t\tif(node_min_first[2*k+1] < node_min_first[k])\
    \ {\n\t\t\tinternal_chmin(2*k+1, node_min_first[k]);\n\t\t}\n\t}\n\tinline void\
    \ merge(int k) {\n\t\tnode_sum[k] = node_sum[2*k+0] + node_sum[2*k+1];\n\t\tif(node_max_first[2*k+0]\
    \ < node_max_first[2*k+1]) {\n\t\t\tnode_max_first[k] = node_max_first[2*k+1];\n\
    \t\t\tcount_max_first[k] = count_max_first[2*k+1];\n\t\t\tnode_max_second[k] =\
    \ max(node_max_first[2*k+0], node_max_second[2*k+1]);\n\t\t}\n\t\telse if(node_max_first[2*k+0]\
    \ > node_max_first[2*k+1]) {\n\t\t\tnode_max_first[k] = node_max_first[2*k+0];\n\
    \t\t\tcount_max_first[k] = count_max_first[2*k+0];\n\t\t\tnode_max_second[k] =\
    \ max(node_max_second[2*k+0], node_max_first[2*k+1]);\n\t\t}\n\t\telse {\n\t\t\
    \tnode_max_first[k] = node_max_first[2*k+0];\n\t\t\tcount_max_first[k] = count_max_first[2*k+0]\
    \ + count_max_first[2*k+1];\n\t\t\tnode_max_second[k] = max(node_max_second[2*k+0],\
    \ node_max_second[2*k+1]);\n\t\t}\n\t\tif(node_min_first[2*k+0] < node_min_first[2*k+1])\
    \ {\n\t\t\tnode_min_first[k] = node_min_first[2*k+0];\n\t\t\tcount_min_first[k]\
    \ = count_min_first[2*k+0];\n\t\t\tnode_min_second[k] = min(node_min_second[2*k+0],\
    \ node_min_first[2*k+1]);\n\t\t}\n\t\telse if(node_min_first[2*k+0] > node_min_first[2*k+1])\
    \ {\n\t\t\tnode_min_first[k] = node_min_first[2*k+1];\n\t\t\tcount_min_first[k]\
    \ = count_min_first[2*k+1];\n\t\t\tnode_min_second[k] = min(node_min_first[2*k+0],\
    \ node_min_second[2*k+1]);\n\t\t}\n\t\telse {\n\t\t\tnode_min_first[k] = node_min_first[2*k+0];\n\
    \t\t\tcount_min_first[k] = count_min_first[2*k+0] + count_min_first[2*k+1];\n\t\
    \t\tnode_min_second[k] = min(node_min_second[2*k+0], node_min_second[2*k+1]);\n\
    \t\t}\n\t}\n\tinline void up_merge(void){\n\t\twhile(up.size()) {\n\t\t\tmerge(up.top());\n\
    \t\t\tup.pop();\n\t\t}\n\t}\n\tinline void down_propagate(const int& k) {\n\t\t\
    propagate(k);\n\t\tdown.push(2*k+0);\n\t\tdown.push(2*k+1);\n\t}\npublic:\n\t\
    SegmentTreeBeats(const int num,const T inf = (1LL<<60)) {\n\t\tvector<T> a(num,0);\n\
    \t\t*this = SegmentTreeBeats(a,inf);\n\t}\n\tSegmentTreeBeats(const vector<T>&\
    \ a,const T inf = (1LL<<60)) : inf(inf){\n\t\tint num = a.size();\n\t\tfor (length\
    \ = 1; length <= num; length *= 2);\n\t\tnode_max_first.resize(2*length);\n\t\t\
    node_max_second.resize(2*length);\n\t\tcount_max_first.resize(2*length);\n\t\t\
    node_min_first.resize(2*length);\n\t\tnode_min_second.resize(2*length);\n\t\t\
    count_min_first.resize(2*length);\n\t\tnode_sum.resize(2*length);\n\t\trange.resize(2*length);\n\
    \t\tlazy_add.resize(2*length);\n\t\tlazy_update.resize(2*length);\n\n\t\tfor(int\
    \ i=0; i<2*length; ++i) lazy_add[i] = 0, lazy_update[i] = inf;\n\t\tfor(int i\
    \ = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\tfor(int i = length\
    \ - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \n\t\tfor(int i=0; i<num; ++i) {\n\t\t\tnode_max_first[length+i] = node_min_first[length+i]\
    \ = node_sum[length+i] = a[i];\n\t\t\tnode_max_second[length+i] = -inf;\n\t\t\t\
    node_min_second[length+i] = inf;\n\t\t\tcount_max_first[length+i] = count_min_first[length+i]\
    \ = 1;\n\t\t}\n\t\tfor(int i=num; i<length; ++i) {\n\t\t\tnode_max_first[length+i]\
    \ = node_max_second[length+i] = -inf;\n\t\t\tnode_min_first[length+i] = node_min_second[length+i]\
    \ = inf;\n\t\t\tcount_max_first[length+i] = count_min_first[length+i] = 0;\n\t\
    \t}\n\t\tfor(int i=length-1; i; --i) merge(i);\n\t}\n\tinline void range_chmin(int\
    \ a, int b, long long x) {\n\t\tdown.push(1);\n\t\twhile(down.size()) {\n\t\t\t\
    int k = down.top();\n\t\t\tdown.pop();\n\t\t\tif(b <= range[k].first || range[k].second\
    \ <= a || node_max_first[k] <= x) continue;\n\t\t\tif(a <= range[k].first && range[k].second\
    \ <= b && node_max_second[k] < x) {\n\t\t\t\tinternal_chmax(k, x);\n\t\t\t\tcontinue;\n\
    \t\t\t}\n\t\t\tdown_propagate(k);\n\t\t\tup.push(k);\n\t\t}\n\t\tup_merge();\n\
    \t}\n\tinline void range_chmax(int a, int b, long long x,int k = 1) {\n\t\tdown.push(1);\n\
    \t\twhile(down.size()) {\n\t\t\tint k = down.top();\n\t\t\tdown.pop();\n\t\t\t\
    if(b <= range[k].first || range[k].second <= a || x <= node_min_first[k]) continue;\n\
    \t\t\tif(a <= range[k].first && range[k].second <= b && x < node_min_second[k])\
    \ {\n\t\t\t\tinternal_chmin(k, x);\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tdown_propagate(k);\n\
    \t\t\tup.push(k);\n\t\t}\n\t\tup_merge();\n\t}\n\tinline void range_add(int a,\
    \ int b, long long x,int k = 1) {\n\t\tdown.push(1);\n\t\twhile(down.size()) {\n\
    \t\t\tint k = down.top();\n\t\t\tdown.pop();\n\t\t\tif(b <= range[k].first ||\
    \ range[k].second <= a) continue;\n\t\t\tif(a <= range[k].first && range[k].second\
    \ <= b) {\n\t\t\t\tinternal_add(k, x);\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tdown_propagate(k);\n\
    \t\t\tup.push(k);\n\t\t}\n\t\tup_merge();\n\t}\n\tinline void range_update(int\
    \ a, int b, long long x,int k = 1) {\n\t\tdown.push(1);\n\t\twhile(down.size())\
    \ {\n\t\t\tint k = down.top();\n\t\t\tdown.pop();\n\t\t\tif(b <= range[k].first\
    \ || range[k].second <= a) continue;\n\t\t\tif(a <= range[k].first && range[k].second\
    \ <= b) {\n\t\t\t\tinternal_update(k, x);\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\t\
    down_propagate(k);\n\t\t\tup.push(k);\n\t\t}\n\t\tup_merge();\n\t}\n\tinline T\
    \ get_max(int a, int b, int k = 1) {\n\t\tdown.push(1);\n\t\tlong long v = inf;\n\
    \t\twhile(down.size()) {\n\t\t\tint k = down.top();\n\t\t\tdown.pop();\n\t\t\t\
    if(b <= range[k].first || range[k].second <= a) continue;\n\t\t\tif(a <= range[k].first\
    \ && range[k].second <= b) {\n\t\t\t\tv = max(v,node_max_first[k]);\n\t\t\t\t\
    continue;\n\t\t\t}\n\t\t\tdown_propagate(k);\n\t\t}\n\t\treturn v;\n\t}\n\tinline\
    \ T get_min(int a, int b, int k = 1) {\n\t\tdown.push(1);\n\t\tlong long v = inf;\n\
    \t\twhile(down.size()) {\n\t\t\tint k = down.top();\n\t\t\tdown.pop();\n\t\t\t\
    if(b <= range[k].first || range[k].second <= a) continue;\n\t\t\tif(a <= range[k].first\
    \ && range[k].second <= b) {\n\t\t\t\tv = min(v,node_min_first[k]);\n\t\t\t\t\
    continue;\n\t\t\t}\n\t\t\tdown_propagate(k);\n\t\t}\n\t\treturn v;\n\t}\n\tinline\
    \ T get_sum(int a, int b, int k=1) {\n\t\tdown.push(1);\n\t\tlong long v = 0;\n\
    \t\twhile(down.size()) {\n\t\t\tint k = down.top();\n\t\t\tdown.pop();\n\t\t\t\
    if(b <= range[k].first || range[k].second <= a) continue;\n\t\t\tif(a <= range[k].first\
    \ && range[k].second <= b) {\n\t\t\t\tv += node_sum[k];\n\t\t\t\tcontinue;\n\t\
    \t\t}\n\t\t\tdown_propagate(k);\n\t\t}\n\t\treturn v;\n\t}\n};\n#line 8 \"test/segment/SegmentTreeBeats-2.test.cpp\"\
    \n\nint main(void){\n    int N,M=20000; cin >> N;\n    SegmentTreeBeats<long long>\
    \ seg1(M),seg2(M),seg3(M),seg4(M);\n    long long pre=0,sum=0;\n    while(N--){\n\
    \        int lx,ly,rx,ry;\n        cin >> lx >> ly >> rx >> ry;\n        seg1.range_chmax(0,rx,ry);\n\
    \        seg2.range_chmax(0,rx,-ly);\n        seg3.range_chmax(0,-lx,ry);\n  \
    \      seg4.range_chmax(0,-lx,-ly);\n        sum=seg1.get_sum(0,M)+seg2.get_sum(0,M)+seg3.get_sum(0,M)+seg4.get_sum(0,M);\n\
    \        cout << sum-pre << endl;\n        pre=sum;\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1074\"\n\n#include <vector>\n\
    #include <iostream>\n#include <stack>\nusing namespace std;\n#include \"../../lib/segment/SegmentTreeBeats.cpp\"\
    \n\nint main(void){\n    int N,M=20000; cin >> N;\n    SegmentTreeBeats<long long>\
    \ seg1(M),seg2(M),seg3(M),seg4(M);\n    long long pre=0,sum=0;\n    while(N--){\n\
    \        int lx,ly,rx,ry;\n        cin >> lx >> ly >> rx >> ry;\n        seg1.range_chmax(0,rx,ry);\n\
    \        seg2.range_chmax(0,rx,-ly);\n        seg3.range_chmax(0,-lx,ry);\n  \
    \      seg4.range_chmax(0,-lx,-ly);\n        sum=seg1.get_sum(0,M)+seg2.get_sum(0,M)+seg3.get_sum(0,M)+seg4.get_sum(0,M);\n\
    \        cout << sum-pre << endl;\n        pre=sum;\n\t}\n\treturn 0;\n}"
  dependsOn:
  - lib/segment/SegmentTreeBeats.cpp
  isVerificationFile: true
  path: test/segment/SegmentTreeBeats-2.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/SegmentTreeBeats-2.test.cpp
layout: document
redirect_from:
- /verify/test/segment/SegmentTreeBeats-2.test.cpp
- /verify/test/segment/SegmentTreeBeats-2.test.cpp.html
title: test/segment/SegmentTreeBeats-2.test.cpp
---
