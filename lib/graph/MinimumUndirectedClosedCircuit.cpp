/*
 * @title MinimumUndirectedClosedCircuit - 無向グラフの最小閉路検出
 * @docs md/graph/MinimumUndirectedClosedCircuit.md
 */
template<class T> class MinimumUndirectedClosedCircuit {
    //Tは整数型のみ
    static_assert(std::is_integral<T>::value, "template parameter T must be integral type");
    Graph<T> graph;
    vector<T> dist;
    vector<int> parent,label;
    size_t N;
    bool is_same_weighted;
    T inf;
    int last_l,last_r,root;
private:
    void solve_same_weighted() {
        queue<int> q;
        q.push(root);
        dist[root] = 0;
        while (q.size()) {
            size_t curr = q.front(); q.pop();;
            for(auto& edge:graph.edges[curr]){
                size_t next = edge.first;
                T w  = edge.second;
                if(parent[curr] == next) continue;
                if(dist[next] > dist[curr] + w) {
                    dist[next]   = dist[curr] + w;
                    parent[next] = curr;
                    label[next] = (curr==root?next:label[curr]);
                    q.push(next);
                }
            }
        }
    }
    void solve_diff_weighted() {
        RadixHeap<int> q(0);
        q.push({0,root});
        dist[root] = 0;
        while (q.size()) {
            auto top =  q.pop();
            size_t curr = top.second;
            if(top.first > dist[curr]) continue;
            for(auto& edge:graph.edges[curr]){
                size_t next = edge.first;
                T w  = edge.second;
                if(parent[curr] == next) continue;
                if(dist[next] > dist[curr] + w) {
                    dist[next]   = dist[curr] + w;
                    parent[next] = curr;
                    label[next] = (curr==root?next:label[curr]);
                    q.push({dist[next],next});
                }
            }
        }
    }
    T solve_cycle() {
        T mini = inf;
        last_l=-1,last_r=-1;
        for(int l=0;l<N;++l) {
            if(l==root) continue;
            for(auto& edge:graph.edges[l]){
                int r = edge.first;
                T   w = edge.second;
                if(mini <= dist[l] + dist[r] + w) continue;
                if( (r==root && l!=label[l]) || (r!=root && label[l]!=label[r]) ) {
                    mini = dist[l] + dist[r] + w;
                    last_l = l;
                    last_r = r;
                }            
            }
        }
        return mini;
    }
public:
    MinimumUndirectedClosedCircuit(Graph<T>& graph, T inf)
     : graph(graph),N(graph.size()),dist(graph.size()),parent(graph.size()),label(graph.size()),inf(inf) {
        assert(!graph.edges.empty());
        //重みが一律かどうか判定 面倒だからここはlogつき
        set<T> st;
        for(int i=0;i<N;++i) for(auto& edge:graph.edges[i]) st.insert(edge.second);        
        is_same_weighted = (st.size() == 1);
    }
    //rootを含む最小閉路の集合を返す O(NlogN) 閉路がないときは空集合
    inline T solve(size_t rt){
        root = rt;
        //初期化
        for(int i = 0; i < N; ++i) dist[i] = inf, parent[i] = -1;
        if(is_same_weighted) solve_same_weighted(); //重み一律
        else solve_diff_weighted(); //重みがバラバラ
        T mini=solve_cycle();
        return mini;
    }
    //復元
    vector<int> restore() {
        stack<int> s;
        queue<int> q;
        vector<int> res;
        if(last_l != -1 && last_r != -1){
            for(int curr = last_l; curr != -1; curr = parent[curr]) s.push(curr);
            for(int curr = last_r; curr != root; curr = parent[curr]) q.push(curr);
            while(s.size()) res.push_back(s.top())  ,s.pop();
            while(q.size()) res.push_back(q.front()),q.pop();
        }
        return res;
    }
};