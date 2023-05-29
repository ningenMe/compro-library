#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <vector>
#include <iostream>
#include <array>
#include <cassert>
using namespace std;
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/math/Matrix.cpp"
constexpr long long MOD = 998'244'353;

int main(void){
    using modint = ModInt<MOD>;
    Matrix<modint,500> m=Matrix<modint,500>::E();
    int N; cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> m[i][j];
        }
    }
    cout << m.determinant() << endl;
	return 0;
}