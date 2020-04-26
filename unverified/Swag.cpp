template<class Operator> class Swag{
public:
	using TypeNode = typename Operator::TypeNode;
	stack<pair<TypeNode,TypeNode>> pre,suf;

	Swag() {
		// do nothing
	}
	TypeNode fold() {
		TypeNode res = Operator::unit_node;
		if(pre.size()) res = Operator::funcNode(res,pre.top().second);
		if(suf.size()) res = Operator::funcNode(res,suf.top().second);
		return res;
	}
	void push(TypeNode val) {
		TypeNode acc = val;
		if(suf.size()) acc = Operator::funcNode(acc,suf.top().second);
		suf.emplace(val,acc);
	}
	void pop() {
		if(pre.empty()) {
			TypeNode acc = Operator::unit_node;
			while(suf.size()) {
				auto [val,_] = suf.top();
				suf.pop();
				acc = Operator::funcNode(acc,val);
				pre.emplace(val,acc);
			}
		}
		if(pre.size()) pre.pop();			
	}
	size_t size(){
		return pre.size()+suf.size();
	}
};

template<class T> struct nodeGCD {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode funcNode(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}
};