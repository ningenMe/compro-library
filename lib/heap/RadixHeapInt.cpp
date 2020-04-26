template<class T> class RadixHeapInt{
	using TypeNode = pair<unsigned int, T>;
	array<vector<TypeNode>,33> vq;
	unsigned int size_num;
	TypeNode last;
	inline int bit(int a) {
		return a ? 32 - __builtin_clz(a) : 0;
	}
public:
	RadixHeapInt(T mini) : size_num(0), last(make_pair(0,mini)) {
		// do nothing
	}
	inline bool empty() {
		return size_num == 0;
	}
	inline size_t size(){
		return size_num;
	}
	inline void push(TypeNode x){
		++size_num;
		vq[bit(x.first^last.first)].push_back(x);
	}
	inline void emplace(unsigned int key,T val){
		++size_num;
		vq[bit(key^last.first)].emplace_back(key,val);
	}
	inline TypeNode pop() {
		if(vq[0].empty()) {
			int i = 1;
			while(vq[i].empty()) ++i;
			last = *min_element(vq[i].begin(),vq[i].end());
			for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);
			vq[i].clear();
		}
		--size_num;
		auto res = vq[0].back();
		vq[0].pop_back();
		return res;
	}
};
