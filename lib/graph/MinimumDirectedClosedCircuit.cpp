/*
 * @title MinimumDirectedClosedCircuit - 有向グラフの最小閉路検出
 * @docs md/graph/MinimumDirectedClosedCircuit.md
 */
template<class T> class MinimumDirectedClosedCircuit {
    //Tは整数型のみ
    static_assert(std::is_integral<T>::value, "template parameter T must be integral type");
    Graph<T>& graph;
    vector<T> dist;
    vector<int> parent;
    size_t N;
    T inf;
    int last,root;
private:

    T solve_impl() {
        T mini = inf;
        last = -1;
        RadixHeap<int> q(0);
        q.push({0,root});
        dist[root] = 0;
        while (q.size()) {
            auto top =  q.pop();
            size_t curr = top.second;
            for(auto& edge:graph.edges[curr]){
                size_t next = edge.first;
                T w  = edge.second;                
                if(dist[next] > dist[curr]+w) {
                    dist[next]   = dist[curr] + w;
                    parent[next] = curr;
                    q.push({dist[next],next});
                }
                //根に返って来てるなら閉路候補
                if(next == root && mini > dist[curr]+w) {
                    mini = dist[curr]+w;
                    last = curr;
                }                
            }
        }
        return mini;
    }
public:
    MinimumDirectedClosedCircuit(Graph<T>& graph, T inf)
     : graph(graph),N(graph.size()),dist(graph.size()),parent(graph.size()),inf(inf) {
    }
    //rootを含む最小閉路の集合を返す O(NlogN) 閉路がないときは空集合
    inline T solve(size_t rt){
        root = rt;
        //初期化
        for(int i = 0; i < N; ++i) dist[i] = inf, parent[i] = -1;
        //最小閉路の大きさを決める
        T mini = solve_impl();
        return mini;
    }
    vector<int> restore() {
        vector<int> res;
        if(last == -1) return res;
        int curr = last;
        res.push_back(curr);
        while(curr != root) res.push_back(curr = parent[curr]);
        reverse(res.begin(),res.end());
        return res;
    }
};
