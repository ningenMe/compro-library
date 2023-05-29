#define PROBLEM "https://yukicoder.me/problems/no/741"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/30-math/CombinationMod.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
    CombinationMod<MOD> CM(N+10);
    cout << CM.binom(N+9,9) << endl;
	return 0;
}