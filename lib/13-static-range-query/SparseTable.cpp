/*
 * @title SparseTable
 * @docs md/static-range-query/SparseTable.md
 */
template<class Operator> class SparseTable{
public:
    using TypeNode = typename Operator::TypeNode;
    vector<TypeNode> node;
    vector<size_t> idx;
    size_t depth;
    size_t length;

    SparseTable(const vector<TypeNode>& vec) {
        for(depth = 0;(1<<depth)<=vec.size();++depth);
        length = (1<<depth);
        node.resize(depth*length);
        for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];
        for(int i = 1; i < depth; ++i) for(int j = 0; j + (1<<i) < (1<<depth); ++j) node[i*length+j] = Operator::func_fold(node[(i-1)*length+j],node[(i-1)*length+j + (1 << (i-1))]);
        idx.resize(vec.size()+1);
        for(int i = 2; i < vec.size()+1; ++i) idx[i] = idx[i>>1] + 1;
    }

    //[l,r)
    TypeNode fold(const int l,const int r) {
        size_t bit = idx[r-l];
        return Operator::func_fold(node[bit*length+l],node[bit*length+r - (1<<bit)]);
    }
};

template<class T> struct NodeMin {
    using TypeNode = T;
    inline static constexpr TypeNode unitNode = 1LL<<31;
    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return min(l,r);}
};
