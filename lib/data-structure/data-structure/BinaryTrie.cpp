/*
 * @title BinaryTrie
 * @docs md/data-structure/data-structure/BinaryTrie.md
 */
template<class Operator, int bit=60> class BinaryTrie{
	using TypeNode = typename Operator::TypeNode; 
public:
	vector<TypeNode> node;
	vector<vector<int>> ch;
	BinaryTrie():node(1),ch(1,vector<int>(2,-1)){}
	void operate(long long idx, const TypeNode var) {
		int curr=0;
		stack<int> st;
		for(int i=bit-1; 0 <= i; --i) {
			st.push(curr);
			int f=(idx>>i)&1;
			if(ch[curr][f]==-1) {
				node.push_back(Operator::unit_node);
				ch.push_back(vector<int>(2,-1));
				ch[curr][f] = (int)node.size()-1;
			}
			curr = ch[curr][f];
		}
		node[curr] = Operator::func_operate(node[curr],var);
		while(st.size()) {
			curr = st.top(); st.pop();
			node[curr]=Operator::unit_node;
			if(ch[curr][0]!=-1)	node[curr] = Operator::func_fold(node[ch[curr][0]],node[curr]);
			if(ch[curr][1]!=-1)	node[curr] = Operator::func_fold(node[curr],node[ch[curr][1]]);
		}
	}
	TypeNode fold(long long idx) {
		int curr=0;
		for(int i=bit-1; 0 <= i; --i) {
			int f=(idx>>i)&1;
			if(ch[curr][f]!=-1) curr = ch[curr][f];
			else return Operator::unit_node;
		}
		return node[curr];
	}
	long long min_bitwise_xor(long long x) {
		int curr=0;
		long long y=0;
		for(int i=bit-1; 0 <= i; --i) {
			long long f=(x>>i)&1;
			if(!node[curr]) break;
			if(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];
			else curr = ch[curr][f^=1];
			y^=(f<<i);
		}
		return y^x;
	}
};
