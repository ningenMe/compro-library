/*
 * @title ConvexHullTrickSegmentTree
 */
template<class Operator> class ConvexHullTrickSegmentTree {
	using TypeValue = typename Operator::TypeValue;
	using TypeNode = pair<TypeValue,TypeValue>;
	size_t length;
	size_t num;
	vector<ConvexHullTrick<Operator>> node;
public:
	inline constexpr TypeValue y(const TypeNode p, TypeValue x) {
		return p.first*x+p.second;
	}
	ConvexHullTrickSegmentTree(const size_t num): num(num) {
		for (length = 1; length <= num; length *= 2);
		node.resize(2 * length);
	}
	//[idx,idx+1) insert{ax+b}
	void update(size_t idx, const TypeValue a, const TypeValue b) {
		if(idx < 0 || length <= idx) return;
		for(idx+=length;idx;idx >>= 1) node[idx].insert(a,b);
	}
	//[l,r)
	TypeValue get(int l, int r, TypeValue x) {
		if (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_value;
		TypeValue vl =  Operator::unit_value, vr = Operator::unit_value;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) {
				auto tl=node[l++].get(x);                
				vl = (Operator::func_compare(vl,tl)?vl:tl);
			}
			if(r&1) {
				auto tr=node[--r].get(x);                
				vr = (Operator::func_compare(tr,vr)?tr:vr);
			}
		}
		return (Operator::func_compare(vl,vr)?vl:vr);
	}
	//[l,r)
	TypeNode get_line(int l, int r, TypeValue x) {
		if (l < 0 || length <= l || r < 0 || length < r) return {0,Operator::unit_value};
		TypeNode vl = {0,Operator::unit_value}, vr = {0,Operator::unit_value};
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) {
				auto tl=node[l++].get_line(x);                
				vl = (Operator::func_compare(y(vl,x),y(tl,x))?vl:tl);
			}
			if(r&1) {
				auto tr=node[--r].get_line(x);                
				vr = (Operator::func_compare(y(tr,x),y(vr,x))?tr:vr);
			}
		}
		return (Operator::func_compare(y(vl,x),y(vr,x))?vl:vr);
	}
	void print(){
		cout << "node" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			node[i].print();
			if(i==((1<<j)-1) && ++j) cout << endl;
		}    
	}
};