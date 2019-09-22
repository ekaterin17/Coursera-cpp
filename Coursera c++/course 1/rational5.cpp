//#include <cmath>
//#include <iostream>
//#include <sstream>
//#include <map>
//#include <set>
//#include <stdexcept>
//
//using namespace std;
//
//int gcd(int a, int b) {
//    while (a != 0 && b != 0) {
//        if (a > b) {
//            a %= b;
//        } else {
//            b %= a;
//        }
//    }
//    return a + b;
//}
//
//class Rational {
//public:
//    Rational() {
//        num = 0;
//        denom = 1;
//    };
//    Rational(int numerator, int denominator) {
//        if (denominator == 0) throw invalid_argument("Invalid argument");
//        bool minus = false;
//        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) {
//            minus = true;
//        }
//        numerator = abs(numerator);
//        denominator = abs(denominator);
//
//        int gcdOfNumbers = gcd(numerator, denominator);
//        num = numerator / gcdOfNumbers;
//        denom = denominator / gcdOfNumbers;
//        if (minus) num *= -1;
//    };
//
//    int Numerator() const {
//        return num;
//    };
//    int Denominator() const {
//        return denom;
//    };
//private:
//    int num;
//    int denom;
//};
//
//bool operator == (const Rational& lhs, const Rational& rhs) {
//    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
//}
//
//Rational& operator + (const Rational& lhs, const Rational& rhs) {
//    Rational res(lhs.Numerator()*rhs.Denominator() + lhs.Denominator() * rhs.Numerator(),
//                 lhs.Denominator() * rhs.Denominator());
//    return res;
//}
//
//Rational& operator - (const Rational& lhs, const Rational& rhs) {
//    Rational res(lhs.Numerator()*rhs.Denominator() - lhs.Denominator() * rhs.Numerator(),
//                 lhs.Denominator() * rhs.Denominator());
//    return res;
//}
//
//Rational& operator * (const Rational& lhs, const Rational& rhs) {
//    Rational res(lhs.Numerator()*rhs.Numerator(),
//                 lhs.Denominator() * rhs.Denominator());
//    return res;
//}
//
//Rational& operator / (const Rational& lhs, const Rational& rhs) {
//    if (rhs.Numerator() == 0) throw domain_error("Domain error");
//    Rational res(lhs.Numerator()*rhs.Denominator(),
//                 lhs.Denominator() * rhs.Numerator());
//    return res;
//}
//
//istream& operator >> (istream& stream, Rational& r) {
//    int p, q;
//    if (stream >> p && stream.ignore(1) && stream >> q) {
//        r ={p,q};
//    }
//    return stream;
//}
//
//ostream& operator << (ostream& stream, const Rational& r) {
//    stream << r.Numerator() << "/" << r.Denominator();
//    return stream;
//}
//
//bool operator > (const Rational& lhs, const Rational& rhs) {
//    return (lhs.Numerator() / (double) lhs.Denominator()) > (rhs.Numerator() /(double)rhs.Denominator());
//}
//
//bool operator < (const Rational& lhs, const Rational& rhs) {
//    return (lhs.Numerator() / (double) lhs.Denominator()) < (rhs.Numerator() /(double)rhs.Denominator());
//}
//
//int main() {
//    try {
//        Rational r(1, 0);
//        cout << "Doesn't throw in case of zero denominator" << endl;
//        return 1;
//    } catch (invalid_argument&) {
//    }
//
//    try {
//        auto x = Rational(1, 2) / Rational(0, 1);
//        cout << "Doesn't throw in case of division by zero" << endl;
//        return 2;
//    } catch (domain_error&) {
//    }
//
//    cout << "OK" << endl;
//    return 0;
//}
