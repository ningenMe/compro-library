/*
 * @title DualSegmentTree - 非再帰抽象化双対セグメント木
 * @docs md/segment-tree/DualSegmentTree.md
 */
template<class Monoid> class DualSegmentTree {
    using TypeNode = typename Monoid::TypeNode;
    using TypeLazy = typename Monoid::TypeLazy;
    size_t length;
    size_t height;
    vector<TypeNode> node;
    vector<TypeLazy> lazy;

    void propagate(int k) {
        if(lazy[k] == Monoid::unit_lazy) return;
        if(k >=length) node[k-length] = Monoid::func_operate(node[k-length],lazy[k],k-length,k-length+1);
        if(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);
        if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);
        lazy[k] = Monoid::unit_lazy;
    }
    void build(const size_t num) {
        for (length = 1,height = 0; length <= num; length *= 2, height++);
        node.resize(1 * length, Monoid::unit_node);
        lazy.resize(2 * length, Monoid::unit_lazy);
    }

public:

    //unitで初期化
    DualSegmentTree(const size_t num) {
        build(num);
    }
    // //同じinitで初期化
    DualSegmentTree(const size_t num, const TypeNode init) {
        build(num);
        for (int i = 0; i < num; ++i) node[i] = init;
    }
    //vectorで初期化
    DualSegmentTree(const vector<TypeNode>& vec) {
        build(vec.size());
        for (int i = 0; i < vec.size(); ++i) node[i] = vec[i];
    }

    //operate [a,b)
    void operate(int a, int b, TypeLazy x) {
        int l = a + length, r = b + length - 1;
        for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
        for(r++; l < r; l >>=1, r >>=1) {
            if(l&1) lazy[l] = Monoid::func_lazy(lazy[l],x), propagate(l),l++;
            if(r&1) --r,lazy[r] = Monoid::func_lazy(lazy[r],x), propagate(r);
        }
    }

    //fold [a,a+1)
    TypeNode fold(int a) {
        int l = a + length;
        for (int i = height; 0 <= i; --i) propagate(l >> i);
        return node[a];
    }

    void print(){
        cout << "lazy" << endl;
        for(int i = 1,j = 1; i < 2*length; ++i) {
        	cout << lazy[i] << " ";
        	if(i==((1<<j)-1) && ++j) cout << endl;
        }
        cout << "vector" << endl;
        cout << "{ " << fold(0);
        for(int i = 1; i < length; ++i) cout << ", " << fold(i);
        cout << " }" << endl;
    }
};