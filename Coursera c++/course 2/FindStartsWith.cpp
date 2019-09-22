//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//template <typename RandomIt>
//pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
//    string value = {prefix};
//    auto left = lower_bound(range_begin, range_end, value);
//
//    auto next = static_cast<char>(prefix + 1);
//    std::string value2 = {next};
//    auto right = lower_bound(range_begin, range_end, value2);
//    return make_pair(left, right);
//}
//
//template <typename RandomIt>
//pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
//    auto left = lower_bound(range_begin, range_end, prefix);
//
//    std::string prefix2 = prefix;
//    char ch = prefix2.back();
//    ch++;
//    prefix2.pop_back();
//    prefix2 += ch;
//    auto right = lower_bound(range_begin, range_end, prefix2);
//    return make_pair(left, right);
//}
//
//int main() {
//    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
//
//    const auto mo_result =
//    FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
//    for (auto it = mo_result.first; it != mo_result.second; ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    const auto mt_result =
//    FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
//    cout << (mt_result.first - begin(sorted_strings)) << " " <<
//    (mt_result.second - begin(sorted_strings)) << endl;
//
//    const auto na_result =
//    FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
//    cout << (na_result.first - begin(sorted_strings)) << " " <<
//    (na_result.second - begin(sorted_strings)) << endl;
//
//    return 0;
//}
