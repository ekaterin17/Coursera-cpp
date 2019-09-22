//#include "test_runner.h"
//
//#include <utility>
//#include <vector>
//
//using namespace std;
//
//template <typename T>
//class Table {
//public:
//    Table(size_t rows_, size_t columns_) : rows(rows_), columns(columns_) {
//        Resize(rows, columns);
//    }
//    
//    void Resize(size_t rows_, size_t columns_) {
//        rows = rows_;
//        columns = columns_;
//        data.resize(rows);
//        for (auto& row: data){
//            row.resize(columns);
//        }
//    }
//    
//    const vector<T>& operator [] (size_t idx) const {
//        return data[idx];
//    }
//    
//    vector<T>& operator [] (size_t idx) {
//        return data[idx];
//    }
//    
//    pair<size_t, size_t> Size() const {
//        return make_pair(rows,columns);
//    }
//    
//private:
//    size_t rows;
//    size_t columns;
//    vector<vector<T> > data;
//};
//
//void TestTable() {
//    Table<int> t(1, 1);
//    ASSERT_EQUAL(t.Size().first, 1u);
//    ASSERT_EQUAL(t.Size().second, 1u);
//    t[0][0] = 42;
//    ASSERT_EQUAL(t[0][0], 42);
//    t.Resize(3, 4);
//    ASSERT_EQUAL(t.Size().first, 3u);
//    ASSERT_EQUAL(t.Size().second, 4u);
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, TestTable);
//    return 0;
//}
