/*
 * @title RectangleWeight - 重みつき矩形
 * @docs md/geometory/RectangleWeight.md
 */
template<class T> class RectangleWeight{
    int H,W;
    vector<tuple<int,int,int,int,T>> query;
    vector<T> grid;
public:
    RectangleWeight(int H,int W):H(H),W(W),grid(H*W){
    }
    //[y1,y2)*[x1,x2)の矩形、均質重みw
    void make_query(int y1,int x1,int y2,int x2,T w=1) {
        query.emplace_back(y1,x1,y2,x2,w);
    }
    void solve() {
        for(const auto& q:query) {
            int y1 = std::get<0>(q);
            int x1 = std::get<1>(q);
            int y2 = std::get<2>(q);
            int x2 = std::get<3>(q);
            T   w  = std::get<4>(q);
            grid[y1*W+x1] += w;
            grid[y1*W+x2] -= w;
            grid[y2*W+x1] -= w;
            grid[y2*W+x2] += w;
        }
        for(int y=0;y<H;++y) {
            for(int x=0;x+1<W;++x) {
                grid[y*W+x+1] += grid[y*W+x];
            }
        }
        for(int x=0;x<W;++x) {
            for(int y=0;y+1<H;++y) {
                grid[(y+1)*W+x] += grid[y*W+x];
            }
        }
    }
    T get(int y,int x) {
        return grid[y*W+x];
    }
};
