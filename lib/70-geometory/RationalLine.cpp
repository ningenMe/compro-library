/*
 * @title RationalLine - 有理数直線
 * @docs md/geometory/RationalLine.md
 */
class RationalLine {
    pair<Rational,Rational> p;
public:
    constexpr RationalLine(const long long x1,const long long y1,const long long x2,const long long y2) {
        Rational slope(y2-y1,x2-x1), intercept(y1*x2-x1*y2,x2-x1);
        if(slope == Rational::inf()) intercept = x1;
        p.first=slope;
        p.second=intercept;
    }
    constexpr bool operator<(const RationalLine &rhs) const { return p < rhs.p; }
    constexpr bool operator<=(const RationalLine &rhs) const { return p <= rhs.p; }
    constexpr bool operator>(const RationalLine &rhs) const { return rhs.p < p; }
    constexpr bool operator>=(const RationalLine &rhs) const { return rhs.p <= p; }
    constexpr bool operator==(const RationalLine &rhs) const { return p == rhs.p; }
    constexpr bool operator!=(const RationalLine &rhs) const { return p != rhs.p; }
    friend ostream &operator<<(ostream &os, const RationalLine &rhs) {return os << "{" << rhs.p.first << "," << rhs.p.second << "}";}
};