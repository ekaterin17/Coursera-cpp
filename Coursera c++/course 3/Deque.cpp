////#include "test_runner.h"
//
//#include <stdexcept>
//#include <utility>
//#include <vector>
//
//using namespace std;
//
//template <typename T>
//class Deque {
//public:
//    Deque(){}
//    
//    bool Empty() const {
//        return front.empty() && back.empty();
//    }
//    
//    size_t Size() const {
//        return front.size() + back.size();
//    }
//    
//    T& operator [] (size_t index) {
//        if (index < front.size()) {
//            return front[front.size() - index - 1];
//        } else {
//            return back[index - front.size()];
//        }
//    }
//    
//    const T& operator [] (size_t index) const {
//        if (index < front.size()) {
//            return front[front.size() - index - 1];
//        } else {
//            return back[index - front.size()];
//        }
//    }
//    
//    T& At(size_t index) {
//        if (index > Size()) {
//            throw out_of_range("Out of deque range");
//        } else {
//            return this->operator[](index);
//        }
//    }
//    
//    const T& At(size_t index) const {
//        if (index > Size()) {
//            throw out_of_range("Out of deque range");
//        } else {
//            return this->operator[](index);
//        }
//    }
//    
//    
//    T& Front() {
//        return front.empty() ? back.front() : front.back();
//    }
//    
//    const T& Front()  const{
//        return front.empty() ? back.front() : front.back();
//    }
//    
//    T& Back() {
//        return back.empty() ? front.front() : back.back();
//    }
//    
//    const T& Back()  const{
//        return back.empty() ? front.front() : back.back();
//    }
//    
//    void PushFront(const T& element) {
//        front.push_back(element);
//    }
//    
//    void PushBack(const T& element) {
//        back.push_back(element);
//    }
//    
//    
//private:
//    vector<T> front, back;
//};
//
////void TestDeque() {
////    Deque<int> d;
////    ASSERT_EQUAL(d.Size(), 0u);
////    d.Back();
////    d.PushBack(1);
////    ASSERT_EQUAL(d.Back(), 1);
////    d.PushFront(2);
////    ASSERT_EQUAL(d.Front(), 2);
////    ASSERT_EQUAL(d.Size(), 2);
////    ASSERT_EQUAL(d[0], 2);
////    ASSERT_EQUAL(d[1], 1);
//////    ASSERT_EQUAL(d.At(3), 1);
////}
////
////int main() {
////    TestRunner tr;
////    RUN_TEST(tr, TestDeque);
////    return 0;
////}
