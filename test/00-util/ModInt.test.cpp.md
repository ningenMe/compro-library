---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/ModInt.cpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1067
    links:
    - https://yukicoder.me/problems/no/1067
  bundledCode: "#line 1 \"test/00-util/ModInt.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1067\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <map>\n\
    #include <queue>\nusing namespace std;\n#line 1 \"lib/00-util/ModInt.cpp\"\n/*\n\
    \ * @title ModInt\n * @docs md/util/ModInt.md\n */\ntemplate<long long mod> class\
    \ ModInt {\npublic:\n    long long x;\n    constexpr ModInt():x(0) {}\n    constexpr\
    \ ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n    constexpr\
    \ ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}\n\
    \    constexpr ModInt &operator+=(const long long y) {ModInt p(y);if((x += p.x)\
    \ >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator+=(const int\
    \ y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    constexpr\
    \ ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return\
    \ *this;}\n    constexpr ModInt &operator-=(const long long y) {ModInt p(y);if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator-=(const\
    \ int y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n  \
    \  constexpr ModInt &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}\n\
    \    constexpr ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x\
    \ % mod);return *this;}\n    constexpr ModInt &operator*=(const int y) {ModInt\
    \ p(y);x = (x * p.x % mod);return *this;}\n    constexpr ModInt &operator^=(const\
    \ ModInt &p) {x = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator^=(const\
    \ long long y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    constexpr\
    \ ModInt &operator^=(const int y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n\
    \    constexpr ModInt &operator/=(const ModInt &p) {*this *= p.inv();return *this;}\n\
    \    constexpr ModInt &operator/=(const long long y) {ModInt p(y);*this *= p.inv();return\
    \ *this;}\n    constexpr ModInt &operator/=(const int y) {ModInt p(y);*this *=\
    \ p.inv();return *this;}\n    constexpr ModInt operator=(const int y) {ModInt\
    \ p(y);*this = p;return *this;}\n    constexpr ModInt operator=(const long long\
    \ y) {ModInt p(y);*this = p;return *this;}\n    constexpr ModInt operator-() const\
    \ {return ModInt(-x); }\n    constexpr ModInt operator++() {x++;if(x>=mod) x-=mod;return\
    \ *this;}\n    constexpr ModInt operator--() {x--;if(x<0) x+=mod;return *this;}\n\
    \    constexpr ModInt operator+(const ModInt &p) const { return ModInt(*this)\
    \ += p; }\n    constexpr ModInt operator-(const ModInt &p) const { return ModInt(*this)\
    \ -= p; }\n    constexpr ModInt operator*(const ModInt &p) const { return ModInt(*this)\
    \ *= p; }\n    constexpr ModInt operator/(const ModInt &p) const { return ModInt(*this)\
    \ /= p; }\n    constexpr ModInt operator^(const ModInt &p) const { return ModInt(*this)\
    \ ^= p; }\n    constexpr bool operator==(const ModInt &p) const { return x ==\
    \ p.x; }\n    constexpr bool operator!=(const ModInt &p) const { return x != p.x;\
    \ }\n    // ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b > 0) {t = a /\
    \ b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n    constexpr\
    \ ModInt inv() const {int a=x,b=mod,u=1,v=0,t=0,tmp=0;while(b > 0) {t = a / b;a-=t*b;tmp=a;a=b;b=tmp;u-=t*v;tmp=u;u=v;v=tmp;}\
    \ return ModInt(u);}\n    constexpr ModInt pow(long long n) const {ModInt ret(1),\
    \ mul(x);for(;n > 0;mul *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}\n  \
    \  friend ostream &operator<<(ostream &os, const ModInt &p) {return os << p.x;}\n\
    \    friend istream &operator>>(istream &is, ModInt &a) {long long t;is >> t;a\
    \ = ModInt<mod>(t);return (is);}\n};\nconstexpr long long MOD_998244353 = 998244353;\n\
    constexpr long long MOD_1000000007 = 1'000'000'000LL + 7; //'\n#line 10 \"test/00-util/ModInt.test.cpp\"\
    \n\nconstexpr long long MOD2 = 998244353;\nusing modint = ModInt<MOD2>;\nint main()\
    \ {\n    long long N,Q; cin >> N >> Q;\n    vector<long long> A(N+1,1234567890LL);\n\
    \    for(int i = 1; i <= N; ++i) cin >> A[i];\n\tsort(A.begin(),A.end(),greater<>());\n\
    \    A.push_back(0);\n    vector<long long> L(Q),R(Q),P(Q);\n    for(int i = 0;\
    \ i < Q; ++i) cin >> L[i] >> R[i] >> P[i];\n    priority_queue<pair<long long,int>>\
    \ pq;\n    for(int i = 0; i < Q; ++i) {\n        for(int j = L[i]; j <= R[i];\
    \ ++j) {\n            pq.push({j,P[i]});\n        }\n    }\n    vector<vector<modint>>\
    \ dp(2,vector<modint>(N+2));\n    dp[0][0]=1;\n    modint cnt = 1;\n    for(int\
    \ i = 1; i <= N; ++i) cnt *= A[i];\n    map<pair<long long,int>,modint> mp;\n\
    \    for(int i = 1; i <= N+1; ++i) {\n        while(pq.size() && pq.top().first>A[i])\
    \ {\n            auto p = pq.top();\n            pq.pop();\n            mp[p]=dp[(i-1)%2][p.second]*cnt;\n\
    \        }\n        for(int j = 0; j <= N; ++j) {\n            dp[i%2][j] = 0;\n\
    \        }\n        for(int j = 0; j <= i-1; ++j) {\n            dp[i%2][j+1]\
    \ += dp[(i-1)%2][j];\n            dp[i%2][j]   += dp[(i-1)%2][j]*(A[i]-1);\n \
    \       }\n        cnt /= A[i];\n    }\n    for(int i = 0; i < Q; ++i) {\n   \
    \     modint ans = 0;\n        for(int j = L[i]; j <= R[i]; ++j) {\n         \
    \   ans ^= mp[{j,P[i]}];\n        }\n        cout << ans << endl;\n    }\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1067\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n#include <map>\n#include <queue>\n\
    using namespace std;\n#include \"../../lib/00-util/ModInt.cpp\"\n\nconstexpr long\
    \ long MOD2 = 998244353;\nusing modint = ModInt<MOD2>;\nint main() {\n    long\
    \ long N,Q; cin >> N >> Q;\n    vector<long long> A(N+1,1234567890LL);\n    for(int\
    \ i = 1; i <= N; ++i) cin >> A[i];\n\tsort(A.begin(),A.end(),greater<>());\n \
    \   A.push_back(0);\n    vector<long long> L(Q),R(Q),P(Q);\n    for(int i = 0;\
    \ i < Q; ++i) cin >> L[i] >> R[i] >> P[i];\n    priority_queue<pair<long long,int>>\
    \ pq;\n    for(int i = 0; i < Q; ++i) {\n        for(int j = L[i]; j <= R[i];\
    \ ++j) {\n            pq.push({j,P[i]});\n        }\n    }\n    vector<vector<modint>>\
    \ dp(2,vector<modint>(N+2));\n    dp[0][0]=1;\n    modint cnt = 1;\n    for(int\
    \ i = 1; i <= N; ++i) cnt *= A[i];\n    map<pair<long long,int>,modint> mp;\n\
    \    for(int i = 1; i <= N+1; ++i) {\n        while(pq.size() && pq.top().first>A[i])\
    \ {\n            auto p = pq.top();\n            pq.pop();\n            mp[p]=dp[(i-1)%2][p.second]*cnt;\n\
    \        }\n        for(int j = 0; j <= N; ++j) {\n            dp[i%2][j] = 0;\n\
    \        }\n        for(int j = 0; j <= i-1; ++j) {\n            dp[i%2][j+1]\
    \ += dp[(i-1)%2][j];\n            dp[i%2][j]   += dp[(i-1)%2][j]*(A[i]-1);\n \
    \       }\n        cnt /= A[i];\n    }\n    for(int i = 0; i < Q; ++i) {\n   \
    \     modint ans = 0;\n        for(int j = L[i]; j <= R[i]; ++j) {\n         \
    \   ans ^= mp[{j,P[i]}];\n        }\n        cout << ans << endl;\n    }\n   \
    \ return 0;\n}\n"
  dependsOn:
  - lib/00-util/ModInt.cpp
  isVerificationFile: true
  path: test/00-util/ModInt.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:32:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/00-util/ModInt.test.cpp
layout: document
redirect_from:
- /verify/test/00-util/ModInt.test.cpp
- /verify/test/00-util/ModInt.test.cpp.html
title: test/00-util/ModInt.test.cpp
---
