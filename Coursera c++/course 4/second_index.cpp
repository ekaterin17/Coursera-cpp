//#include "test_runner.h"
//
//#include <iostream>
//#include <map>
//#include <set>
//#include <string>
//#include <unordered_map>
//
//using namespace std;
//
//struct Record {
//    string id;
//    string title;
//    string user;
//    int timestamp;
//    int karma;
//};
//
//// Реализуйте этот класс
//class Database {
//public:
//    bool Put(const Record& record) {
//        if (db_id.find(record.id) != db_id.end()) return false;
//        
//        records[idx] = record;
//        db_id[record.id] = idx;
//        db_timestamp[record.timestamp].insert(idx);
//        db_karma[record.karma].insert(idx);
//        db_user[record.user].insert(idx);
//        
//        ++idx;
//        return true;
//    }
//    
//    const Record* GetById(const string& id) const {
//        auto it = db_id.find(id);
//        if (it == db_id.end()) return nullptr;
//        return &records.at(it->second);
//    }
//    
//    bool Erase(const string& id) {
//        auto it = db_id.find(id);
//        if (it == db_id.end()) return false;
//        
//        size_t idx_ = it->second;
//        
//        db_timestamp[records[idx_].timestamp].erase(idx_);
//        db_karma[records[idx_].karma].erase(idx_);
//        db_user[records[idx_].user].erase(idx_);
//        records.erase(idx_);
//        db_id.erase(id);
//        
//        return true;
//    }
//    
//    template <typename Callback>
//    void RangeByTimestamp(int low, int high, Callback callback) const {
//        auto it = db_timestamp.lower_bound(low);
//        auto end = db_timestamp.upper_bound(high);
//        
//        for (; it != end; ++it) {
//            for (const size_t& a : it->second) {
//                if (!callback(records.at(a))) return;
//            }
//        }
//    }
//    
//    template <typename Callback>
//    void RangeByKarma(int low, int high, Callback callback) const {
//        auto it = db_karma.lower_bound(low);
//        auto end = db_karma.upper_bound(high);
//        
//        for (; it != end; ++it) {
//            for (const size_t& a : it->second) {
//                if (!callback(records.at(a))) return;
//            }
//        }
//    }
//    
//    template <typename Callback>
//    void AllByUser(const string& user, Callback callback) const {
//        try {
//            for (const size_t& a : db_user.at(user)) {
//                if (!callback(records.at(a))) return;
//            }
//        } catch(exception&) {
//            
//        }
//    }
//    
//private:
//    
//    unordered_map<size_t, Record> records;
//    map<string, size_t> db_id;
//    map<int, set<size_t> > db_timestamp;
//    map<int, set<size_t> > db_karma;
//    unordered_map<string, set<size_t> > db_user;
//    
//    size_t idx = 0;
//};
//
//void TestRangeBoundaries() {
//    const int good_karma = 1000;
//    const int bad_karma = -10;
//    
//    Database db;
//    db.Put({"id1", "Hello there", "master", 1536107260, good_karma});
//    db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma});
//    
//    int count = 0;
//    db.RangeByKarma(bad_karma, good_karma, [&count](const Record&) {
//        ++count;
//        return true;
//    });
//    
//    ASSERT_EQUAL(2, count);
//}
//
//void TestSameUser() {
//    Database db;
//    db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
//    db.Put({"id2", "Rethink life", "master", 1536107260, 2000});
//    
//    int count = 0;
//    db.AllByUser("master", [&count](const Record&) {
//        ++count;
//        return true;
//    });
//    
//    ASSERT_EQUAL(2, count);
//}
//
//void TestReplacement() {
//    const string final_body = "Feeling sad";
//    
//    Database db;
//    db.Put({"id", "Have a hand", "not-master", 1536107260, 10});
//    db.Erase("id");
//    db.Put({"id", final_body, "not-master", 1536107260, -10});
//    
//    auto record = db.GetById("id");
//    ASSERT(record != nullptr);
//    ASSERT_EQUAL(final_body, record->title);
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, TestRangeBoundaries);
//    RUN_TEST(tr, TestSameUser);
//    RUN_TEST(tr, TestReplacement);
//    return 0;
//}
