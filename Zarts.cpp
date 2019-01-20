#include <bits/stdc++.h>
using namespace std;

//Seat Pressure O(NlogN)
template<class T> vector<int> Zarts(const vector<T> & ar, int cnt = 0) {
    vector<int> res;
    map<T, int> mp;
    for (auto &e : ar) mp[e] = 0;
    for (auto &e : mp) e.second = cnt++;
    for (auto &e : ar) res.push_back(mp[e]);
    return res;
}


//verify https://atcoder.jp/contests/abc036/tasks/abc036_c