//#include <iostream>
//#include <map>
//#include <set>
//#include <sstream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//template <class T>
//ostream& operator << (ostream& os, const vector<T>& s) {
//    os << "{";
//    bool first = true;
//    for (const auto& x : s) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << x;
//    }
//    return os << "}";
//}
//
//template <class T>
//ostream& operator << (ostream& os, const set<T>& s) {
//    os << "{";
//    bool first = true;
//    for (const auto& x : s) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << x;
//    }
//    return os << "}";
//}
//
//template <class K, class V>
//ostream& operator << (ostream& os, const map<K, V>& m) {
//    os << "{";
//    bool first = true;
//    for (const auto& kv : m) {
//        if (!first) {
//            os << ", ";
//        }
//        first = false;
//        os << kv.first << ": " << kv.second;
//    }
//    return os << "}";
//}
//
//template<class T, class U>
//void AssertEqual(const T& t, const U& u, const string& hint = {}) {
//    if (t != u) {
//        ostringstream os;
//        os << "Assertion failed: " << t << " != " << u;
//        if (!hint.empty()) {
//            os << " hint: " << hint;
//        }
//        throw runtime_error(os.str());
//    }
//}
//
//void Assert(bool b, const string& hint) {
//    AssertEqual(b, true, hint);
//}
//
//class TestRunner {
//public:
//    template <class TestFunc>
//    void RunTest(TestFunc func, const string& test_name) {
//        try {
//            func();
//            cerr << test_name << " OK" << endl;
//        } catch (exception& e) {
//            ++fail_count;
//            cerr << test_name << " fail: " << e.what() << endl;
//        } catch (...) {
//            ++fail_count;
//            cerr << "Unknown exception caught" << endl;
//        }
//    }
//    
//    ~TestRunner() {
//        if (fail_count > 0) {
//            cerr << fail_count << " unit tests failed. Terminate" << endl;
//            exit(1);
//        }
//    }
//    
//private:
//    int fail_count = 0;
//};
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
//        if (numerator == 0) {
//            num = 0;
//            denom = 1;
//        } else {
//            bool minus = false;
//            if (numerator * denominator < 0) {
//                minus = true;
//            }
//            numerator = abs(numerator);
//            denominator = abs(denominator);
//            
//            int gcdOfNumbers = gcd(numerator, denominator);
//            num = numerator / gcdOfNumbers;
//            denom = denominator / gcdOfNumbers;
//            if (minus) num *= -1;
//        }
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
//void TestDefaultConstructor() {
//    Rational r = Rational();
//    AssertEqual(r.Numerator(), 0);
//    AssertEqual(r.Denominator(), 1);
//}
//
//void TestRational() {
//    Rational r(4,10);
//    AssertEqual(r.Numerator(), 2);
//    AssertEqual(r.Denominator(), 5);
//}
//
//void TestNegativeNumertor() {
//    Rational r(-3,9);
//    AssertEqual(r.Numerator(), -1);
//    AssertEqual(r.Denominator(), 3);
//}
//
//void TestNegativeDenominator() {
//    Rational r(3,-9);
//    AssertEqual(r.Numerator(), -1);
//    AssertEqual(r.Denominator(), 3);
//}
//
//void TestBothNegative() {
//    Rational r(-3,-9);
//    AssertEqual(r.Numerator(), 1);
//    AssertEqual(r.Denominator(), 3);
//}
//
//void TestZeroNumerator() {
//    Rational r(0,9);
//    AssertEqual(r.Numerator(), 0);
//    AssertEqual(r.Denominator(), 1);
//}
//
//int main() {
//    TestRunner runner;
//    runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
//    runner.RunTest(TestRational, "TestRational");
//    runner.RunTest(TestNegativeNumertor, "TestNegativeNumertor");
//    runner.RunTest(TestNegativeDenominator, "TestNegativeDenominator");
//    runner.RunTest(TestBothNegative, "TestBothNegative");
//    runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
//    
//    return 0;
//}
