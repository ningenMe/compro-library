/*
 * @title Graph
 * @docs md/graph/Graph.md
 */
template<class T> class Graph{
private:
    const size_t N;
public:
    vector<vector<pair<size_t,T>>> edges;
    Graph(const size_t N):N(N), edges(N) {}
    void make_edge(size_t from, size_t to, T w) {
        edges[from].emplace_back(to,w);
    }
    size_t size(){return N;}
};