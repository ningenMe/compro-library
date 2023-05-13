---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/Zalgorithm.cpp
    title: Zalgorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/string/Zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#include <vector>\n#include <iostream>\nusing namespace std;\n#line 1 \"lib/string/Zalgorithm.cpp\"\
    \n/*\n * @title Zalgorithm\n * @docs md/string/Zalgorithm.md\n */\nclass Zalgorithm{\n\
    \    vector<int> zarray;\n    template<class T> void init(const vector<T>& ar)\
    \ {\n        int N = ar.size();\n        for(int i = 1, j = 0; i < N; ++i) {\n\
    \            if(i + zarray[i - j] < j + zarray[j]) {\n                zarray[i]\
    \ = zarray[i - j];\n            } \n            else {\n                int k\
    \ = max(0, j + zarray[j] - i);\n                while(i + k < N && ar[k] == ar[i\
    \ + k]) ++k;\n                zarray[j = i] = k;\n            }\n        }\n \
    \       zarray[0] = N;\n    }\npublic:\n    template<class T> Zalgorithm(const\
    \ vector<T>& ar) : zarray(ar.size()) {\n        init(ar);\n    }\n    Zalgorithm(const\
    \ string& s) : zarray(s.size()) {\n        vector<char> ar(s.size());\n      \
    \  for(int i=0; i<s.size(); ++i) ar[i]=s[i];\n        init(ar);\n    }\n\tinline\
    \ int operator[](int idx) {\n\t\treturn zarray[idx];\n\t}\n};\n#line 7 \"test/string/Zalgorithm.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    string S; cin\
    \ >> S;\n    Zalgorithm z(S);\n    for(int i=0;i<S.size();++i) cout << z[i] <<\
    \ \" \";\n    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <vector>\n#include <iostream>\nusing namespace std;\n#include \"../../lib/string/Zalgorithm.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    string S; cin\
    \ >> S;\n    Zalgorithm z(S);\n    for(int i=0;i<S.size();++i) cout << z[i] <<\
    \ \" \";\n    cout << endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/string/Zalgorithm.cpp
  isVerificationFile: true
  path: test/string/Zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:04:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/Zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/string/Zalgorithm.test.cpp
- /verify/test/string/Zalgorithm.test.cpp.html
title: test/string/Zalgorithm.test.cpp
---