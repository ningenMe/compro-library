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
    Matrix(const Matrix& matrix):h(H),w(W) {
        assert(H==matrix.h&&W==matrix.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]=matrix.a[i][j];
    }
    static Matrix E() {
        assert(H==W);
        Matrix<T,H,W> res = Matrix();
        for(int i = 0; i < H; ++i) res.a[i][i]=1;
        return res;
    }
    Matrix &operator+=(const Matrix &r) {
        assert(H==r.h&&W==r.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]+=r.a[i][j];
		return *this;
	}
    Matrix &operator-=(const Matrix &r) {
        assert(H==r.h&&W==r.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]-=r.a[i][j];
		return *this;
	}
    Matrix &operator*=(const Matrix &r) {
        assert(W==r.h);
        Matrix res = Matrix();
        for(int i = 0; i < H; ++i) for(int j = 0; j < r.w; ++j) for(int k = 0; k < W; ++k) res.a[i][j]+=a[i][k]*r.a[k][j];
        a=res.a;
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
    Matrix pow(long long K) const {
        assert(H == W);
        Matrix x = *this;
        Matrix res = this->E();
        for (; K > 0; K /= 2) {
            if (K & 1) res *= x;
            x *= x;
        }
        return res;
    }
};