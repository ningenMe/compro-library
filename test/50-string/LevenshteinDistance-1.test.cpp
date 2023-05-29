#define PROBLEM "https://yukicoder.me/problems/no/225"

#include <vector>
#include <iostream>
#include <string>
using namespace std;
#include "../../lib/50-string/LevenshteinDistance.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int a; cin >> a >> a;
    string S,T; cin >> S >> T;
    cout << LevenshteinDistance(S,T) << endl;
    return 0;
}
