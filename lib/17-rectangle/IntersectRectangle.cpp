/*
 * @title IntersectRectangle - 長方形の交差のカウント
 * @docs md/rectangle/IntersectRectangle.md
 */
template<class T> class IntersectRectangle {
    class BinaryIndexedTree {
        size_t length; vector<T> node;
    public:
        BinaryIndexedTree(const size_t num) { for (length = 1; length < num; length *= 2); node.resize(length+1, 0);}
        void operate(size_t idx, T val) { for (++idx; idx <= length; idx += idx & -idx) node[idx] += val; }
        T fold(size_t idx) { T res = 0; for (idx = min(length,idx); idx > 0; idx -= idx & -idx) res += node[idx]; return res;}
        void clear() {for(size_t i = 0; i <= length; ++i) node[i] = 0;}
    };
    size_t N;
    vector<int> count;
    void build(vector<T> vl, vector<T> vr, vector<T> vd, vector<T> vu) {
        N = vl.size();
        assert(vr.size() == N);
        assert(vd.size() == N);
        assert(vu.size() == N);
        for(size_t i = 0; i < N; ++i) {
            assert(vl[i] < vr[i] && vd[i] < vu[i]);
        }
        //x,yそれぞれで座圧
        vector<T> sorted_x(2*N),sorted_y(2*N);
        for(size_t i=0;i<N;++i) {
            sorted_x[2*i+0]=vl[i];
            sorted_x[2*i+1]=vr[i];
            sorted_y[2*i+0]=vd[i];
            sorted_y[2*i+1]=vu[i];
        }
        sort(sorted_x.begin(), sorted_x.end());
        sort(sorted_y.begin(), sorted_y.end());
        vector<size_t> zl(N),zr(N),zd(N),zu(N);
        for(size_t i=0;i<N;++i) {
            zl[i] = lower_bound(sorted_x.begin(), sorted_x.end(), vl[i]) - sorted_x.begin();
            zr[i] = lower_bound(sorted_x.begin(), sorted_x.end(), vr[i]) - sorted_x.begin();
            zd[i] = lower_bound(sorted_y.begin(), sorted_y.end(), vd[i]) - sorted_y.begin();
            zu[i] = lower_bound(sorted_y.begin(), sorted_y.end(), vu[i]) - sorted_y.begin();
        }
        //   |  | 
        // --|--|--
        //   | s| 
        // --|--|--
        //   |  |
        // 領域sに対して、sと共有領域を持たないものを包除原理で数える {左|右|上|下} - {左上|左下|右上|右下}
        count.resize(N,0);
        BinaryIndexedTree bit(2*N);
        {
            for(size_t i=0;i<N;++i) bit.operate(zr[i]-1,1);
            for(size_t i=0;i<N;++i) count[i] += bit.fold(zl[i]);
            bit.clear();
            for(size_t i=0;i<N;++i) bit.operate(zl[i],1);
            for(size_t i=0;i<N;++i) count[i] += N-bit.fold(zr[i]);
            bit.clear();
            for(size_t i=0;i<N;++i) bit.operate(zu[i]-1,1);
            for(size_t i=0;i<N;++i) count[i] += bit.fold(zd[i]);
            bit.clear();
            for(size_t i=0;i<N;++i) bit.operate(zd[i],1);
            for(size_t i=0;i<N;++i) count[i] += N-bit.fold(zu[i]);
            bit.clear();
        }
        vector<tuple<size_t,int,size_t>> sorted_zx;
        BinaryIndexedTree bit_u(2*N),bit_d(2*N);
        {
            for(size_t i=0;i<N;++i) sorted_zx.emplace_back(zl[i],1,i), sorted_zx.emplace_back(zr[i],0,i);
            sort(sorted_zx.begin(), sorted_zx.end());
        }
        {
            for(size_t j=0;j<2*N;++j) {
                auto [_,lr,i] = sorted_zx[j];
                if(lr == 1) {
                    count[i] -= bit_u.fold(zd[i]);
                    count[i] -= bit_d.fold(2*N)-bit_d.fold(zu[i]);
                }
                if(lr == 0) {
                    bit_d.operate(zd[i],1);
                    bit_u.operate(zu[i]-1,1);
                }
            }
            bit_d.clear();
            bit_u.clear();
            for(size_t j=2*N-1;;--j) {
                auto [_,lr,i] = sorted_zx[j];
                if(lr == 1) {
                    bit_d.operate(zd[i],1);
                    bit_u.operate(zu[i]-1,1);
                }
                if(lr == 0) {
                    count[i] -= bit_u.fold(zd[i]);
                    count[i] -= bit_d.fold(2*N)-bit_d.fold(zu[i]);
                }
                if(j==0) break;
            }
        }
    }
public:
    //[l,r) x [d,u) の長方形の集合
    IntersectRectangle(const vector<array<T,4>>& l_r_d_u){
        size_t N = l_r_d_u.size();
        vector<T> vl(N),vr(N),vd(N),vu(N);
        for(size_t i = 0; i < N; ++i) {
            auto [a,b,c,d]=l_r_d_u[i];
            vl[i]=a,vr[i]=b,vd[i]=c,vu[i]=d;
        }
        build(vl,vr,vd,vu);
    }
    IntersectRectangle(const vector<T>& vl, const vector<T>& vr, const vector<T>& vd, const vector<T>& vu) {
        build(vl,vr,vd,vu);
    }
    size_t size() { return N; }
    int get(const size_t i) { return N-1-count[i]; }
};