//#include <exception>
//#include <iostream>
//#include <map>
//
//using namespace std;
//
//template <typename Key, typename Value>
//Value& GetRefStrict(map<Key, Value>& m, Key key) {
//    try {
//        return m.at(key);
//    } catch (const std::out_of_range& oor) {
//        throw std::runtime_error("Out of range");
//    }
//}
//
////int main() {
////    map<int, string> m = {{0, "value"}};
////    string& item = GetRefStrict(m, 0);
////    item = "newvalue";
////    cout << m[0] << endl; // выведет newvalue
////    return 0;
////}
