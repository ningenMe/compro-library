/*
 * @title LazyRandomizedBinarySearchTreeSequence - 遅延評価平衡二分探索木列
 * @docs md/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.md
 */
template<class Monoid> class LazyRandomizedBinarySearchTreeSequence {
	using TypeNode = typename Monoid::TypeNode;
	using TypeLazy = typename Monoid::TypeLazy;
	unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned int xor_shift() {
		unsigned int t = (x ^ (x << 11)); x = y; y = z; z = w;
		return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
	}
	struct Node {
	private:
		void build() {left = right = nullptr;size = 1;lazy = range_lazy = Monoid::unit_lazy;}
	public:
		Node *left, *right;
		TypeNode value, range_value;
		TypeLazy lazy, range_lazy;
		int size;
		Node() : value(Monoid::unit_node), range_value(Monoid::unit_node) {build();}
		Node(TypeNode v) : value(v), range_value(v) {build();}
        friend ostream &operator<<(ostream &os, const Node* node) {return os << "{" << node->value << ", " << node->range_value << ", " << node->range_lazy << ", " << node->size << "}";}
	};
	Node* root;
	inline int size(Node *node) {return node==nullptr ? 0 : node->size;}
    inline TypeNode range_value(Node *node) {return node==nullptr ? Monoid::unit_node : node->range_value;}
	inline TypeNode get(Node *node, size_t k) {
		if (node==nullptr) return Monoid::unit_node;
        propagate(node);
		if (k == size(node->left)) return node->value;
		if (k < size(node->left)) return get(node->left, k);
		else return get(node->right, k-1 - size(node->left));
	}
	inline Node* update(Node *node) {
		node->size = size(node->left) + size(node->right) + 1;
		node->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));
		return node;
	}
	inline void propagate(Node *node) {
		if(node==nullptr || node->range_lazy == Monoid::unit_lazy) return;
		node->range_value = Monoid::func_operate(node->range_value,node->range_lazy,0,node->size);
		node->value = Monoid::func_operate(node->value,node->range_lazy,0,1);
		if(node->left !=nullptr) node->left->range_lazy  = Monoid::func_lazy(node->left->range_lazy,node->range_lazy);
		if(node->right!=nullptr) node->right->range_lazy = Monoid::func_lazy(node->right->range_lazy,node->range_lazy);
		node->range_lazy = Monoid::unit_lazy;
	}
    Node* merge_impl(Node *left, Node *right) {
        propagate(left);
        propagate(right);
		if (left==nullptr)  return right;
		if (right==nullptr) return left;
		if (xor_shift() % (left->size + right->size) < left->size) {
			left->right = merge_impl(left->right, right);
			return update(left);
		}
		else {
			right->left = merge_impl(left, right->left);
			return update(right);
		}
	}
	pair<Node*, Node*> split_impl(Node* node, int k) {
		if (node==nullptr) return make_pair(nullptr, nullptr);
        propagate(node);
		if (k <= size(node->left)) {
			pair<Node*, Node*> sub = split_impl(node->left, k);
			node->left = sub.second;
			return make_pair(sub.first, update(node));
		}
		else {
			pair<Node*, Node*> sub = split_impl(node->right, k - 1 - size(node->left));
			node->right = sub.first;
			return make_pair(update(node), sub.second);
		}
	}
	inline void operate_impl(Node *node, int l, int r, TypeLazy lazy) {
		if(l < 0 || size(node) <= l || r <= 0 || r-l <= 0) return;
		if (l == 0 && r == size(node)) {
			node->range_lazy = Monoid::func_lazy(node->range_lazy,lazy);
			propagate(node);
			return;
		}
		int sl = size(node->left);
		propagate(node->left);
		if(sl > l) operate_impl(node->left,l,min(sl,r),lazy);
		l = max(l-sl,0), r -= sl;
		if(l == 0 && r > 0) node->value = Monoid::func_operate(node->value,lazy,0,1);
		l = max(l-1,0), r -= 1;
		propagate(node->right);
		if(l >= 0 && r > l) operate_impl(node->right,l,r,lazy);
		update(node);
	}
	inline TypeNode fold_impl(Node *node, int l, int r) {
        if (l < 0 || size(node) <= l || r<=0 || r-l <= 0) return Monoid::unit_node;
		propagate(node);
		if (l == 0 && r == size(node)) return range_value(node);
        TypeNode value = Monoid::unit_node;
		int sl = size(node->left);
		if(sl > l) value = Monoid::func_fold(value,fold_impl(node->left,l,min(sl,r)));
		l = max(l-sl,0), r -= sl;
		if(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);
		l = max(l-1,0), r -= 1;
		if(l >= 0 && r > l) value = Monoid::func_fold(value,fold_impl(node->right,l,r));
		return value;
	}
	inline void insert_impl(const size_t k, const TypeNode value) {
		pair<Node*, Node*> sub = split_impl(this->root, k); 
		this->root = this->merge_impl(this->merge_impl(sub.first, new Node(value)), sub.second);
	}
	inline void erase_impl(const size_t k) {
		if(size(this->root) <= k) return;
        auto sub = split_impl(this->root,k);
        this->root = merge_impl(sub.first, split_impl(sub.second, 1).second);
	}
	LazyRandomizedBinarySearchTreeSequence(Node* node):root(node){}
public:
	LazyRandomizedBinarySearchTreeSequence() : root(nullptr) {}
	inline int size() {return size(this->root);}
	inline int empty(void) {return bool(size()==0);}
	inline TypeNode get(size_t k) {return get(this->root, k);}
	inline Node* merge(Node *left, Node *right) {return merge_impl(left,right);}
	inline pair<Node*, Node*> split(int k) {return split_impl(this->root,k);}
	inline void insert(const size_t k, const TypeNode value) {insert_impl(k,value);}
    inline TypeNode fold(int l, int r) {return fold_impl(this->root,l,r);}
	inline void operate(const int l, const int r, const TypeLazy lazy) {propagate(this->root); operate_impl(this->root,l,r,lazy);}
    inline void erase(const size_t k) {erase_impl(k);}
    void print() {
		queue<pair<Node*,int>> q1,q2;
        q1.push({root,0});
        while(q1.size()) {
            while(q1.size()) {
                auto p = q1.front(); q1.pop();
                q2.push(p);
            }
            int flg = 1;
            cout << "{";
            while(q2.size()) {
                auto node = q2.front().first; 
				auto offs = q2.front().second;
				q2.pop();
                if(node==nullptr) {
                    cout << "{},";
                    q1.push({nullptr,-1});
                    q1.push({nullptr,-1});
                }
                else {
					propagate(node);
                    cout << offs + size(node->left) << ":" << node << ",";
                    q1.push({node->left,offs});
                    q1.push({node->right,offs + size(node->left) + 1});
                    flg &= 0;
                }
            }
            cout << "}" << endl;
            if(flg) break;
        }
    }
};
