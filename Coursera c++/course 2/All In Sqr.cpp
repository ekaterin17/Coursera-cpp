//#include <iostream>
//#include <map>
//#include <utility>
//#include <vector>
//
//using namespace std;
//
//template <typename T>
//std::vector<T> operator * (const std::vector<T>& lhs, const std::vector<T>& rhs);
//
//template<typename First, typename Second>
//std::pair<First, Second> operator * (const std::pair<First, Second> lhs, const std::pair<First ,Second> rhs);
//
//template <typename Key, typename Value>
//std::map<Key, Value> operator * (const std::map<Key, Value>& lhs, const std::map<Key, Value>& rhs);
//
//template <typename T>
//T Sqr(T x);
//
//template <typename T>
//std::vector<T> operator * (const std::vector<T>& lhs, const std::vector<T>& rhs) {
//    std::vector<T> res;
//    for (size_t i = 0; i < lhs.size(); ++i) {
//        res.push_back(lhs[i] * rhs[i]);
//    }
//    return res;
//}
//
//template<typename First, typename Second>
//std::pair<First, Second> operator * (const std::pair<First, Second> lhs, const std::pair<First ,Second> rhs) {
//    First f = lhs.first * rhs.first;
//    Second s = lhs.second * rhs.second;
//    return std::make_pair(f,s);
//}
//
//template <typename Key, typename Value>
//std::map<Key, Value> operator * (const std::map<Key, Value>& lhs, const std::map<Key, Value>& rhs) {
//    std::map<Key, Value> res;
//    for (auto& item : lhs) {
//        auto second_value = rhs.at(item.first);
//        res[item.first] = item.second * second_value;
//    }
//    return res;
//}
//
//template <typename T>
//T Sqr(T x) {
//    return x * x;
//}
//
//int main() {
//    vector<int> v = {1, 2, 3};
//    cout << "vector:";
//    for (int x : Sqr(v)) {
//        cout << ' ' << x;
//    }
//    cout << endl;
//    
//    map<int, pair<int, int>> map_of_pairs = {
//        {4, {2, 2}},
//        {7, {4, 3}}
//    };
//    cout << "map of pairs:" << endl;
//    for (const auto& x : Sqr(map_of_pairs)) {
//        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
//    }
//}
