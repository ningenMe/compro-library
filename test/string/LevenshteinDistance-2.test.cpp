#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"

#include <vector>
#include <iostream>
#include <string>
using namespace std;
#include "../../lib/string/LevenshteinDistance.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string S,T; cin >> S >> T;
    cout << LevenshteinDistance(S,T) << endl;
    return 0;
}
