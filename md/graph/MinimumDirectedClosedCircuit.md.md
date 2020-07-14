##### overview
重みなし有向グラフの最小閉路クラス
##### api
- MinimumDirectedClosedCircuit(int N)  
    - コンストラクタ  
- inline void make_edge(int from, int to)  
    - from から to に辺を張る  
- inline vector<int> solve(int root)  
    - rootを含む最小閉路の頂点集合。閉路がないときは空集合を返す。  