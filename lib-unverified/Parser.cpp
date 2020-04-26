template<class T> class Parser {
public:
    int root;
    vector<T> res;
    vector<int> leftNode, rightNode; //左右の子へのindex
	vector<int> idx;//元のindex

	string str;    //構文
	vector<T> num; //数値
    
	Parser(const string& str,const vector<T>& num):str(str),num(num){
        int p = 0;
        root = expr(p);
	}
	
	//構文木のindexに対する文字を取り出す
	char getOperator(int q){
		assert(0 <= q && q <= str.size());
		return str[idx[q]];
	}

private:
	int newNode(int i, int l, int r) {
		leftNode.push_back(l);
		rightNode.push_back(r);
        T val;
		if (str[i] == 'a') {
            val = num[i];
        }
		else if(str[i] == '(' || str[i] == ')'){
            val = -1;
		}
        else {
            if (str[i] == '+') val = res[l] + res[r];
            if (str[i] == '-') val = res[l] - res[r];
            if (str[i] == '*') val = res[l] * res[r];
            if (str[i] == '/') val = res[l] / res[r];
        }
		res.push_back(val);
		idx.push_back(i);
        return (int)res.size() - 1;
    }
    
    int expr(int &p) {
        int l = factor(p);
        while (p < (int)str.size() && (str[p] == '+' || str[p] == '-')) {
			int i = p++;
            int r = factor(p);
            l = newNode(i, l, r);
        }
        return l;
    }
    
    int factor(int &p) {
        int l = value(p);
        while (p < (int)str.size() && (str[p]== '*' || str[p] == '/')) {
			int i = p++;
            int r = value(p);
            l = newNode(i, l, r);
        }
        return l;
    }
    
    int value(int &p) {
        if (str[p] == '(') {
            newNode(p, -1, -1);  //'('
			p++;
            int l = expr(p);
            newNode(p, -1, -1);  //')'
            p++;
			return l;
        }
        else {
			int i = p++;
            return newNode(i, -1, -1);
        }
    }
};