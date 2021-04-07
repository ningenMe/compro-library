---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc151/tasks/abc151_f
  bundledCode: "#line 1 \"non-verified/SmallestEnclosingDisc.cpp\"\n\ntemplate <class\
    \ T> class SmallestEnclosingDisc{\n    inline T cross(const complex<T>& a, const\
    \ complex<T>& b) {return a.real()*b.imag() - a.imag()*b.real(); }\n    inline\
    \ T dot(const complex<T>& a, const complex<T>& b) { return a.real()*b.real() +\
    \ a.imag()*b.imag(); }\n    inline void makeCenter(const complex<T>& a,const complex<T>&\
    \ b) {\n        center = (a+b)/2.;\n        radius = abs(a-center);\n    }\n \
    \   inline void makeCenter(const complex<T>& a,const complex<T>& b,const complex<T>&\
    \ c) {\n        T s = norm(b-c),t = norm(c-a),u = norm(a-b),z = abs(cross(b-a,c-a));\n\
    \        center = (s*(t+u-s)*a+t*(u+s-t)*b+u*(s+t-u)*c)/(4*z*z);\n        radius\
    \ = abs(a-center);\n    }\n    inline bool isInCircle(const complex<T>& point){\n\
    \        return norm(point-center) <= radius*radius + eps;\n    } \n    vector<complex<T>>\
    \ points;\n    T eps;\npublic:\n    complex<T> center;\n    T radius;\n\n    SmallestEnclosingDisc(T\
    \ eps = 1e-9): eps(eps){\n    }\n    inline void addPoint(complex<T> point){\n\
    \        points.push_back(point);\n    }\n    void solve(){\n        int num =\
    \ points.size();\n        if(num == 1) {\n            radius = 0;\n          \
    \  center = points.front();\n            return;\n        }\n        random_device\
    \ seed_gen;\n        mt19937 engine(seed_gen());\n        shuffle(points.begin(),\
    \ points.end(), engine);\n        makeCenter(points[0],points[1]);\n        for(int\
    \ i = 2; i < num; ++i){\n            if(isInCircle(points[i])) continue;\n   \
    \         makeCenter(points[0],points[i]);\n            for(int j = 1; j < i;\
    \ ++j) {\n                if(isInCircle(points[j])) continue;\n              \
    \  makeCenter(points[i],points[j]);\n                for(int k = 0; k < j; ++k)\
    \ {\n                    if(isInCircle(points[k])) continue;\n               \
    \     makeCenter(points[i],points[j],points[k]);\n                }\n        \
    \    }\n        }\n    }\n};\n\n//verify https://atcoder.jp/contests/abc151/tasks/abc151_f\n"
  code: "\ntemplate <class T> class SmallestEnclosingDisc{\n    inline T cross(const\
    \ complex<T>& a, const complex<T>& b) {return a.real()*b.imag() - a.imag()*b.real();\
    \ }\n    inline T dot(const complex<T>& a, const complex<T>& b) { return a.real()*b.real()\
    \ + a.imag()*b.imag(); }\n    inline void makeCenter(const complex<T>& a,const\
    \ complex<T>& b) {\n        center = (a+b)/2.;\n        radius = abs(a-center);\n\
    \    }\n    inline void makeCenter(const complex<T>& a,const complex<T>& b,const\
    \ complex<T>& c) {\n        T s = norm(b-c),t = norm(c-a),u = norm(a-b),z = abs(cross(b-a,c-a));\n\
    \        center = (s*(t+u-s)*a+t*(u+s-t)*b+u*(s+t-u)*c)/(4*z*z);\n        radius\
    \ = abs(a-center);\n    }\n    inline bool isInCircle(const complex<T>& point){\n\
    \        return norm(point-center) <= radius*radius + eps;\n    } \n    vector<complex<T>>\
    \ points;\n    T eps;\npublic:\n    complex<T> center;\n    T radius;\n\n    SmallestEnclosingDisc(T\
    \ eps = 1e-9): eps(eps){\n    }\n    inline void addPoint(complex<T> point){\n\
    \        points.push_back(point);\n    }\n    void solve(){\n        int num =\
    \ points.size();\n        if(num == 1) {\n            radius = 0;\n          \
    \  center = points.front();\n            return;\n        }\n        random_device\
    \ seed_gen;\n        mt19937 engine(seed_gen());\n        shuffle(points.begin(),\
    \ points.end(), engine);\n        makeCenter(points[0],points[1]);\n        for(int\
    \ i = 2; i < num; ++i){\n            if(isInCircle(points[i])) continue;\n   \
    \         makeCenter(points[0],points[i]);\n            for(int j = 1; j < i;\
    \ ++j) {\n                if(isInCircle(points[j])) continue;\n              \
    \  makeCenter(points[i],points[j]);\n                for(int k = 0; k < j; ++k)\
    \ {\n                    if(isInCircle(points[k])) continue;\n               \
    \     makeCenter(points[i],points[j],points[k]);\n                }\n        \
    \    }\n        }\n    }\n};\n\n//verify https://atcoder.jp/contests/abc151/tasks/abc151_f\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/SmallestEnclosingDisc.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/SmallestEnclosingDisc.cpp
layout: document
redirect_from:
- /library/non-verified/SmallestEnclosingDisc.cpp
- /library/non-verified/SmallestEnclosingDisc.cpp.html
title: non-verified/SmallestEnclosingDisc.cpp
---
