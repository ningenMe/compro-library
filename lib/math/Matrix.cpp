/*
 * @title Matrix
 */
template <class T, int H, int W = H> class Matrix {
public:
    int h,w;
    array<array<T,W>,H> a;
    Matrix():h(H),w(W){
        // do nothing
    }
    Matrix(const vector<vector<T>>& vec):h(H),w(W) {
        assert(vec.size()==H && vec.front().size()==W);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]=vec[i][j];
    }
    static Matrix E() {
        assert(H==W);
        Matrix res = Matrix();
        for(int i = 0; i < H; ++i) res[i][i]=1;
        return res;
    }
    Matrix &operator+=(const Matrix &r) {
        assert(H==r.h&&W==r.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]+=r[i][j];
		return *this;
	}
    Matrix &operator-=(const Matrix &r) {
        assert(H==r.h&&W==r.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]-=r[i][j];
		return *this;
	}
    Matrix &operator*=(const Matrix &r) {
        assert(W==r.h);
        Matrix res = Matrix();
        for(int i = 0; i < H; ++i) for(int j = 0; j < r.w; ++j) for(int k = 0; k < W; ++k) res[i][j]+=(a[i][k])*(r[k][j]);
        a.swap(res.a);
		return *this;
	}
    Matrix operator+(const Matrix& r) const {
        return Matrix(*this) += r;
    }
    Matrix operator-(const Matrix& r) const {
        return Matrix(*this) -= r;
    }
    Matrix operator*(const Matrix& r) const {
        return Matrix(*this) *= r;
    }
	inline array<T,W> &operator[](int i) { 
		return a[i];
	}
	inline const array<T,W> &operator[](int i) const { 
		return a[i];
	}
    Matrix pow(long long K) const {
        assert(H == W);
		Matrix x(*this);
        Matrix res = this->E();
        for (; K > 0; K /= 2) {
            if (K & 1) res *= x;
            x *= x;
        }
        return res;
    }
	// T determinant(void) const {
	// 	assert(H==W);
	// 	Matrix x(*this);
	// 	T res = 1;
	// 	for(int i = 0; i < W; i++) {
	// 		int idx = -1;
	// 		for(int j = i; j < W; j++) {
	// 			if(B[j][i] != 0) idx = j;
	// 		}
	// 		if(idx == -1) return 0;
	// 		if(i != idx) {
	// 			res *= -1;
	// 			swap(B[i], B[idx]);
	// 		}
	// 		res *= B[i][i];
	// 		T vv = B[i][i];
	// 		for(size_t j = 0; j < width(); j++) {
	// 			B[i][j] /= vv;
	// 		}
	// 		for(size_t j = i + 1; j < width(); j++) {
	// 			T a = B[j][i];
	// 			for(int k = 0; k < width(); k++) {
	// 			B[j][k] -= B[i][k] * a;
	// 			}
	// 		}
	// 	}
	// 	return ret;
	// }
};