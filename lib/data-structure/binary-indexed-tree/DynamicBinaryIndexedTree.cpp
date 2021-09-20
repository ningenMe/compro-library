/*
 * @title DynamicBinaryIndexedTree - 動的BIT
 * @docs md/segment/DynamicBinaryIndexedTree.md
 */
template<class Abel> class DynamicBinaryIndexedTree {
    using TypeNode = typename Abel::TypeNode;
    using i64 = long long;
    i64 length;

    unordered_map<i64,TypeNode> node;
public:

    //[0,N) constructed, inplace [0,1) + [1,N+1)
    //you can ignore inplace offset
    DynamicBinaryIndexedTree(const i64 num) {
        for (length = 1; length < num; length *= 2);
    }

    //[idx,idx+1) operate
    void operate(i64 idx, TypeNode var) {
        assert(0 <= idx && idx < length);
        for (++idx; idx <= length; idx += idx & -idx) node[idx] = Abel::func_fold(node[idx],var);
    }

    //[0,idx) fold
    TypeNode fold(i64 idx) {
        TypeNode ret = Abel::unit_node;
        for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);
        return ret;
    }

    //[l,r) fold
    TypeNode fold(i64 l, i64 r) {
        return Abel::func_fold_inv(fold(r),fold(l));
    }

    void print() {
        cout << "{ " << fold(1);
        for(int i = 1; i < length; ++i) cout << ", " << fold(i+1);
        cout << " }" << endl;
    }
};