//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <vector>
//
//using namespace std;
//
//template <typename RandomIt>
//void MergeSort(RandomIt range_begin, RandomIt range_end) {
//    if (range_end - range_begin < 2) {
//        return;
//    }
//
//    vector<typename RandomIt::value_type> elements(make_move_iterator(range_begin), make_move_iterator(range_end));
//    auto it1 = elements.begin() + elements.size() / 3;
//    auto it2 = elements.begin() + 2 * elements.size() / 3;
//    MergeSort(elements.begin(), it1);
//    MergeSort(it1, it2);
//    MergeSort(it2, elements.end());
//    vector<typename RandomIt::value_type> buf;
//    merge(make_move_iterator(elements.begin()), make_move_iterator(it1), make_move_iterator(it1), make_move_iterator(it2), back_inserter(buf));
//    merge(make_move_iterator(buf.begin()), make_move_iterator(buf.end()), make_move_iterator(it2), make_move_iterator(elements.end()), range_begin);
//}
//
//int main() {
//    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
//    MergeSort(begin(v), end(v));
//    for (int x : v) {
//        cout << x << " ";
//    }
//    cout << endl;
//    return 0;
//}
