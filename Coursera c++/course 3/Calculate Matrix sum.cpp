//#include "test_runner.h"
//#include "profile.h"
//
//#include <algorithm>
//#include <cstdint>
//#include <future>
//#include <vector>
//
//using namespace std;
//
//template <typename Iterator>
//class IteratorRange {
//public:
//    IteratorRange(Iterator first_, Iterator last_, size_t page_size_)
//    : first(first_)
//    , last(last_)
//    , page_size(page_size_) {};
//
//    Iterator begin() const {
//        return first;
//    }
//
//    Iterator end() const {
//        return last;
//    }
//
//    size_t size() const {
//        return page_size;
//    }
//
//private:
//    Iterator first;
//    Iterator last;
//    size_t page_size;
//};
//
//template <typename Iterator>
//class Paginator {
//public:
//    Paginator(Iterator first, Iterator last, size_t page_size) {
//        for (auto begin = first; begin < last; begin += page_size) {
//            auto end = begin + page_size < last ? begin + page_size : last;
//            pages.push_back({begin, end, static_cast<size_t>(distance(begin, end))});
//        }
//    }
//
//    auto begin() const {
//        return pages.begin();
//    }
//
//    auto end() const {
//        return pages.end();
//    }
//
//
//    size_t size() const {
//        return pages.size();
//    }
//
//private:
//    vector<IteratorRange<Iterator>> pages;
//};
//
//template <typename C>
//auto Paginate(C& c, size_t page_size) {
//    return Paginator{ c.begin(), c.end(), page_size };
//}
//
//template <typename ContainerOfVectors>
//int64_t SumSingleThread(const ContainerOfVectors& matrix) {
//    int64_t sum = 0;
//    for (const auto& row : matrix) {
//        for (const auto& elem : row) {
//            sum += elem;
//        }
//    }
//    return sum;
//}
//
//int64_t CalculateMatrixSum(const vector<vector<int> >& matrix) {
//    vector<future<int64_t> > sums;
//    for (auto page : Paginate(matrix, 1500)) {
//        sums.push_back(async([=] {
//            return SumSingleThread(page);
//        }));
//    }
//    int64_t sum = 0;
//    for (auto& a : sums) {
//        sum += a.get();
//    }
//    return sum;
//}
//
//void TestCalculateMatrixSum() {
//    const vector<vector<int>> matrix = {
//        {1, 2, 3, 4},
//        {5, 6, 7, 8},
//        {9, 10, 11, 12},
//        {13, 14, 15, 16}
//    };
//    ASSERT_EQUAL(CalculateMatrixSum(matrix), 136);
//}
//
//int main() {
//    {
//        LOG_DURATION("Multi Threading Calculation");
//        TestRunner tr;
//        RUN_TEST(tr, TestCalculateMatrixSum);
//    }
//}
