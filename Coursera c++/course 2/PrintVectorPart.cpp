//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//template <typename It>
//void PrintVector(It range_begin, It range_end) {
//    while (range_end != range_begin) {
//        --range_end;
//        cout << *range_end << " ";
//    }
//}
//
//void PrintVectorPart(const vector<int>& numbers) {
//    auto it = find_if(numbers.begin(), numbers.end(), [] (const int& a) {
//        return a < 0;
//    });
//    
//    PrintVector(numbers.begin(), it);
//}
//
//int main() {
//    PrintVectorPart({6, 1, 8, -5, 4});
//    cout << endl;
//    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
//    cout << endl;
//    PrintVectorPart({6, 1, 8, 5, 4});
//    cout << endl;
//    return 0;
//}
