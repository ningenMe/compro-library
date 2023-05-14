---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heap/DoubleEndedPriorityQuere.test.cpp
    title: test/heap/DoubleEndedPriorityQuere.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/heap/DoubleEndedPriorityQuere.md
    document_title: "DoubleEndedPriorityQuere - \u4E21\u7AEFpriority queue"
    links: []
  bundledCode: "#line 1 \"lib/heap/DoubleEndedPriorityQuere.cpp\"\n/*\n * @title DoubleEndedPriorityQuere\
    \ - \u4E21\u7AEFpriority queue\n * @docs md/heap/DoubleEndedPriorityQuere.md\n\
    \ */\ntemplate<class T> class DoubleEndedPriorityQuere {\n\tstd::priority_queue<T>\
    \ max_pq,poped_max_pq;\n\tstd::priority_queue<T, vector<T>, greater<T> > min_pq,\
    \ poped_min_pq;\npublic:\n\tDoubleEndedPriorityQuere() {\n    }\n\tinline void\
    \ push(const T &v) {\n\t\tmax_pq.push(v);\n\t\tmin_pq.push(v);\n\t}\n\tinline\
    \ T front() {\n        while(poped_min_pq.size() && min_pq.top()==poped_min_pq.top())\
    \ min_pq.pop(),poped_min_pq.pop();\n\t\treturn min_pq.top();\n\t}\n\tinline T\
    \ back() {\n        while(poped_max_pq.size() && max_pq.top()==poped_max_pq.top())\
    \ max_pq.pop(),poped_max_pq.pop();\n\t\treturn max_pq.top();\n\t}\n\tinline void\
    \ pop_front() {\n        while(poped_min_pq.size() && min_pq.top()==poped_min_pq.top())\
    \ min_pq.pop(),poped_min_pq.pop();\n\t\tpoped_max_pq.push(min_pq.top());\n\t\t\
    min_pq.pop();\n\t}\n\tinline void pop_back() {\n        while(poped_max_pq.size()\
    \ && max_pq.top()==poped_max_pq.top()) max_pq.pop(),poped_max_pq.pop();\n\t\t\
    poped_min_pq.push(max_pq.top());\n\t\tmax_pq.pop();\n\t}\n\tinline size_t size()\
    \ const { return max_pq.size(); }\n};\n"
  code: "/*\n * @title DoubleEndedPriorityQuere - \u4E21\u7AEFpriority queue\n * @docs\
    \ md/heap/DoubleEndedPriorityQuere.md\n */\ntemplate<class T> class DoubleEndedPriorityQuere\
    \ {\n\tstd::priority_queue<T> max_pq,poped_max_pq;\n\tstd::priority_queue<T, vector<T>,\
    \ greater<T> > min_pq, poped_min_pq;\npublic:\n\tDoubleEndedPriorityQuere() {\n\
    \    }\n\tinline void push(const T &v) {\n\t\tmax_pq.push(v);\n\t\tmin_pq.push(v);\n\
    \t}\n\tinline T front() {\n        while(poped_min_pq.size() && min_pq.top()==poped_min_pq.top())\
    \ min_pq.pop(),poped_min_pq.pop();\n\t\treturn min_pq.top();\n\t}\n\tinline T\
    \ back() {\n        while(poped_max_pq.size() && max_pq.top()==poped_max_pq.top())\
    \ max_pq.pop(),poped_max_pq.pop();\n\t\treturn max_pq.top();\n\t}\n\tinline void\
    \ pop_front() {\n        while(poped_min_pq.size() && min_pq.top()==poped_min_pq.top())\
    \ min_pq.pop(),poped_min_pq.pop();\n\t\tpoped_max_pq.push(min_pq.top());\n\t\t\
    min_pq.pop();\n\t}\n\tinline void pop_back() {\n        while(poped_max_pq.size()\
    \ && max_pq.top()==poped_max_pq.top()) max_pq.pop(),poped_max_pq.pop();\n\t\t\
    poped_min_pq.push(max_pq.top());\n\t\tmax_pq.pop();\n\t}\n\tinline size_t size()\
    \ const { return max_pq.size(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/heap/DoubleEndedPriorityQuere.cpp
  requiredBy: []
  timestamp: '2023-05-15 02:35:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/heap/DoubleEndedPriorityQuere.test.cpp
documentation_of: lib/heap/DoubleEndedPriorityQuere.cpp
layout: document
redirect_from:
- /library/lib/heap/DoubleEndedPriorityQuere.cpp
- /library/lib/heap/DoubleEndedPriorityQuere.cpp.html
title: "DoubleEndedPriorityQuere - \u4E21\u7AEFpriority queue"
---
### DoubleEndedPriorityQuere
- 両端priority queue
- ほとんどstdライブラリのラッパー
- pq4本で最大最小を管理

### reference
- https://ningenme.net/compro-category/topic/topic_B1BRYF/problem
