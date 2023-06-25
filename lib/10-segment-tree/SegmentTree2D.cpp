/*
 * @title SegmentTree2D - 非再帰抽象化セグメント木2D
 * @docs md/segment-tree/SegmentTree2D.md
 */
template<class Monoid> class SegmentTree2D {
    using TypeNode = typename Monoid::TypeNode;
    class SegmentTree {
        size_t length;
        vector<TypeNode> node;
    public:
        //unitで初期化
        SegmentTree(const size_t num) {
            for (length = 1; length <= num; length *= 2);
            node.resize(2 * length, Monoid::unit_node);
            for (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);
        }
        //[idx,idx+1)
        void operate(size_t idx, const TypeNode var) {
            if(idx < 0 || length <= idx) return;
            idx += length;
            node[idx] = Monoid::func_operate(node[idx],var);
            while(idx >>= 1) node[idx] = Monoid::func_fold(node[(idx<<1)+0],node[(idx<<1)+1]);
        }
        //[l,r)
        TypeNode fold(int l, int r) {
            if (l < 0 || length <= l || r < 0 || length < r) return Monoid::unit_node;
            TypeNode vl = Monoid::unit_node, vr = Monoid::unit_node;
            for(l += length, r += length; l < r; l >>=1, r >>=1) {
                if(l&1) vl = Monoid::func_fold(vl,node[l++]);
                if(r&1) vr = Monoid::func_fold(node[--r],vr);
            }
            return Monoid::func_fold(vl,vr);
        }
        void print() {
            cout << "{";
            for(int i=0; i < length; ++i) cout << fold(i,i+1) << " }"[i+1==length];
            cout << endl;
        }
    };
    size_t height,width;
    vector<SegmentTree> node;
public:
    SegmentTree2D(const size_t h, const size_t w):width(w) {
        for (height = 1; height <= h; height *= 2);
        SegmentTree seg(width);
        node.resize(2 * height, seg);
        for (int i = height - 1; i >= 0; --i) {
            for(int j=0; j < width; ++j) {
                node[i].operate(j, Monoid::func_fold(node[(i<<1)+0].fold(j,j+1),node[(i<<1)+1].fold(j,j+1)));
            }
        }
    }
    //[u,u+1)*[l,l+1) に operate
    void operate(size_t u, size_t l, const TypeNode var) {
        if(u < 0 || height <= u || l < 0 || width <= l) return;
        u += height;
        node[u].operate(l, var);
        while(u >>= 1) node[u].operate(l, Monoid::func_fold(node[(u<<1)+0].fold(l,l+1),node[(u<<1)+1].fold(l,l+1)));
    }
    //[u,d),[l,r)
    TypeNode fold(int u, int d, int l, int r) {
        if(u < 0 || height <= u || d < 0 || height < d || l < 0 || width <= l || r < 0 || width < r) return Monoid::unit_node;
        TypeNode vu = Monoid::unit_node, vd = Monoid::unit_node;
        for(u += height, d += height; u < d; u >>=1, d >>=1) {
            if(u&1) vu = Monoid::func_fold(vu,node[u++].fold(l,r));
            if(d&1) vd = Monoid::func_fold(node[--d].fold(l,r),vd);
        }
        return Monoid::func_fold(vu,vd);
    }
    void print() {
        for(int i=height; i < 2*height; ++i) {
            node[i].print();
        }
    }
};