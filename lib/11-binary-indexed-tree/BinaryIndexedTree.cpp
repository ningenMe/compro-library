/*
 * @title BinaryIndexedTree - BIT
 * @docs md/binary-indexed-tree/BinaryIndexedTree.md
 */
template<class Abel> class BinaryIndexedTree {
    using TypeNode = typename Abel::TypeNode;
    size_t length;
    size_t num;
    vector<TypeNode> node;
public:

    //[0,N) constructed, inplace [0,1) + [1,N+1)
    //you can ignore inplace offset
    BinaryIndexedTree(const size_t num) : num(num) {
        for (length = 1; length < num; length *= 2);
        node.resize(length+1, Abel::unit_node);
    }

    //[idx,idx+1) operate
    void operate(size_t idx, TypeNode var) {
        assert(0 <= idx && idx < length);
        for (++idx; idx <= length; idx += idx & -idx) node[idx] = Abel::func_fold(node[idx],var);
    }

    //[0,idx) fold
    TypeNode fold(size_t idx) {
        TypeNode ret = Abel::unit_node;
        for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);
        return ret;
    }

    //return [0,length]
    int binary_search(TypeNode var) {
        if(!Abel::func_check(node.back(),var)) return num;
        TypeNode ret = Abel::unit_node;
        size_t off = 0;
        for(size_t idx = length; idx; idx >>= 1){
            if(off + idx <= length && !Abel::func_check(Abel::func_fold(ret,node[off+idx]),var)) {
                off += idx;
                ret = Abel::func_fold(ret,node[off]);
            }
        }
        return min(off,num);
    }

    void print() {
        cout << "{ " << fold(1);
        for(int i = 1; i < length; ++i) cout << ", " << fold(i+1);
        cout << " }" << endl;
    }
};
