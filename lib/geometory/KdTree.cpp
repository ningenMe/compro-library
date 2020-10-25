/*
 * @title KdTree - 2次元頂点分類木
 * @docs md/geometory/KdTree.md
 */
template<class T> class KdTree{
    struct Point{
        T x,y;
        int idx;
        friend ostream &operator<<(ostream &os, const Point& point) {return os << "{" << point.x << ", " << point.y << ", " << point.idx << "}";}
    };
    struct Node{
        int depth,ch_l,ch_r;
        Point point;
        Node(const Point point,const int depth):point(point),depth(depth),ch_l(-1),ch_r(-1){};
    };
    vector<Node> tree;

    //[l,r)
    void dfs(int depth, int l, int r, vector<Point>& points) {
        if(r-l==1) {
            tree.push_back(Node(points[l],depth));
            return;
        }
        int m = (l+r)/2;
        int root = tree.size();
        if(depth&1) sort(points.begin()+l,points.begin()+r,[&](Point a,Point b){return a.y < b.y;});
        else        sort(points.begin()+l,points.begin()+r,[&](Point a,Point b){return a.x < b.x;});
        tree.push_back(Node(points[m],depth));
        if(l<m) {
            tree[root].ch_l = tree.size();
            dfs(depth+1,l,m,points);
        }
        if(m+1<r) {
            tree[root].ch_r = tree.size();
            dfs(depth+1,m+1,r,points);
        }
    }
    void print(int p) {
        if(p==-1) return;
        print(tree[p].ch_l);
        cout << p << ", " << tree[p].point << ", ";
        print(tree[p].ch_r);
        if(p==0) cout << endl;
    }
public:
    //(x,y)のvector
    KdTree(const vector<pair<T,T>>& arg_points) {
        vector<Point> points(arg_points.size());
        for(int i=0;i<arg_points.size();++i) points[i] = {arg_points[i].first,arg_points[i].second,i};
        dfs(0,0,points.size(),points);
    }
    void print() {
        print(0);
    }
    //x区間[x1,x2],y区間[y1,y2]に囲まれる領域内の数 x1<=x2 && y1 <= y2
    vector<Point> points_in_range(const T& x1,const T& x2,const T& y1,const T& y2) {
        vector<Point> ret;
        stack<int> st; st.push(0);
        while(st.size()) {
            int p=st.top(); st.pop();
            if(x1<=tree[p].point.x&&tree[p].point.x<=x2&&y1<=tree[p].point.y&&tree[p].point.y<=y2) {
                ret.emplace_back(tree[p].point);
            }
            if(tree[p].depth&1) {//y
                if(tree[p].ch_r!=-1 && tree[p].point.y <= y2) st.push(tree[p].ch_r);
                if(tree[p].ch_l!=-1 && y1 <= tree[p].point.y) st.push(tree[p].ch_l);
            }
            else {               //x
                if(tree[p].ch_r!=-1 && tree[p].point.x <= x2) st.push(tree[p].ch_r);
                if(tree[p].ch_l!=-1 && x1 <= tree[p].point.x) st.push(tree[p].ch_l);
            }
        }
        sort(ret.begin(),ret.end(),[&](Point l,Point r){return l.idx < r.idx;});
        return ret;
    }
};
