//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//vector<string> SplitIntoWords(const string& s) {
//    vector<string> res;
//    auto range_begin = s.begin();
//    while (range_begin < s.end()) {
//        auto it = find(range_begin, s.end(), ' ');
//        string str(range_begin, it);
//        res.push_back(str);
//        range_begin = it+1;
//    }
//    return res;
//}
//
//int main() {
//    string s = "C Cpp Java Python";
//
//    vector<string> words = SplitIntoWords(s);
//    cout << words.size() << " ";
//    for (auto it = begin(words); it != end(words); ++it) {
//        if (it != begin(words)) {
//            cout << "/";
//        }
//        cout << *it;
//    }
//    cout << endl;
//
//    return 0;
//}
