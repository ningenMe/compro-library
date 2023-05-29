---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.11/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.11/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.11/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.11/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/919\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#include \"../../lib/12-binary-search-tree/RandomizedBinarySearchTree.cpp\"\
    \n#include \"../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\n\ntemplate<class\
    \ T> class Mo{\n    unordered_map<long long,int> mp;\n    long long N;\n    int\
    \ bucket;\n    vector<pair<int,int>> range;\n\tvector<int> idx;\npublic:\n\n \
    \   Mo(int N, const vector<pair<int,int>>& range) : N(N),range(range),idx(range.size()),bucket(sqrt(N))\
    \ {\n        iota(idx.begin(),idx.end(),0);\n        sort(idx.begin(),idx.end(),[&](int\
    \ a, int b){\n            auto  al = range[a].first/bucket;\n            auto\
    \  ar = range[a].second;\n            auto  bl = range[b].first/bucket;\n    \
    \        auto  br = range[b].second;\n            return (al != bl) ? (al < bl)\
    \ : ((al%2)?(ar > br):(ar < br));\n        });\n    }\n    \n    //\u53C2\u7167\
    \u3067vector\u3092\u6E21\u3057\u305F\u308A\u3059\u308B\u3068\u826F\u3044\n   \
    \ void solve(const vector<int>& A, RandomizedBinarySearchTree<MonoidRangeSumPointAdd<long\
    \ long>>& med){\n        int l = 0, r = 0;\n        for(int& i:idx){\n       \
    \     auto& xl = range[i].first;\n            auto& xr = range[i].second;\n  \
    \          \n            //\u5DE6\u7AEF\u3092\u5E83\u3052\u308B\n            while(xl\
    \ < l){\n                l--;\n                med.insert(A[l]);\n           \
    \ }\n            //\u53F3\u7AEF\u3092\u5E83\u3052\u308B\n            while(r <\
    \ xr){\n                r++;\n                med.insert(A[r]);\n            }\n\
    \            //\u5DE6\u7AEF\u3092\u72ED\u3081\u308B\n            while(l < xl){\n\
    \t\t\t\tmed.erase(A[l]);\n                l++;\n            }\n            //\u53F3\
    \u7AEF\u3092\u72ED\u3081\u308B\n            while(xr < r){\n\t\t\t\tmed.erase(A[r]);\n\
    \                r--;\n            }\n            mp[xl*N+xr] = med.get((xr-xl)/2);\n\
    \        }\n    }\n\n    T& operator [] (pair<int,int> p) {\n        return mp[p.first*N+p.second];\n\
    \    }\n};\n\ntemplate <class T> void chmax(T& a, const T b){a=max(a,b);}\n\n\
    int main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n\tint N; cin >> N;\n\
    \    vector<int> A(N);\n\tfor(int i = 0; i < N; ++i) cin >> A[i];\n\n\t//\u30AF\
    \u30A8\u30EA\u533A\u9593\u3092\u5217\u6319\u3001\u8ABF\u548C\u7D1A\u6570\u306A\
    \u306E\u3067O(N*logN)\n\tvector<pair<int,int>> range;\n\tfor(int n = 1; n <= N;\
    \ ++n) {\n\t\tint M = N/n;\n\t\tfor(int i = 0;     i+n <= N; i+=n) range.push_back({i,i+n-1});\n\
    \t\tfor(int i = N-M*n; i+n <= N; i+=n) range.push_back({i,i+n-1});\n\t}\n\n\t\n\
    \t//Mo\u3067\u4E2D\u592E\u5024\u5217\u6319\u3000O(N*sqrt(N)*(logN)^2)\n    Mo<int>\
    \ mo(N,range);\n    RandomizedBinarySearchTree<MonoidRangeSumPointAdd<long long>>\
    \ med;\n    med.insert(A[0]);\n    mo.solve(A,med);\n\n\tlong long ans = 0;\n\t\
    int cnt = 0;\n\t//\u533A\u9593\u9577\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22\
    O(N*logN)\n\tfor(long long n = 1; n <= N; ++n) {\n\t\tint M = N/n;\n\t\tvector<long\
    \ long> lSum(M,0),rSum(M,0);\n\t\tvector<pair<int, int>> lRange(M),rRange(M);\n\
    \t\t//\u533A\u9593\u53D6\u5F97 O(M)\n\t\tfor(int i = 0; i < M; ++i) {\n\t\t\t\
    lRange[i] = range[cnt + i];\n\t\t\tlSum[i]   = n*mo[lRange[i]];\n\t\t\trRange[i]\
    \ = range[cnt + i + M];\n\t\t\trSum[i]   = n*mo[rRange[i]];\n\t\t}\n\t\t//\u7D2F\
    \u7A4D\u548C O(M)\n\t\tfor(int i = 1;    i < M; ++i) lSum[i]  += lSum[i-1];\n\t\
    \tfor(int i = M-2; 0 <= i; --i) rSum[i]  += rSum[i+1];\n\t\t//\u7D2F\u7A4Dmax\
    \ O(M)\n\t\tfor(int i = 1;    i < M; ++i) chmax(lSum[i],lSum[i-1]);\n\t\tfor(int\
    \ i = M-2; 0 <= i; --i) chmax(rSum[i],rSum[i+1]);\n\n\t\tchmax(ans,lSum[M-1]);\n\
    \t\tchmax(ans,rSum[0]);\n\n\t\t//\u5C3A\u53D6\u308A\u3057\u306A\u304C\u3089\u5DE6\
    \u53F3\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22 O(M)\n\t\tint j = 0;\n\t\tfor(int\
    \ i = 0; i < M; ++i) {\n\t\t\twhile(j < M && lRange[i].second >= rRange[j].first)\
    \ j++;\n\t\t\tif(j<M && lRange[i].second < rRange[j].first) {\n\t\t\t\tchmax(ans,lSum[i]+rSum[j]);\n\
    \t\t\t}\n\t\t}\n\t\tcnt += 2*M;\n\t}\n\tcout << ans << endl;\n\n    return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/binary-search-tree/RandomizedBinarySearchTree-med.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binary-search-tree/RandomizedBinarySearchTree-med.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/RandomizedBinarySearchTree-med.test.cpp
- /verify/test/binary-search-tree/RandomizedBinarySearchTree-med.test.cpp.html
title: test/binary-search-tree/RandomizedBinarySearchTree-med.test.cpp
---
