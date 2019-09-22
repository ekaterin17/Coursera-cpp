//#include <cmath>
//#include <iostream>
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
//Rational operator + (const Rational& lhs, const Rational& rhs) {
//    Rational res(lhs.Numerator()*rhs.Denominator() + lhs.Denominator() * rhs.Numerator(),
//                 lhs.Denominator() * rhs.Denominator());
//    return res;
//}
//
//Rational operator - (const Rational& lhs, const Rational& rhs) {
//    Rational res(lhs.Numerator()*rhs.Denominator() - lhs.Denominator() * rhs.Numerator(),
//                 lhs.Denominator() * rhs.Denominator());
//    return res;
//}
//
//int main() {
//    {
//        Rational r1(4, 6);
//        Rational r2(2, 3);
//        bool equal = r1 == r2;
//        if (!equal) {
//            cout << "4/6 != 2/3" << endl;
//            return 1;
//        }
//    }
//    
//    {
//        Rational a(2, 3);
//        Rational b(4, 3);
//        Rational c = a + b;
//        bool equal = c == Rational(2, 1);
//        if (!equal) {
//            cout << "2/3 + 4/3 != 2" << endl;
//            return 2;
//        }
//    }
//    
//    {
//        Rational a(5, 7);
//        Rational b(2, 9);
//        Rational c = a - b;
//        bool equal = c == Rational(31, 63);
//        if (!equal) {
//            cout << "5/7 - 2/9 != 31/63" << endl;
//            return 3;
//        }
//    }
//    
//    cout << "OK" << endl;
//    return 0;
//}
