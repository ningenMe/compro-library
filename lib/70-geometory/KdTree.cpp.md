---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometory/KdTree.test.cpp
    title: test/geometory/KdTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/geometory/KdTree.md
    document_title: "KdTree - 2\u6B21\u5143\u9802\u70B9\u5206\u985E\u6728"
    links: []
  bundledCode: "#line 1 \"lib/70-geometory/KdTree.cpp\"\n/*\n * @title KdTree - 2\u6B21\
    \u5143\u9802\u70B9\u5206\u985E\u6728\n * @docs md/geometory/KdTree.md\n */\ntemplate<class\
    \ T> class KdTree{\n    struct Point{\n        T x,y;\n        int idx;\n    \
    \    friend ostream &operator<<(ostream &os, const Point& point) {return os <<\
    \ \"{\" << point.x << \", \" << point.y << \", \" << point.idx << \"}\";}\n  \
    \  };\n    struct Node{\n        int depth,ch_l,ch_r;\n        Point point;\n\
    \        Node(const Point point,const int depth):point(point),depth(depth),ch_l(-1),ch_r(-1){};\n\
    \    };\n    vector<Node> tree;\n\n    //[l,r)\n    void dfs(int depth, int l,\
    \ int r, vector<Point>& points) {\n        if(r-l==1) {\n            tree.push_back(Node(points[l],depth));\n\
    \            return;\n        }\n        int m = (l+r)/2;\n        int root =\
    \ tree.size();\n        if(depth&1) sort(points.begin()+l,points.begin()+r,[&](Point\
    \ a,Point b){return a.y < b.y;});\n        else        sort(points.begin()+l,points.begin()+r,[&](Point\
    \ a,Point b){return a.x < b.x;});\n        tree.push_back(Node(points[m],depth));\n\
    \        if(l<m) {\n            tree[root].ch_l = tree.size();\n            dfs(depth+1,l,m,points);\n\
    \        }\n        if(m+1<r) {\n            tree[root].ch_r = tree.size();\n\
    \            dfs(depth+1,m+1,r,points);\n        }\n    }\n    void print(int\
    \ p) {\n        if(p==-1) return;\n        print(tree[p].ch_l);\n        cout\
    \ << p << \", \" << tree[p].point << \", \";\n        print(tree[p].ch_r);\n \
    \       if(p==0) cout << endl;\n    }\npublic:\n    //(x,y)\u306Evector\n    KdTree(const\
    \ vector<pair<T,T>>& arg_points) {\n        vector<Point> points(arg_points.size());\n\
    \        for(int i=0;i<arg_points.size();++i) points[i] = {arg_points[i].first,arg_points[i].second,i};\n\
    \        dfs(0,0,points.size(),points);\n    }\n    void print() {\n        print(0);\n\
    \    }\n    //x\u533A\u9593[x1,x2],y\u533A\u9593[y1,y2]\u306B\u56F2\u307E\u308C\
    \u308B\u9818\u57DF\u5185\u306E\u6570 x1<=x2 && y1 <= y2\n    vector<Point> points_in_range(const\
    \ T& x1,const T& x2,const T& y1,const T& y2) {\n        vector<Point> ret;\n \
    \       stack<int> st; st.push(0);\n        while(st.size()) {\n            int\
    \ p=st.top(); st.pop();\n            if(x1<=tree[p].point.x&&tree[p].point.x<=x2&&y1<=tree[p].point.y&&tree[p].point.y<=y2)\
    \ {\n                ret.emplace_back(tree[p].point);\n            }\n       \
    \     if(tree[p].depth&1) {//y\n                if(tree[p].ch_r!=-1 && tree[p].point.y\
    \ <= y2) st.push(tree[p].ch_r);\n                if(tree[p].ch_l!=-1 && y1 <=\
    \ tree[p].point.y) st.push(tree[p].ch_l);\n            }\n            else { \
    \              //x\n                if(tree[p].ch_r!=-1 && tree[p].point.x <=\
    \ x2) st.push(tree[p].ch_r);\n                if(tree[p].ch_l!=-1 && x1 <= tree[p].point.x)\
    \ st.push(tree[p].ch_l);\n            }\n        }\n        sort(ret.begin(),ret.end(),[&](Point\
    \ l,Point r){return l.idx < r.idx;});\n        return ret;\n    }\n};\n"
  code: "/*\n * @title KdTree - 2\u6B21\u5143\u9802\u70B9\u5206\u985E\u6728\n * @docs\
    \ md/geometory/KdTree.md\n */\ntemplate<class T> class KdTree{\n    struct Point{\n\
    \        T x,y;\n        int idx;\n        friend ostream &operator<<(ostream\
    \ &os, const Point& point) {return os << \"{\" << point.x << \", \" << point.y\
    \ << \", \" << point.idx << \"}\";}\n    };\n    struct Node{\n        int depth,ch_l,ch_r;\n\
    \        Point point;\n        Node(const Point point,const int depth):point(point),depth(depth),ch_l(-1),ch_r(-1){};\n\
    \    };\n    vector<Node> tree;\n\n    //[l,r)\n    void dfs(int depth, int l,\
    \ int r, vector<Point>& points) {\n        if(r-l==1) {\n            tree.push_back(Node(points[l],depth));\n\
    \            return;\n        }\n        int m = (l+r)/2;\n        int root =\
    \ tree.size();\n        if(depth&1) sort(points.begin()+l,points.begin()+r,[&](Point\
    \ a,Point b){return a.y < b.y;});\n        else        sort(points.begin()+l,points.begin()+r,[&](Point\
    \ a,Point b){return a.x < b.x;});\n        tree.push_back(Node(points[m],depth));\n\
    \        if(l<m) {\n            tree[root].ch_l = tree.size();\n            dfs(depth+1,l,m,points);\n\
    \        }\n        if(m+1<r) {\n            tree[root].ch_r = tree.size();\n\
    \            dfs(depth+1,m+1,r,points);\n        }\n    }\n    void print(int\
    \ p) {\n        if(p==-1) return;\n        print(tree[p].ch_l);\n        cout\
    \ << p << \", \" << tree[p].point << \", \";\n        print(tree[p].ch_r);\n \
    \       if(p==0) cout << endl;\n    }\npublic:\n    //(x,y)\u306Evector\n    KdTree(const\
    \ vector<pair<T,T>>& arg_points) {\n        vector<Point> points(arg_points.size());\n\
    \        for(int i=0;i<arg_points.size();++i) points[i] = {arg_points[i].first,arg_points[i].second,i};\n\
    \        dfs(0,0,points.size(),points);\n    }\n    void print() {\n        print(0);\n\
    \    }\n    //x\u533A\u9593[x1,x2],y\u533A\u9593[y1,y2]\u306B\u56F2\u307E\u308C\
    \u308B\u9818\u57DF\u5185\u306E\u6570 x1<=x2 && y1 <= y2\n    vector<Point> points_in_range(const\
    \ T& x1,const T& x2,const T& y1,const T& y2) {\n        vector<Point> ret;\n \
    \       stack<int> st; st.push(0);\n        while(st.size()) {\n            int\
    \ p=st.top(); st.pop();\n            if(x1<=tree[p].point.x&&tree[p].point.x<=x2&&y1<=tree[p].point.y&&tree[p].point.y<=y2)\
    \ {\n                ret.emplace_back(tree[p].point);\n            }\n       \
    \     if(tree[p].depth&1) {//y\n                if(tree[p].ch_r!=-1 && tree[p].point.y\
    \ <= y2) st.push(tree[p].ch_r);\n                if(tree[p].ch_l!=-1 && y1 <=\
    \ tree[p].point.y) st.push(tree[p].ch_l);\n            }\n            else { \
    \              //x\n                if(tree[p].ch_r!=-1 && tree[p].point.x <=\
    \ x2) st.push(tree[p].ch_r);\n                if(tree[p].ch_l!=-1 && x1 <= tree[p].point.x)\
    \ st.push(tree[p].ch_l);\n            }\n        }\n        sort(ret.begin(),ret.end(),[&](Point\
    \ l,Point r){return l.idx < r.idx;});\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/70-geometory/KdTree.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometory/KdTree.test.cpp
documentation_of: lib/70-geometory/KdTree.cpp
layout: document
redirect_from:
- /library/lib/70-geometory/KdTree.cpp
- /library/lib/70-geometory/KdTree.cpp.html
title: "KdTree - 2\u6B21\u5143\u9802\u70B9\u5206\u985E\u6728"
---
### KdTree
- 2次元頂点分類木
- staticなクエリのみに対応
- 2次元座標の特定の領域に含まれる頂点集合を求めることができる
- これは他のライブラリと違って(x,y)で与える

### コンストラクタ
- KdTree(const vector<pair<T,T>>& arg_points)
  - arg_pointsは頂点集合のvector。(x,y)がたくさんある感じ
  - 計算量は$O(N(\logN)^2)
  
### メソッド
- vector<Point> points_in_range(const T& x1,const T& x2,const T& y1,const T& y2) 
  - x区間[x1,x2],y区間[y1,y2]両方に囲まれる領域内の頂点集合を返す x1<=x2 && y1 <= y2 を要請する。
  - Pointは{x,y,idx}の構造体。idxはコンストラクタに渡したときのindex
  - 計算量は頂点集合の個数を$K$としてO(\sqrt(N)+K)
- void print() 
  - デバッグ用