//#include <iomanip>
//#include <iostream>
//#include <vector>
//#include <utility>
//
//using namespace std;
//
//class ReadingManager {
//public:
//    ReadingManager()
//    : user_page_counts_(MAX_USER_COUNT_ + 1, 0)
//    , count_person_(MAX_PAGES_COUNT_ + 1, 0)
//    {}
//    
//    void Read(int user_id, int page_count) {
//        if (user_page_counts_[user_id] == 0) {
//            ++users_count_;
//        } else {
//            --count_person_[user_page_counts_[user_id]];
//        }
//        
//        user_page_counts_[user_id] = page_count;
//        ++count_person_[page_count];
//    }
//    
//    double Cheer(int user_id) const {
//        if (user_page_counts_[user_id] == 0) {
//            return 0;
//        }
//        
//        if (users_count_ == 1) {
//            return 1;
//        }
//        
//        int page_number = user_page_counts_[user_id];
//        int users_count = 0;
//        for (size_t i = 0; i < page_number; ++i) {
//            users_count += count_person_[(int)i];
//        }
//        
//        return users_count * 1.0 / (users_count_ - 1);
//    }
//    
//private:
//    static const int MAX_USER_COUNT_ = 100'000;
//    static const int MAX_PAGES_COUNT_ = 1000;
//    int users_count_ = 0;
//    vector<int> user_page_counts_;
//    vector<int> count_person_;
//};
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    
//    ReadingManager manager;
//    
//    int query_count;
//    cin >> query_count;
//    
//    for (int query_id = 0; query_id < query_count; ++query_id) {
//        string query_type;
//        cin >> query_type;
//        int user_id;
//        cin >> user_id;
//        
//        if (query_type == "READ") {
//            int page_count;
//            cin >> page_count;
//            manager.Read(user_id, page_count);
//        } else if (query_type == "CHEER") {
//            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
//        }
//    }
//    
//    return 0;
//}
