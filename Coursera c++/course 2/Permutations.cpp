//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> permutation(n);
//    for (int i = 1; i <= n; ++i) {
//        permutation[i-1] = n-i+1;
//    }
//    
//    
//    do {
//        for (auto& i : permutation) {
//            std::cout << i << " ";
//        }
//        std::cout << std::endl;
//    } while(std::prev_permutation(permutation.begin(), permutation.end()));
//    
//    return 0;
//}
