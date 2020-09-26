---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/segment/Rbst.cpp
    title: "Rbst - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
  - icon: ':question:'
    path: lib/geometory/ConvexHullTrick.cpp
    title: "ConvexHullTrick - \u975E\u5358\u8ABFCHT"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/409
    links:
    - https://yukicoder.me/problems/no/409
  bundledCode: "#line 1 \"test/geometory/ConvexHullTrick-max.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/409\"\n\n#include <iostream>\n#include <vector>\n\
    #include <queue>\nusing namespace std;\n#line 1 \"lib/segment/Rbst.cpp\"\n/*\n\
    \ * @title Rbst - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\n * @docs md/segment/Rbst.md\n\
    \ */\ntemplate<class Operator> class Rbst {\n\tusing TypeNode = typename Operator::TypeNode;\n\
    \tunsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\t\
    unsigned int xor_shift() {\n\t\tunsigned int t = (x ^ (x << 11)); x = y; y = z;\
    \ z = w;\n\t\treturn (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n\t}\n\tstruct Node\
    \ {\n\t\tNode *left, *right;\n\t\tTypeNode val;\n\t\tint size;\n\t\tTypeNode sum;\n\
    \n\t\tNode() : val(Operator::unit_node), size(1), sum(Operator::unit_node) {\n\
    \t\t\tleft = right = nullptr;\n\t\t}\n\t\tNode(TypeNode v) : val(v), size(1),\
    \ sum(v) {\n\t\t\tleft = right = nullptr;\n\t\t}\n\t};\n\tNode* root;\n\tinline\
    \ int size(Node *node) {\n\t\treturn node==nullptr ? 0 : node->size;\n\t}\n\t\
    inline TypeNode sum(Node *node) {\n\t\treturn node==nullptr ? Operator::unit_node\
    \ : node->sum;\n\t}\n\tinline Node* update(Node *node) {\n\t\tnode->size = size(node->left)\
    \ + size(node->right) + 1;\n\t\tnode->sum = Operator::func_node(sum(node->left),sum(node->right),node->val);\n\
    \t\treturn node;\n\t}\n\tinline TypeNode get(Node *node, int k) {\n\t\tif (node==nullptr)\
    \ return Operator::unit_node;\n\t\tif (k == size(node->left)) return node->val;\n\
    \t\tif (k < size(node->left)) return get(node->left, k);\n\t\telse return get(node->right,\
    \ k-1 - size(node->left));\n\t}\n\tinline int lower_bound(Node *node, TypeNode\
    \ val) {\n\t\tif (node==nullptr) return 0;\n\t\tif (val <= node->val) return lower_bound(node->left,\
    \ val);\n\t\telse return size(node->left) + lower_bound(node->right, val) + 1;\n\
    \t}\n\tinline int upper_bound(Node *node, TypeNode val) {\n\t\tif (node==nullptr)\
    \ return 0;\n\t\tif (val >= node->val) return size(node->left) + upper_bound(node->right,\
    \ val) + 1;\n\t\telse return upper_bound(node->left, val);\n\t}\n\tNode* merge(Node\
    \ *left, Node *right) {\n\t\tif (left==nullptr)  return right;\n\t\tif (right==nullptr)\
    \ return left;\n\t\tif (xor_shift() % (left->size + right->size) < left->size)\
    \ {\n\t\t\tleft->right = merge(left->right, right);\n\t\t\treturn update(left);\n\
    \t\t}\n\t\telse {\n\t\t\tright->left = merge(left, right->left);\n\t\t\treturn\
    \ update(right);\n\t\t}\n\t}\n\tpair<Node*, Node*> split(Node* node, int k) {\n\
    \t\tif (node==nullptr) return make_pair(node, node);\n\t\tif (k <= size(node->left))\
    \ {\n\t\t\tpair<Node*, Node*> sub = split(node->left, k);\n\t\t\tnode->left =\
    \ sub.second;\n\t\t\treturn make_pair(sub.first, update(node));\n\t\t}\n\t\telse\
    \ {\n\t\t\tpair<Node*, Node*> sub = split(node->right, k-1 - size(node->left));\n\
    \t\t\tnode->right = sub.first;\n\t\t\treturn make_pair(update(node), sub.second);\n\
    \t\t}\n\t}\n\tvoid print(Node *node) {\n\t\tif (node==nullptr) return;\n\t\tprint(node->left);\n\
    \t\tcout << node->val << \" \";\n\t\tprint(node->right);\n\t}\n\tRbst(Node* node):root(node){}\n\
    public:\n\tRbst() : root(nullptr) {}\n\tinline int size() {\n\t\treturn size(this->root);\n\
    \t}\n\tinline TypeNode sum() {\n\t\treturn sum(this->root);\n\t}\n\tinline int\
    \ lower_bound(TypeNode val) {\n\t\treturn lower_bound(this->root, val);\n\t}\n\
    \tinline int upper_bound(TypeNode val) {\n\t\treturn upper_bound(this->root, val);\n\
    \t}\n\tinline int empty(void) {\n\t\treturn bool(size()==0);\n\t}\n\tinline int\
    \ count(TypeNode val) {\n\t\treturn upper_bound(val) - lower_bound(val);\n\t}\n\
    \tinline TypeNode get(int k) {\n\t\treturn get(this->root, k);\n\t}\n\tinline\
    \ TypeNode get_median() {\n\t\t//\u5947\u6570\u306E\u6642N/2\n\t\treturn get(this->root,\
    \ (size()-1)/2);\n\t}\n\tvoid merge(Rbst another) {\n\t\troot = merge(this->root,\
    \ another.root);\n\t}\n\tvoid insert(const TypeNode val) {\n\t\tpair<Node*, Node*>\
    \ sub = split(this->root, this->lower_bound(val));\n\t\tthis->root = this->merge(this->merge(sub.first,\
    \ new Node(val)), sub.second);\n\t}\n\tvoid erase(const TypeNode val) {\n\t\t\
    if (!this->count(val)) return;\n\t\tpair<Node*, Node*> sub = this->split(this->root,\
    \ this->lower_bound(val));\n\t\tthis->root = this->merge(sub.first, this->split(sub.second,\
    \ 1).second);\n\t}\n\tvoid print() {\n\t\tcout << \"{\";\n\t\tprint(this->root);\n\
    \t\tcout << \"}\" << endl;\n\t}\n};\n//https://atcoder.jp/contests/abc154/tasks/abc154_c\n\
    //https://atcoder.jp/contests/arc033/tasks/arc033_3\n//https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_c\n\
    //https://yukicoder.me/problems/no/919\n//https://yukicoder.me/problems/no/649\n\
    //https://yukicoder.me/problems/no/822\n\ntemplate<class T> struct NodeSum {\n\
    \tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return\
    \ l+c+r;}\n};\n\ntemplate<class T> struct NodeSimple {\n\tusing TypeNode = T;\n\
    \tinline static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeNode\
    \ func_node(TypeNode l,TypeNode c,TypeNode r){return 0;}\n};\n#line 1 \"lib/geometory/ConvexHullTrick.cpp\"\
    \n/*\n * @title ConvexHullTrick - \u975E\u5358\u8ABFCHT\n * @docs md/geometory/ConvexHullTrick.md\n\
    \ */\ntemplate<class Operator> class ConvexHullTrick {\nprivate:\n\tusing TypeValue\
    \ = typename Operator::TypeValue;\n\tstruct NodePair {\n\t\tusing TypeNode = pair<TypeValue,TypeValue>;\n\
    \t\tinline static constexpr TypeNode unit_node = {0,Operator::unit_value};\n\t\
    \tinline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return\
    \ {0,0};}\n\t};\n\tRbst<NodePair> lines;\n\n\t//3\u76F4\u7DDA\u306B\u95A2\u3057\
    \u3066line2\u304C\u5FC5\u8981\u304B\u78BA\u8A8D (\u3053\u306E\u3068\u304D a1 <\
    \ a2 < a3\u304C\u5FC5\u8981=rbst\u306E\u9806\u305D\u306E\u307E\u307E)\n\tinline\
    \ int is_required(const pair<TypeValue,TypeValue>& line1, const pair<TypeValue,TypeValue>&\
    \ line2, const pair<TypeValue,TypeValue>& line3) {\n\t\treturn Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \t}\n\t\n\t//y=ax+b\u306E\u5024\n\tinline TypeValue y(const pair<TypeValue,TypeValue>\
    \ line, TypeValue x) {\n\t\treturn line.first * x + line.second;\n\t}\n\npublic:\n\
    \tConvexHullTrick() {\n\t\t// do nothing\n\t} \n\n\t//ax+b\u3092\u8FFD\u52A0\n\
    \tvoid insert(const TypeValue a, const TypeValue b) {\n\t\tinsert({a,b});\n\t\
    }\n\t//ax+b\u3092\u8FFD\u52A0 armortized O(log(N))\n\tvoid insert(const pair<TypeValue,TypeValue>\
    \ line) {\n\t\tint i,flg=1;\n\t\ti=lines.lower_bound(line);\n\t\tauto l=lines.get(i-1);\n\
    \t\tauto r=lines.get(i);\n\t\t//l\u3068\u50BE\u304D\u304C\u540C\u3058\u306A\u3089\
    \u3001\u3069\u3061\u3089\u304B\u3092erase\n\t\tif(flg && l.second!=Operator::unit_value\
    \ && l.first==line.first) {\n\t\t\tif(Operator::func_compare(l.second,line.second))\
    \ return;\n\t\t\telse lines.erase(l),flg=0;\n\t\t}\t\n\t\t//r\u3068\u50BE\u304D\
    \u304C\u540C\u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n\t\t\
    if(flg && r.second!=Operator::unit_value && line.first==r.first) {\n\t\t\tif(Operator::func_compare(r.second,line.second))\
    \ return;\n\t\t\telse lines.erase(r),flg=0;\n\t\t}\t\n\t\t//\u81EA\u8EAB\u304C\
    \u5FC5\u8981\u304B\u5224\u5B9A\n\t\tif(flg && l.second!=Operator::unit_value &&\
    \ r.second!=Operator::unit_value && !is_required(l,line,r)) return;\n\t\t//\u50BE\
    \u304D\u304C\u5C0F\u3055\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\u76F4\u7DDA\
    \u3092\u53D6\u308A\u9664\u304F\n\t\tfor(i=lines.lower_bound(line);i>=2&&!is_required(lines.get(i-2),\
    \ lines.get(i-1), line);i=lines.lower_bound(line)) lines.erase(lines.get(i-1));\n\
    \t\t//\u50BE\u304D\u304C\u5927\u304D\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n\t\tfor(i=lines.lower_bound(line);i+1<lines.size()&&!is_required(line,lines.get(i),lines.get(i+1));i=lines.lower_bound(line))\
    \ lines.erase(lines.get(i));\n\t\tlines.insert(line);\n\t}\n\t\n\t//O(log(N)^2)\n\
    \tTypeValue get(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1, md;\n\
    \t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn y(lines.get(ok),x);\n\t}\n\n\t//O(log(N)^2)\n\
    \tpair<TypeValue,TypeValue> get_line(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1,\
    \ md;\n\t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn lines.get(ok);\n\t}\n\n\tvoid print() {\n\t\t\
    lines.print();\n\t}\n};\n\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMin {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = 3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l<r;}\n};\n\n//\u6700\u5927\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMax {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = -3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l>r;}\n};\n#line 9 \"test/geometory/ConvexHullTrick-max.test.cpp\"\
    \nusing ll = long long;\n\nint main(void){\n\tll N,A,B,W; cin >> N >> A >> B >>\
    \ W;\n\tvector<ll> D(N+2,0);\n\tfor(int i = 1; i <= N; ++i) cin >> D[i];\n\t//\
    \ dp[i]=min{j:[0,i)} -> dp[j]+B*k*(k+1)/2-k*A+D[i] (k=i-j-1)\n\t//           \
    \         -> dp[j]+B*(i-j-1)*(i-j)/2-(i-j-1)*A+D[i]\n\t//                    ->\
    \ dp[j]+B/2*(i*i-2*i*j+j*j-i+j)-A*(i-j-1)+D[i]\n\t//                    -> (-B*j)*i\
    \  +  dp[j]+B/2*(j*j+j)+A*j  +  B/2*(i*i-i)-A*(i-1)+D[i] \n\t// dp[i]=-max{j:[0,i)}->\
    \ (B*j)*i  +  -{dp[j]+B/2*(j*j+j)+A*j} \n\t//                    ->\n\tvector<ll>\
    \ dp(N+2,1e15);\n\tdp[0]=W;\n\tConvexHullTrick<ValueMax<ll>> cht;\n\tcht.insert(0,-dp[0]);\n\
    \tfor(ll i=1;i<=N+1;++i){\n\t\tdp[i]=-cht.get(i) + B*(i*i-i)/2-A*(i-1)+D[i];\n\
    \t\tcht.insert(B*i,-(dp[i]+B*(i*i+i)/2+A*i));\n\t}\n\tcout << dp[N+1] << endl;\n\
    \treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/409\"\n\n#include <iostream>\n\
    #include <vector>\n#include <queue>\nusing namespace std;\n#include \"../../lib/segment/Rbst.cpp\"\
    \n#include \"../../lib/geometory/ConvexHullTrick.cpp\"\nusing ll = long long;\n\
    \nint main(void){\n\tll N,A,B,W; cin >> N >> A >> B >> W;\n\tvector<ll> D(N+2,0);\n\
    \tfor(int i = 1; i <= N; ++i) cin >> D[i];\n\t// dp[i]=min{j:[0,i)} -> dp[j]+B*k*(k+1)/2-k*A+D[i]\
    \ (k=i-j-1)\n\t//                    -> dp[j]+B*(i-j-1)*(i-j)/2-(i-j-1)*A+D[i]\n\
    \t//                    -> dp[j]+B/2*(i*i-2*i*j+j*j-i+j)-A*(i-j-1)+D[i]\n\t//\
    \                    -> (-B*j)*i  +  dp[j]+B/2*(j*j+j)+A*j  +  B/2*(i*i-i)-A*(i-1)+D[i]\
    \ \n\t// dp[i]=-max{j:[0,i)}-> (B*j)*i  +  -{dp[j]+B/2*(j*j+j)+A*j} \n\t//   \
    \                 ->\n\tvector<ll> dp(N+2,1e15);\n\tdp[0]=W;\n\tConvexHullTrick<ValueMax<ll>>\
    \ cht;\n\tcht.insert(0,-dp[0]);\n\tfor(ll i=1;i<=N+1;++i){\n\t\tdp[i]=-cht.get(i)\
    \ + B*(i*i-i)/2-A*(i-1)+D[i];\n\t\tcht.insert(B*i,-(dp[i]+B*(i*i+i)/2+A*i));\n\
    \t}\n\tcout << dp[N+1] << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/segment/Rbst.cpp
  - lib/geometory/ConvexHullTrick.cpp
  isVerificationFile: true
  path: test/geometory/ConvexHullTrick-max.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometory/ConvexHullTrick-max.test.cpp
layout: document
redirect_from:
- /verify/test/geometory/ConvexHullTrick-max.test.cpp
- /verify/test/geometory/ConvexHullTrick-max.test.cpp.html
title: test/geometory/ConvexHullTrick-max.test.cpp
---
