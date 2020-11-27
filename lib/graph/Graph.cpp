/*
 * @title Graph
 * @docs md/graph/Graph.md
 */
template<class T> class Graph{
private:
    const size_t N,H,W;
public:
    vector<vector<pair<size_t,T>>> edges;
    Graph(const size_t N):N(N), edges(N) {}
    Graph(const size_t H, const size_t W):H(H),W(W),N(H*W), edges(H*W) {}
    inline void make_edge(size_t from, size_t to, T w) {
        edges[from].emplace_back(to,w);
    }
    //{from_y,from_x} -> {to_y,to_x} 
    inline void make_edge(pair<size_t,size_t> from, pair<size_t,size_t> to, T w) {
        make_edge(from.first*W+from.second,to.first*W+to.second,w);
    }
    inline void make_bidirectional_edge(size_t from, size_t to, T w) {
        make_edge(from,to,w);
        make_edge(to,from,w);
    }
    inline void make_bidirectional_edge(pair<size_t,size_t> from, pair<size_t,size_t> to, T w) {
        make_edge(from.first*W+from.second,to.first*W+to.second,w);
        make_edge(to.first*W+to.second,from.first*W+from.second,w);
    }
    inline size_t size(){return N;}
    inline size_t idx(pair<size_t,size_t> yx){return yx.first*W+yx.second;}
};
