//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//int main() {
//    int cnt;
//    std::cin >> cnt;
//    std::vector<int> temperatures(cnt);
//    for (int i = 0; i < cnt; ++i) {
//        std::cin >> temperatures[i];
//    }
//    
//    if (cnt == 0) {
//        std::cout << 0;
//        return 0;
//    }
//    
//    int64_t avr = 0;
//    for (auto& t : temperatures) {
//        avr += t;
//    }
//    
//    avr /= static_cast<int64_t>(temperatures.size());
//    
//    int res = count_if(temperatures.begin(), temperatures.end(), [avr](int64_t el) {return el > avr;});
//    
//    std::cout << res << std::endl;
//    for (size_t i = 0; i < temperatures.size(); ++i) {
//        if (temperatures[i] > avr) {
//            std::cout << i << " ";
//        }
//    }
//    return 0;
//}
