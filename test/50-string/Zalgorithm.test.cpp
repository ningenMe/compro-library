#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/50-string/Zalgorithm.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string S; cin >> S;
    Zalgorithm z(S);
    for(int i=0;i<S.size();++i) cout << z[i] << " ";
    cout << endl;
    return 0;
}
