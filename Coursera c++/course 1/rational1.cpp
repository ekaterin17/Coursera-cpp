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
////int main() {
////    {
////        const Rational r(3, 10);
////        if (r.Numerator() != 3 || r.Denominator() != 10) {
////            cout << "Rational(3, 10) != 3/10" << endl;
////            return 1;
////        }
////    }
////
////    {
////        const Rational r(8, 12);
////        if (r.Numerator() != 2 || r.Denominator() != 3) {
////            cout << "Rational(8, 12) != 2/3" << endl;
////            return 2;
////        }
////    }
////
////    {
////        const Rational r(-4, 6);
////        if (r.Numerator() != -2 || r.Denominator() != 3) {
////            cout << "Rational(-4, 6) != -2/3" << endl;
////            return 3;
////        }
////    }
////
////    {
////        const Rational r(4, -6);
////        if (r.Numerator() != -2 || r.Denominator() != 3) {
////            cout << "Rational(4, -6) != -2/3" << endl;
////            return 3;
////        }
////    }
////
////    {
////        const Rational r(0, 15);
////        if (r.Numerator() != 0 || r.Denominator() != 1) {
////            cout << "Rational(0, 15) != 0/1" << endl;
////            return 4;
////        }
////    }
////
////    {
////        const Rational defaultConstructed;
////        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
////            cout << "Rational() != 0/1" << endl;
////            return 5;
////        }
////    }
////
////    cout << "OK" << endl;
////    return 0;
////}
