
// Column_01Echelon_Formalize O(N)　定数倍重め
vector<long long>  BinaryColumnEchelonFormalize(vector<long long> vec){
	for(int i = 59,idx = -1; 0 <= i; --i,idx = -1){
		sort(vec.begin(),vec.end(),greater<long long>());
		for(int j = 0,flg = 1; j < vec.size(); ++j,flg = 0){
			if( !((vec[j]>>i) & 1) ) continue;
			for(int k = 59; i < k; --k) if((vec[j]>>k) & 1) flg = 1;
			if(flg) continue;
			idx = j;
			break;
		}
		for(int j = 0; idx != -1 && j < vec.size(); ++j) if(idx != j && ((vec[j]>>i) & 1)) vec[j] ^= vec[idx];
	}

	return vec;
}