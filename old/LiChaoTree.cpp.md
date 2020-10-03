---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/code-festival-2018-final-open/tasks/code_festival_2018_final_c
    - https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
  bundledCode: "#line 1 \"old/LiChaoTree.cpp\"\ntemplate<class Operator> class LiChaoTree{\n\
    \tOperator Op;                                         //Operator \u6F14\u7B97\
    \u5B50\u3001\u578B\u3001\u5358\u4F4D\u5143\u3092\u6301\u3064\n\tusing typeValue\
    \ = decltype(Op.unitValue);            //value\u306E\u578B\n\tstruct domain{typeValue\
    \ l,c,r;};\n\tsize_t length;\n\ttypeValue yInf;\n\tvector<typeValue> x;\n\tvector<pair<typeValue,typeValue>>\
    \ node;\n\tvector<domain> range;\n\npublic:\n\t//\u53D6\u308A\u3046\u308Bx\u306E\
    \u5024\u3092\u5148\u8AAD\u307F\u3057\u3066\u6E21\u3059\n\tLiChaoTree(vector<typeValue>\
    \ argx) {\n\t\tsort(argx.begin(),argx.end());\n\t\targx.erase(unique(argx.begin(),argx.end()),argx.end());\n\
    \t\ttypeValue maxi = argx.back() + 1;\n\t\tfor (length = 1; length < argx.size();\
    \ length *= 2);\n\t\tx.resize(length + 1, maxi);\n\t\tnode.resize(2 * length,\
    \ {0,Op.unitValue});\n\t\trange.resize(2 * length,  {maxi,maxi,maxi});\n\t\tfor\
    \ (int i = 0; i < argx.size(); ++i) x[i] = argx[i];\n\t\tfor (int i = 0; i < argx.size();\
    \ ++i) range[i + length] = {x[i],-1,x[i+1]};\n\t\tfor (int i = length-1; 1 <=\
    \ i; --i) range[i] = {range[(i<<1)+0].l,range[(i<<1)+0].r,range[(i<<1)+1].r};\n\
    \t}\n\n\t//return y = ax+b\n\tinline typeValue f(pair<typeValue,typeValue>& line,typeValue&\
    \ t)\t{\n\t\treturn line.first*t + line.second;\n\t}\n\n\t//\u76F4\u7DDA\u8FFD\
    \u52A0\u3000ax + b  O(logN)\n\tvoid update(pair<typeValue,typeValue> line,int\
    \ i = 1) {\n\t\twhile(i < 2*length){\n\t\t\ttypeValue& xl = range[i].l;\n\t\t\t\
    typeValue& xc = range[i].c;\n\t\t\ttypeValue& xr = range[i].r;\n\t\t\tint flgl\
    \ = Op.funcCompare(f(line,xl),f(node[i],xl));\n\t\t\tint flgc = Op.funcCompare(f(line,xc),f(node[i],xc));\n\
    \t\t\tint flgr = Op.funcCompare(f(line,xr),f(node[i],xr));\n\t\t\tif(flgl && flgr)\
    \ node[i] = line;\n\t\t\tif(flgl == flgr) break;\n\t\t\tif((flgl && flgc) || (flgc\
    \ && flgr)) swap(node[i],line);\n\t\t\tif((flgl &&!flgc) || (flgc && flgr)) i\
    \ = (i<<1)+0;\n\t\t\tif((flgl && flgc) || (!flgc&& flgr)) i = (i<<1)+1;\n\t\t\
    }\n\t}\n\n\t//\u7DDA\u5206\u8FFD\u52A0\u3000y = ax + b [l,r) O((logN)^2)\n\tvoid\
    \ update(pair<typeValue,typeValue> line, typeValue L, typeValue R) {\n\t\tint\
    \ l = (lower_bound(x.begin(),x.end(),L) - x.begin()) + length;\n\t\tint r = (lower_bound(x.begin(),x.end(),R)\
    \ - x.begin()) + length - 1;\n\t\tfor(r++; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1)\
    \ update(line,l),l++;\n\t\t\tif(r&1) --r,update(line,r);\n\t\t}\n\t}\n\n\t//\u5024\
    \u3092\u53D6\u5F97 t is in {x}\n\ttypeValue get(typeValue t) {\n\t\tint i = (lower_bound(x.begin(),x.end(),t)\
    \ - x.begin()) + length;\n\t\ttypeValue res = Op.unitValue;\n\t\tfor(;1<=i;i>>=1)\
    \ if(Op.funcCompare(f(node[i],t),res)) res = f(node[i],t);\n\t\treturn res; \n\
    \t}\n\n\tvoid print(){\n\t\t// cout << \"{ \" << get(0,1);\n\t\t// for(int i =\
    \ 1; i < length; ++i) cout << \", \" << get(i,i+1);\n\t\t// cout << \" }\" <<\
    \ endl;\n\t\tfor(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t\tcout << node[i]\
    \ << \" \";\n\t\t\tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t}\n\t\tfor(int\
    \ i = 1,j = 1; i < 2*length; ++i) {\n\t\t\tcout << \"{\" << range[i].l << \",\
    \ \" << range[i].c << \", \" << range[i].r << \"}\" << \" \";\n\t\t\tif(i==((1<<j)-1)\
    \ && ++j) cout << endl;\n\t\t}\n\t}\n};\n\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\
    \ntemplate<class typeValue> struct valueMin {\n\ttypeValue unitValue = 3e18;\n\
    \tbool funcCompare(typeValue l,typeValue r){return l<r;}\n};\n\n// verify https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c\n\
    // verify https://atcoder.jp/contests/code-festival-2018-final-open/tasks/code_festival_2018_final_c\n\
    \n"
  code: "template<class Operator> class LiChaoTree{\n\tOperator Op;              \
    \                           //Operator \u6F14\u7B97\u5B50\u3001\u578B\u3001\u5358\
    \u4F4D\u5143\u3092\u6301\u3064\n\tusing typeValue = decltype(Op.unitValue);  \
    \          //value\u306E\u578B\n\tstruct domain{typeValue l,c,r;};\n\tsize_t length;\n\
    \ttypeValue yInf;\n\tvector<typeValue> x;\n\tvector<pair<typeValue,typeValue>>\
    \ node;\n\tvector<domain> range;\n\npublic:\n\t//\u53D6\u308A\u3046\u308Bx\u306E\
    \u5024\u3092\u5148\u8AAD\u307F\u3057\u3066\u6E21\u3059\n\tLiChaoTree(vector<typeValue>\
    \ argx) {\n\t\tsort(argx.begin(),argx.end());\n\t\targx.erase(unique(argx.begin(),argx.end()),argx.end());\n\
    \t\ttypeValue maxi = argx.back() + 1;\n\t\tfor (length = 1; length < argx.size();\
    \ length *= 2);\n\t\tx.resize(length + 1, maxi);\n\t\tnode.resize(2 * length,\
    \ {0,Op.unitValue});\n\t\trange.resize(2 * length,  {maxi,maxi,maxi});\n\t\tfor\
    \ (int i = 0; i < argx.size(); ++i) x[i] = argx[i];\n\t\tfor (int i = 0; i < argx.size();\
    \ ++i) range[i + length] = {x[i],-1,x[i+1]};\n\t\tfor (int i = length-1; 1 <=\
    \ i; --i) range[i] = {range[(i<<1)+0].l,range[(i<<1)+0].r,range[(i<<1)+1].r};\n\
    \t}\n\n\t//return y = ax+b\n\tinline typeValue f(pair<typeValue,typeValue>& line,typeValue&\
    \ t)\t{\n\t\treturn line.first*t + line.second;\n\t}\n\n\t//\u76F4\u7DDA\u8FFD\
    \u52A0\u3000ax + b  O(logN)\n\tvoid update(pair<typeValue,typeValue> line,int\
    \ i = 1) {\n\t\twhile(i < 2*length){\n\t\t\ttypeValue& xl = range[i].l;\n\t\t\t\
    typeValue& xc = range[i].c;\n\t\t\ttypeValue& xr = range[i].r;\n\t\t\tint flgl\
    \ = Op.funcCompare(f(line,xl),f(node[i],xl));\n\t\t\tint flgc = Op.funcCompare(f(line,xc),f(node[i],xc));\n\
    \t\t\tint flgr = Op.funcCompare(f(line,xr),f(node[i],xr));\n\t\t\tif(flgl && flgr)\
    \ node[i] = line;\n\t\t\tif(flgl == flgr) break;\n\t\t\tif((flgl && flgc) || (flgc\
    \ && flgr)) swap(node[i],line);\n\t\t\tif((flgl &&!flgc) || (flgc && flgr)) i\
    \ = (i<<1)+0;\n\t\t\tif((flgl && flgc) || (!flgc&& flgr)) i = (i<<1)+1;\n\t\t\
    }\n\t}\n\n\t//\u7DDA\u5206\u8FFD\u52A0\u3000y = ax + b [l,r) O((logN)^2)\n\tvoid\
    \ update(pair<typeValue,typeValue> line, typeValue L, typeValue R) {\n\t\tint\
    \ l = (lower_bound(x.begin(),x.end(),L) - x.begin()) + length;\n\t\tint r = (lower_bound(x.begin(),x.end(),R)\
    \ - x.begin()) + length - 1;\n\t\tfor(r++; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1)\
    \ update(line,l),l++;\n\t\t\tif(r&1) --r,update(line,r);\n\t\t}\n\t}\n\n\t//\u5024\
    \u3092\u53D6\u5F97 t is in {x}\n\ttypeValue get(typeValue t) {\n\t\tint i = (lower_bound(x.begin(),x.end(),t)\
    \ - x.begin()) + length;\n\t\ttypeValue res = Op.unitValue;\n\t\tfor(;1<=i;i>>=1)\
    \ if(Op.funcCompare(f(node[i],t),res)) res = f(node[i],t);\n\t\treturn res; \n\
    \t}\n\n\tvoid print(){\n\t\t// cout << \"{ \" << get(0,1);\n\t\t// for(int i =\
    \ 1; i < length; ++i) cout << \", \" << get(i,i+1);\n\t\t// cout << \" }\" <<\
    \ endl;\n\t\tfor(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t\tcout << node[i]\
    \ << \" \";\n\t\t\tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t}\n\t\tfor(int\
    \ i = 1,j = 1; i < 2*length; ++i) {\n\t\t\tcout << \"{\" << range[i].l << \",\
    \ \" << range[i].c << \", \" << range[i].r << \"}\" << \" \";\n\t\t\tif(i==((1<<j)-1)\
    \ && ++j) cout << endl;\n\t\t}\n\t}\n};\n\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\
    \ntemplate<class typeValue> struct valueMin {\n\ttypeValue unitValue = 3e18;\n\
    \tbool funcCompare(typeValue l,typeValue r){return l<r;}\n};\n\n// verify https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c\n\
    // verify https://atcoder.jp/contests/code-festival-2018-final-open/tasks/code_festival_2018_final_c\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: old/LiChaoTree.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:21:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/LiChaoTree.cpp
layout: document
redirect_from:
- /library/old/LiChaoTree.cpp
- /library/old/LiChaoTree.cpp.html
title: old/LiChaoTree.cpp
---
