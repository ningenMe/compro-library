/*
 * @title Rational - 有理数
 * @docs md/util/Rational.md
 */
class Rational {
    long long numerator, denominator;
public:
    friend ostream &operator<<(ostream &os, const Rational &rhs) {return os << rhs.numerator << "/" << rhs.denominator;}
    constexpr Rational(const long long num, const long long den):numerator(num),denominator(den){
        if(den<0) denominator*=(-1),numerator*=(-1);
        if(den==0) numerator=1,denominator=0;
    }
    constexpr Rational(const long long val):Rational(val,1){}
    constexpr Rational(const int val):Rational((long long)val){}
    constexpr Rational():Rational(0){}
    inline static constexpr Rational inf() {
        return Rational(1LL,0LL);
    }
    constexpr Rational &operator+=(const Rational &rhs) {
        numerator=numerator*rhs.denominator+denominator*rhs.numerator; 
        denominator*=rhs.denominator;
        if(denominator==0) numerator=1;
        return *this;
    }
    constexpr Rational &operator-=(const Rational &rhs) {
        numerator=numerator*rhs.denominator-denominator*rhs.numerator; 
        denominator*=rhs.denominator;
        if(denominator==0) numerator=1;
        return *this;
    }
    constexpr Rational &operator*=(const Rational &rhs) {
        numerator*=rhs.numerator;
        denominator*=rhs.denominator;
        if(denominator==0) numerator=1;
        return *this;
    }
    constexpr Rational &operator/=(const Rational &rhs) {*this *= rhs.inv();return *this;}
    constexpr Rational operator-() const {return Rational(-numerator, denominator); }
    constexpr Rational operator+(const Rational &rhs) const { return Rational(*this) += rhs; }
    constexpr Rational operator-(const Rational &rhs) const { return Rational(*this) -= rhs; }
    constexpr Rational operator*(const Rational &rhs) const { return Rational(*this) *= rhs; }
    constexpr Rational operator/(const Rational &rhs) const { return Rational(*this) /= rhs; }
    constexpr bool operator<(const Rational &rhs) const { return numerator*rhs.denominator < denominator*rhs.numerator; }
    constexpr bool operator<=(const Rational &rhs) const { return numerator*rhs.denominator <= denominator*rhs.numerator; }
    constexpr bool operator>(const Rational &rhs) const { return rhs < *this; }
    constexpr bool operator>=(const Rational &rhs) const { return rhs <= *this; }
    constexpr bool operator==(const Rational &rhs) const { return numerator*rhs.denominator == denominator*rhs.numerator; }
    constexpr bool operator!=(const Rational &rhs) const { return !(*this == rhs); }
    constexpr Rational inv() const {return (numerator==0?inf():Rational(denominator,numerator));}
};