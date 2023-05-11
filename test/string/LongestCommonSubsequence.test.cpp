#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include "../../lib/string/LongestCommonSubsequence.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int Q; cin >> Q;
    while(Q--) {
        string S,T; cin >> S >> T;
        cout << LongestCommonSubsequence(S,T).size() << endl;
    }
    return 0;
}
