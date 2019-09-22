//#include "test_runner.h"
//
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <queue>
//#include <stdexcept>
//#include <set>
//using namespace std;
//
//template <class T>
//class ObjectPool {
//public:
//    T* Allocate() {
//        if (deallocated_objects.empty()) {
//            T* new_object = new T;
//            allocated_objects.insert(new_object);
//            return new_object;
//        }
//        
//        return GetDeallocatedObject();
//    }
//    
//    T* TryAllocate() {
//        if (deallocated_objects.empty()) {
//            return nullptr;
//        }
//        
//        return GetDeallocatedObject();
//    }
//    
//    void Deallocate(T* object) {
//        if (allocated_objects.find(object) != allocated_objects.end()) {
//            allocated_objects.erase(object);
//            deallocated_objects.push(object);
//        } else {
//            throw invalid_argument("Object was not found");
//        }
//    }
//    
//    ~ObjectPool() {
//        for (T* object: allocated_objects) {
//            delete object;
//        }
//        allocated_objects.clear();
//        
//        while (!deallocated_objects.empty()) {
//            delete deallocated_objects.front();
//            deallocated_objects.pop();
//        }
//    }
//    
//private:
//    set<T*> allocated_objects;
//    queue<T*> deallocated_objects;
//    
//    T* GetDeallocatedObject() {
//        T* new_object = deallocated_objects.front();
//        deallocated_objects.pop();
//        allocated_objects.insert(new_object);
//        return new_object;
//    }
//    
//};
//
//void TestObjectPool() {
//    ObjectPool<string> pool;
//    
//    auto p1 = pool.Allocate();
//    auto p2 = pool.Allocate();
//    auto p3 = pool.Allocate();
//    
//    *p1 = "first";
//    *p2 = "second";
//    *p3 = "third";
//    
//    pool.Deallocate(p2);
//    ASSERT_EQUAL(*pool.Allocate(), "second");
//    
//    pool.Deallocate(p3);
//    pool.Deallocate(p1);
//    ASSERT_EQUAL(*pool.Allocate(), "third");
//    ASSERT_EQUAL(*pool.Allocate(), "first");
//    
//    pool.Deallocate(p1);
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, TestObjectPool);
//    return 0;
//}
