---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/Solver.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ull = unsigned long long;\n\n#define REP(i,n)\
    \ for(long long i = 0; i < (n); i++)\n#define FOR(i, m, n) for(long long i = (m);i\
    \ < (n); ++i)\n#define ALL(obj) (obj).begin(),(obj).end()\n#define SPEED cin.tie(0);ios::sync_with_stdio(false);\n\
    \ntemplate<class T> using V = vector<T>;\ntemplate<class T, class U> using P =\
    \ pair<T, U>;\n\nconst ll MOD = (ll)1e9 + 7;\nconst ll MOD2 = 998244353;\nconst\
    \ ll HIGHINF = (ll)1e18;\nconst ll LOWINF = (ll)1e15;\nconst long double PI =\
    \ 3.1415926535897932384626433;\n\ntemplate<typename T> vector<T> make_v(size_t\
    \ N,T init){return vector<T>(N,init);}\ntemplate<typename... T> auto make_v(size_t\
    \ N,T... t){return vector<decltype(make_v(t...))>(N,make_v(t...));}\ntemplate\
    \ <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}\n\
    template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj)\
    \ {o << \"{\"; for (auto &x : obj) o << \" {\" << x.first << \" : \" << x.second\
    \ << \"}\" << \",\"; o << \" }\"; return o;}\ntemplate <class T>ostream &operator<<(ostream\
    \ &o, const set<T>&obj) {o << \"{\"; for (auto itr = obj.begin(); itr != obj.end();\
    \ ++itr) o << (itr != obj.begin() ? \", \" : \"\") << *itr; o << \"}\"; return\
    \ o;}\ntemplate <class T>ostream &operator<<(ostream &o, const multiset<T>&obj)\
    \ {o << \"{\"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr\
    \ != obj.begin() ? \", \" : \"\") << *itr; o << \"}\"; return o;}\ntemplate <class\
    \ T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << \"{\"; for (int\
    \ i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? \", \" : \"\") << obj[i]; o <<\
    \ \"}\"; return o;}\ntemplate <class T, class U>ostream &operator<<(ostream &o,\
    \ const pair<T, U>&obj) {o << \"{\" << obj.first << \", \" << obj.second << \"\
    }\"; return o;}\ntemplate <template <class tmp>  class T, class U> ostream &operator<<(ostream\
    \ &o, const T<U> &obj) {o << \"{\"; for (auto itr = obj.begin(); itr != obj.end();\
    \ ++itr)o << (itr != obj.begin() ? \", \" : \"\") << *itr; o << \"}\"; return\
    \ o;}\nvoid print(void) {cout << endl;}\ntemplate <class Head> void print(Head&&\
    \ head) {cout << head;print();}\ntemplate <class Head, class... Tail> void print(Head&&\
    \ head, Tail&&... tail) {cout << head << \" \";print(forward<Tail>(tail)...);}\n\
    template <class T> void chmax(T& a, const T b){a=max<T>(a,b);}\ntemplate <class\
    \ T> void chmin(T& a, const T b){a=min<T>(a,b);}\nvoid YN(bool flg) {cout << ((flg)\
    \ ? \"YES\" : \"NO\") << endl;}\nvoid Yn(bool flg) {cout << ((flg) ? \"Yes\" :\
    \ \"No\") << endl;}\nvoid yn(bool flg) {cout << ((flg) ? \"yes\" : \"no\") <<\
    \ endl;}\n\nint main() {\n  \n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\n\n#define REP(i,n) for(long long i = 0; i < (n);\
    \ i++)\n#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)\n#define ALL(obj)\
    \ (obj).begin(),(obj).end()\n#define SPEED cin.tie(0);ios::sync_with_stdio(false);\n\
    \ntemplate<class T> using V = vector<T>;\ntemplate<class T, class U> using P =\
    \ pair<T, U>;\n\nconst ll MOD = (ll)1e9 + 7;\nconst ll MOD2 = 998244353;\nconst\
    \ ll HIGHINF = (ll)1e18;\nconst ll LOWINF = (ll)1e15;\nconst long double PI =\
    \ 3.1415926535897932384626433;\n\ntemplate<typename T> vector<T> make_v(size_t\
    \ N,T init){return vector<T>(N,init);}\ntemplate<typename... T> auto make_v(size_t\
    \ N,T... t){return vector<decltype(make_v(t...))>(N,make_v(t...));}\ntemplate\
    \ <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}\n\
    template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj)\
    \ {o << \"{\"; for (auto &x : obj) o << \" {\" << x.first << \" : \" << x.second\
    \ << \"}\" << \",\"; o << \" }\"; return o;}\ntemplate <class T>ostream &operator<<(ostream\
    \ &o, const set<T>&obj) {o << \"{\"; for (auto itr = obj.begin(); itr != obj.end();\
    \ ++itr) o << (itr != obj.begin() ? \", \" : \"\") << *itr; o << \"}\"; return\
    \ o;}\ntemplate <class T>ostream &operator<<(ostream &o, const multiset<T>&obj)\
    \ {o << \"{\"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr\
    \ != obj.begin() ? \", \" : \"\") << *itr; o << \"}\"; return o;}\ntemplate <class\
    \ T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << \"{\"; for (int\
    \ i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? \", \" : \"\") << obj[i]; o <<\
    \ \"}\"; return o;}\ntemplate <class T, class U>ostream &operator<<(ostream &o,\
    \ const pair<T, U>&obj) {o << \"{\" << obj.first << \", \" << obj.second << \"\
    }\"; return o;}\ntemplate <template <class tmp>  class T, class U> ostream &operator<<(ostream\
    \ &o, const T<U> &obj) {o << \"{\"; for (auto itr = obj.begin(); itr != obj.end();\
    \ ++itr)o << (itr != obj.begin() ? \", \" : \"\") << *itr; o << \"}\"; return\
    \ o;}\nvoid print(void) {cout << endl;}\ntemplate <class Head> void print(Head&&\
    \ head) {cout << head;print();}\ntemplate <class Head, class... Tail> void print(Head&&\
    \ head, Tail&&... tail) {cout << head << \" \";print(forward<Tail>(tail)...);}\n\
    template <class T> void chmax(T& a, const T b){a=max<T>(a,b);}\ntemplate <class\
    \ T> void chmin(T& a, const T b){a=min<T>(a,b);}\nvoid YN(bool flg) {cout << ((flg)\
    \ ? \"YES\" : \"NO\") << endl;}\nvoid Yn(bool flg) {cout << ((flg) ? \"Yes\" :\
    \ \"No\") << endl;}\nvoid yn(bool flg) {cout << ((flg) ? \"yes\" : \"no\") <<\
    \ endl;}\n\nint main() {\n  \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/Solver.cpp
  requiredBy: []
  timestamp: '2020-01-09 00:30:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Solver.cpp
layout: document
redirect_from:
- /library/old/Solver.cpp
- /library/old/Solver.cpp.html
title: old/Solver.cpp
---
