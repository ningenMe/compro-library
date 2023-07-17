/*
 * @title PrimalDualMinCostFlow - 最短路反復の最小費用流
 * @docs md/graph/PrimalDualMinCostFlow.md
 */
template<class TypeFlow, class TypeCost> class PrimalDualMinCostFlow {
    using Pair = pair<TypeCost,size_t>;
    struct Edge {
        size_t to;
        size_t rev;
        TypeFlow cap;
        TypeCost cost; 
    };
    vector<vector<Edge>> edge;
    const size_t N;
    const TypeCost inf_cost;
    vector<TypeCost> min_cost;
    vector<TypeCost> potential;
    vector<size_t> prev_vertex,prev_edge;
    TypeFlow max_flow=0;
public:
    PrimalDualMinCostFlow(const size_t N, const TypeCost inf_cost) 
        : N(N), edge(N), min_cost(N), potential(N,0), prev_vertex(N,N), prev_edge(N,N), inf_cost(inf_cost) {}
    // costは単位流量あたりのコスト
    inline void make_edge(const size_t from, const size_t to, const TypeFlow cap, const TypeCost cost) {
        assert(cost < inf_cost);
        edge[from].push_back({ to, edge[to].size(), cap, cost });
        edge[to].push_back({ from, edge[from].size() - 1, 0, -cost });
        max_flow += cap;
    }
    pair<TypeFlow,TypeCost> min_cost_flow(const size_t s, const size_t g) {
        return min_cost_flow(s,g,max_flow);
    }
    pair<TypeFlow,TypeCost> min_cost_flow(const size_t s, const size_t g, const TypeFlow limit_flow) {
        assert(0 <= s && s < N && 0 <= g && g < N && s != g);
        priority_queue<Pair,vector<Pair>,greater<Pair>> pq;

        TypeCost sum_cost=0;
        TypeFlow sum_flow=0;
        while(sum_flow < limit_flow) {
            min_cost.assign(N, inf_cost);
            {
                pq.emplace(0,s);
                min_cost[s]=0;
            }
            while(pq.size()) {
                auto [from_cost, from] = pq.top(); pq.pop();
                if(min_cost[from] < from_cost) continue;

                for(int i=0; i < edge[from].size(); ++i) {
                    auto [to, rev, cap, cost] = edge[from][i];
                    TypeCost to_cost = from_cost + cost + (potential[from] - potential[to]);
                    if(cap > 0 && min_cost[to] > to_cost) {
                        pq.emplace(to_cost, to);
                        prev_vertex[to] = from;
                        prev_edge[to] = i;
                        min_cost[to] = to_cost;
                    }
                }
            }
            if(min_cost[g]==inf_cost) break;
            for(size_t i=0; i<N; ++i) potential[i] += min_cost[i];

            TypeFlow diff_flow = limit_flow - sum_flow;
            for(size_t i=g; i!=s; i = prev_vertex[i]) {
                diff_flow = min(diff_flow, edge[prev_vertex[i]][prev_edge[i]].cap);
            }
            sum_flow += diff_flow;
            sum_cost += diff_flow * potential[g];
            for(size_t i=g; i!=s; i = prev_vertex[i]) {
                auto& [_to,rev,cap,_cost] = edge[prev_vertex[i]][prev_edge[i]];
                auto& [_r_to,_r_rev,r_cap,_r_cost] = edge[i][rev];

                cap -= diff_flow;
                r_cap += diff_flow;
            }
        }
        return {sum_flow, sum_cost};
    }

};