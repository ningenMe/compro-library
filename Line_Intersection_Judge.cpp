#include <bits/stdc++.h>
using namespace std;

//Line Intersection Judge
template<class T> bool Line_Intersection_Judge(T ax, T ay, T bx, T by, T cx, T cy, T dx, T dy) {
    T ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    T tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    T tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    T td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
    return tc * td < 0 && ta * tb < 0;
}

//verify https://atcoder.jp/contests/abc016/tasks/abc016_4