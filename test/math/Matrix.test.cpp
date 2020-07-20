#define PROBLEM "https://yukicoder.me/problems/no/718"

#include <vector>
#include <iostream>
#include <array>
#include <cassert>
using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/Matrix.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    using modint = ModInt<MOD>;
    vector<vector<modint>> a(4,vector<modint>(4));
    a[0] = {1,2,2,-1};
    a[1] = {0,2,2,-1};
    a[2] = {0,1,0,0};
    a[3] = {0,0,1,0};
    long long N; cin >> N;
    if(N==1){
        cout << 1 << endl;
        return 0;
    }
    if(N==2){
        cout << 2 << endl;
        return 0;
    }
    Matrix<modint,4> b(a);
    auto s = b.pow(N-2);
    cout << s.a[0][0]*2+s.a[0][1]+s.a[0][2] << endl;
	return 0;
}