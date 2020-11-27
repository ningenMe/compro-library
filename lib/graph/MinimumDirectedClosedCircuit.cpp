/*
 * @title MinimumDirectedClosedCircuit - 有向グラフの最小閉路検出
 * @docs md/graph/MinimumDirectedClosedCircuit.md
 */
template<class T> class MinimumDirectedClosedCircuit {
    //Tは整数型のみ
    static_assert(std::is_integral<T>::value, "template parameter T must be integral type");
    Graph<T>& graph;
    vector<int> dist,parent;
    size_t N;
    bool is_same_weighted;
    T inf;
    int last,root;
private:
    T solve_same_weighted() {
        T mini = inf;
        last = -1;
        queue<int> q;
        q.push(root);
        dist[root] = 0;
        while (q.size()) {
            size_t curr = q.front(); q.pop();
            for(auto& edge:graph.edges[curr]){
                size_t next = edge.first;
                T w  = edge.second;
                
                //根に返って来てるなら閉路
                if(next == root && mini > dist[curr]+w) {
                    mini = dist[curr]+w;
                    last = curr;
                }
                //そうじゃないなら探索木を広げる
                else if(dist[next]==-1) {
                    dist[next]   = dist[curr] + w;
                    parent[next] = curr;
                    q.push(next);
                }
            }
        }
        return mini;
    }
    T solve_diff_weighted() {
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
                
                //根に返って来てるなら閉路
                if(next == root && mini > dist[curr]+w) {
                    mini = dist[curr]+w;
                    last = curr;
                }
                //そうじゃないなら探索木を広げる
                else if(dist[next]==-1) {
                    dist[next]   = dist[curr] + w;
                    parent[next] = curr;
                    q.push({dist[next],next});
                }
            }
        }
        return mini;
    }
public:
    MinimumDirectedClosedCircuit(Graph<T>& graph, T inf)
     : graph(graph),N(graph.size()),dist(graph.size()),parent(graph.size()),inf(inf) {
        assert(!graph.edges.empty());
        //重みが一律かどうか判定 面倒だからここはlogつき
        set<T> st;
        for(int i=0;i<N;++i) for(auto& edge:graph.edges[i]) st.insert(edge.second);        
        is_same_weighted = (st.size() == 1);
    }
    //rootを含む最小閉路の集合を返す O(NlogN) 閉路がないときは空集合
    inline T solve(size_t rt, int restore = 0){
        root = rt;
        //初期化
        for(int i = 0; i < N; ++i) dist[i] = parent[i] = -1;
        //最小閉路の大きさを決める
        T mini;
        if(is_same_weighted) mini=solve_same_weighted(); //重み一律
        else mini=solve_diff_weighted(); //重みがバラバラ
        return mini;
    }
    vector<int> restore() {
        vector<int> res;
        if(last == -1) return res;
        res.push_back(last);
        int curr = last;
        while(curr != root) res.push_back(curr = parent[curr]);
        reverse(res.begin(),res.end());
        return res;
    }
};