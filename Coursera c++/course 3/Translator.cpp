//#include "test_runner.h"
//
//#include <deque>
//#include <map>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Translator {
//public:
//    void Add(string_view source, string_view target) {
//        const string_view source_view = GetClonedView(source);
//        const string_view target_view = GetClonedView(target);
//        forwardList[source_view] = target_view;
//        backwardList[target_view] = source_view;
//    }
//    
//    string_view TranslateForward(string_view source) const {
//        try {
//            return forwardList.at(source);
//        } catch (exception& ex) {
//            return {};
//        }
//    }
//    
//    string_view TranslateBackward(string_view target) const {
//        try {
//            return backwardList.at(target);
//        } catch (exception& ex) {
//            return {};
//        }
//    }
//    
//private:
//    string_view GetClonedView(string_view s) {
//        for (const auto* map_ptr : {&forwardList, &backwardList}) {
//            const auto it = map_ptr->find(s);
//            if (it != map_ptr->end()) {
//                return it->first;
//            }
//        }
//        return data.emplace_back(s);
//    }
//    
//    map<string_view, string_view> forwardList;
//    map<string_view, string_view> backwardList;
//    deque<string> data;
//};
//
//void TestSimple() {
//    Translator translator;
//    translator.Add(string("okno"), string("window"));
//    translator.Add(string("stol"), string("table"));
//    
//    ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
//    ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
//    ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
//    
//    translator.Add(string("okno"), string("window2"));
//    ASSERT_EQUAL(translator.TranslateForward("okno"), "window2");
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, TestSimple);
//    return 0;
//}
