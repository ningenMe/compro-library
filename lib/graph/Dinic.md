## Dinic

#### api
##### Dinic(int N, T ini, T inf)
- コンストラクタ 
##### inline void make_edge(int from, int to, T cap)
- from から to に容量 cap の辺を張る
##### inline T maxflow(int start, int goal)
- start から goal への最大流