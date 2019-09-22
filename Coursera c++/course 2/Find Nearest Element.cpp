//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <set>
//
//using namespace std;
//
//set<int>::const_iterator FindNearestElement(const set<int>& numbers,int border) {
//    set<int>::const_iterator left_it = lower_bound(numbers.begin(), numbers.end(),border);
//    if (left_it == numbers.begin()) {
//        return left_it;
//    }
//    if (left_it == numbers.end()) {
//        return prev(left_it);
//    }
//    
//    return border - *prev(left_it) <= *left_it - border ? prev(left_it) : left_it;
//}
//
//int main() {
//    set<int> numbers = {1, 4, 6};
//    cout <<
//    *FindNearestElement(numbers, 0) << " " <<
//    *FindNearestElement(numbers, 3) << " " <<
//    *FindNearestElement(numbers, 5) << " " <<
//    *FindNearestElement(numbers, 6) << " " <<
//    *FindNearestElement(numbers, 100) << endl;
//    
//    set<int> empty_set;
//    
//    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
//    return 0;
//}
