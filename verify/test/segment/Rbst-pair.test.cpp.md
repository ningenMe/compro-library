---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/segment/Rbst-pair.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#071f76f489cfd361eed2a12635965092">test/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment/Rbst-pair.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 13:46:40+09:00


* see: <a href="https://yukicoder.me/problems/no/822">https://yukicoder.me/problems/no/822</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/segment/Rbst.cpp.html">Rbst</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/822"

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
#include "../../lib/segment/Rbst.cpp"

template<class T> struct NodePair {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = {0,0};
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return {0,0};}
};

int main() {
    int N,K; cin >> N >> K;
    if(N+1 <= K){
		cout << "INF" << endl;
		return 0;
	}
    Rbst<NodePair<pair<int,int>>> st;
    for(int i = 0; i < (1<<20); ++i) {
        if((i&N) != N) continue;
        for(int j = -K; j <= K; ++j) {
            int a = i, b = i + j;
            if(a>b) swap(a,b);
            if(0<=b && b-a<=K && ((a&b)==N) && !st.count({a,b})) st.insert({a,b});
        }
    }
    cout << st.size() << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment/Rbst-pair.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/822"

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
#line 1 "lib/segment/Rbst.cpp"
/*
 * @title Rbst
 */
template<class Operator> class Rbst {
	using TypeNode = typename Operator::TypeNode;
	unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned int xor_shift() {
		unsigned int t = (x ^ (x << 11)); x = y; y = z; z = w;
		return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
	}
	struct Node {
		Node *left, *right;
		TypeNode val;
		int size;
		TypeNode sum;

		Node() : val(Operator::unit_node), size(1), sum(Operator::unit_node) {
			left = right = nullptr;
		}
		Node(TypeNode v) : val(v), size(1), sum(v) {
			left = right = nullptr;
		}
	};
	Node* root;
	inline int size(Node *node) {
		return node==nullptr ? 0 : node->size;
	}
	inline TypeNode sum(Node *node) {
		return node==nullptr ? Operator::unit_node : node->sum;
	}
	inline Node* update(Node *node) {
		node->size = size(node->left) + size(node->right) + 1;
		node->sum = Operator::func_node(sum(node->left),sum(node->right),node->val);
		return node;
	}
	inline TypeNode get(Node *node, int k) {
		if (node==nullptr) return -1;
		if (k == size(node->left)) return node->val;
		if (k < size(node->left)) return get(node->left, k);
		else return get(node->right, k-1 - size(node->left));
	}
	inline int lower_bound(Node *node, TypeNode val) {
		if (node==nullptr) return 0;
		if (val <= node->val) return lower_bound(node->left, val);
		else return size(node->left) + lower_bound(node->right, val) + 1;
	}
	inline int upper_bound(Node *node, TypeNode val) {
		if (node==nullptr) return 0;
		if (val >= node->val) return size(node->left) + upper_bound(node->right, val) + 1;
		else return upper_bound(node->left, val);
	}
	Node* merge(Node *left, Node *right) {
		if (left==nullptr)  return right;
		if (right==nullptr) return left;
		if (xor_shift() % (left->size + right->size) < left->size) {
			left->right = merge(left->right, right);
			return update(left);
		}
		else {
			right->left = merge(left, right->left);
			return update(right);
		}
	}
	pair<Node*, Node*> split(Node* node, int k) {
		if (node==nullptr) return make_pair(node, node);
		if (k <= size(node->left)) {
			pair<Node*, Node*> sub = split(node->left, k);
			node->left = sub.second;
			return make_pair(sub.first, update(node));
		}
		else {
			pair<Node*, Node*> sub = split(node->right, k-1 - size(node->left));
			node->right = sub.first;
			return make_pair(update(node), sub.second);
		}
	}
	Rbst(Node* node):root(node){}
public:
	Rbst() : root(nullptr) {}
	inline int size() {
		return size(this->root);
	}
	inline TypeNode sum() {
		return sum(this->root);
	}
	inline int lower_bound(TypeNode val) {
		return lower_bound(this->root, val);
	}

	inline int upper_bound(TypeNode val) {
		return upper_bound(this->root, val);
	}
	inline int count(TypeNode val) {
		return upper_bound(val) - lower_bound(val);
	}
	inline TypeNode get(int k) {
		return get(this->root, k);
	}
	inline TypeNode get_median() {
		//奇数の時N/2
		return get(this->root, (size()-1)/2);
	}
	void merge(Rbst another) {
		root = merge(this->root, another.root);
	}
	void insert(const TypeNode val) {
		pair<Node*, Node*> sub = split(this->root, this->lower_bound(val));
		this->root = this->merge(this->merge(sub.first, new Node(val)), sub.second);
	}
	void erase(const TypeNode val) {
		if (!this->count(val)) return;
		pair<Node*, Node*> sub = this->split(this->root, this->lower_bound(val));
		this->root = this->merge(sub.first, this->split(sub.second, 1).second);
	}
};
//https://atcoder.jp/contests/abc154/tasks/abc154_c
//https://atcoder.jp/contests/arc033/tasks/arc033_3
//https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_c
//https://yukicoder.me/problems/no/919
//https://yukicoder.me/problems/no/649

template<class T> struct NodeSum {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return l+c+r;}
};

template<class T> struct NodeSimple {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return 0;}
};
#line 11 "test/segment/Rbst-pair.test.cpp"

template<class T> struct NodePair {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = {0,0};
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return {0,0};}
};

int main() {
    int N,K; cin >> N >> K;
    if(N+1 <= K){
		cout << "INF" << endl;
		return 0;
	}
    Rbst<NodePair<pair<int,int>>> st;
    for(int i = 0; i < (1<<20); ++i) {
        if((i&N) != N) continue;
        for(int j = -K; j <= K; ++j) {
            int a = i, b = i + j;
            if(a>b) swap(a,b);
            if(0<=b && b-a<=K && ((a&b)==N) && !st.count({a,b})) st.insert({a,b});
        }
    }
    cout << st.size() << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

