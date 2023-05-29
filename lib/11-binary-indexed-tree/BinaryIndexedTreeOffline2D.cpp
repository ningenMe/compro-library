/*
 * @title BinaryIndexedTreeOffline2D - オフライン2次元BIT
 * @docs md/binary-indexed-tree/BinaryIndexedTreeOffline2D.md
 */
template<class Abel> class BinaryIndexedTreeOffline2D {
    using TypeNode = typename Abel::TypeNode;
    using i64 = long long;

    class InternalBinaryIndexedTree {
        size_t length;
        vector<TypeNode> node;
    public:
        InternalBinaryIndexedTree() {}
        InternalBinaryIndexedTree(const size_t num) {
            for (length = 1; length < num; length *= 2);
            node.resize(length+1, Abel::unit_node);
        }
        void operate(size_t idx, TypeNode var) {
            for (++idx; idx <= length; idx += idx & -idx) node[idx] = Abel::func_fold(node[idx],var);
        }
        TypeNode fold(size_t idx) {
            TypeNode ret = Abel::unit_node;
            for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);
            return ret;
        }
    };
    size_t length;
    vector<InternalBinaryIndexedTree> node;
    vector<i64> ox;
    vector<vector<i64>> oy;

public:

    BinaryIndexedTreeOffline2D(const vector<i64>& operator_x,const vector<i64>& operator_y):ox(operator_x) {
        sort(ox.begin(),ox.end());
        ox.erase(unique(ox.begin(),ox.end()),ox.end());
        size_t num = ox.size();
        for (length = 1; length < num; length *= 2);
        node.resize(length+1);
        oy.resize(length+1);
        int n = operator_x.size();
        for(int i=0;i<n;++i) {
            size_t x = (lower_bound(ox.begin(),ox.end(),operator_x[i])-ox.begin());
            for (++x;x<=length; x += x & -x) {
                oy[x].push_back(operator_y[i]);
            }
        }
        for(int i=0;i<length+1;++i) {
            sort(oy[i].begin(),oy[i].end());
            oy[i].erase(unique(oy[i].begin(),oy[i].end()),oy[i].end());
            node[i]=InternalBinaryIndexedTree(oy[i].size());
        }
    }

    //[l,l+1),[d,d+1) operate
    void operate(i64 l, i64 d, TypeNode var) {
        size_t x = (lower_bound(ox.begin(),ox.end(),l)-ox.begin());
        for (++x; x <= length; x += x & -x) {
            size_t y = (lower_bound(oy[x].begin(),oy[x].end(),d)-oy[x].begin());
            node[x].operate(y,var);
        }
    }

    //[0,r),[0,u) fold
    TypeNode fold(i64 l, i64 u) {
        TypeNode ret = Abel::unit_node;
        size_t x = (lower_bound(ox.begin(),ox.end(),l)-ox.begin());
        for (x = min(length,x); x > 0; x -= x & -x) {
            size_t y = (lower_bound(oy[x].begin(),oy[x].end(),u)-oy[x].begin());
            ret = Abel::func_fold(ret,node[x].fold(y));
        }
        return ret;
    }

    // [l,r),[d,u) fold
    TypeNode fold(i64 l, i64 r, i64 d, i64 u) {
        return Abel::func_fold_inv(Abel::func_fold(fold(r,u),fold(l,d)),Abel::func_fold(fold(r,d),fold(l,u)));
    }
};