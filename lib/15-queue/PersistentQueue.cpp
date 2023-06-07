/*
 * @title PersistentQueue - 永続queue
 * @docs md/data-structure/PersistentQueue.md
 */
template<class T,size_t bit=20> class PersistentQueue{
private:
    struct Node{
        array<size_t,bit> parent;
        T val;
        size_t length;
        Node(T val,size_t length):val(val),length(length){}
    };
    vector<Node> tree;
    unordered_map<int,size_t> mp;
public:
    PersistentQueue(T inf) {
        Node root(inf,0);
        for(size_t i=0;i<bit;++i) root.parent[i]=0;
        mp[-1]=0;
        tree.push_back(root);
    }
    void push(int target_id, int pushed_id, T val) {
        size_t idx = mp[target_id];
        size_t length = tree[idx].length + 1;
        Node leaf(val,length);
        leaf.parent[0]=idx;
        for(size_t i=1;i<bit;++i) leaf.parent[i]=tree[leaf.parent[i-1]].parent[i-1];
        mp[pushed_id] = tree.size();
        tree.push_back(leaf);
    }
    T pop(int target_id,int pushed_id) {
        size_t idx = mp[target_id];
        auto node = tree[idx];
        size_t& length = node.length;
        assert(length > 0);
        length-=1;
        mp[pushed_id] = tree.size();
        tree.push_back(node);
        for(int i=bit-1; 0<=i; --i) if((length>>i) & 1) idx = tree[idx].parent[i];
        return tree[idx].val;
    }
};