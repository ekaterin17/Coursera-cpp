//#include "test_runner.h"
//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <memory>
//#include <set>
//#include <utility>
//#include <vector>
//
//using namespace std;
//
//template <typename T>
//class PriorityCollection {
//public:
//    using Id = size_t;
//
//    // Добавить объект с нулевым приоритетом
//    // с помощью перемещения и вернуть его идентификатор
//    Id Add(T object) {
//        objects[ID] = {ID, 0, move(object)};
//        setOfObjects.insert({0,ID});
//        ID++;
//        return ID-1;
//    }
//
//    // Добавить все элементы диапазона [range_begin, range_end)
//    // с помощью перемещения, записав выданные им идентификаторы
//    // в диапазон [ids_begin, ...)
//    template <typename ObjInputIt, typename IdOutputIt>
//    void Add(ObjInputIt range_begin, ObjInputIt range_end, IdOutputIt ids_begin) {
//        for (auto it = range_begin; it != range_end; ++it) {
//            auto id = Add(move(*it));
//            *(ids_begin++) = id;
//        }
//    }
//
//    // Определить, принадлежит ли идентификатор какому-либо
//    // хранящемуся в контейнере объекту
//    bool IsValid(Id id) const {
//        try {
//            objects.at(id);
//        }
//        catch(exception&) {
//            return false;
//        }
//        return true;
//    }
//
//    // Получить объект по идентификатору
//    const T& Get(Id id) const {
//        return objects.at(id).val;
//    }
//
//    // Увеличить приоритет объекта на 1
//    void Promote(Id id) {
//        auto it = setOfObjects.find({objects[id].priority, id});
//        setOfObjects.erase(it);
//        ++objects[id].priority;
//        setOfObjects.insert({objects[id].priority, id});
//    }
//
//    // Получить объект с максимальным приоритетом и его приоритет
//    pair<const T&, int> GetMax() const {
//        auto maxOb = setOfObjects.rbegin();
//        return {objects.at(maxOb->second).val, maxOb->first};
//    }
//
//    // Аналогично GetMax, но удаляет элемент из контейнера
//    pair<T, int> PopMax() {
//        auto maxOb = setOfObjects.rbegin();
//        Id id = maxOb->second;
//        setOfObjects.erase(*maxOb);
//        Item& item = objects[id];
//        objects.erase(id);
//        return {move(item.val), move(item.priority)};
//    }
//
//private:
//    Id ID = 0;
//    struct Item {
//        Id id;
//        size_t priority;
//        T val;
//    };
//
//    map<Id, Item> objects;
//    set<pair<size_t, Id> > setOfObjects;
//};
//
//class StringNonCopyable : public string {
//public:
//    using string::string;
//    StringNonCopyable(const StringNonCopyable&) = delete;
//    StringNonCopyable(StringNonCopyable&&) = default;
//    StringNonCopyable& operator=(const StringNonCopyable&) = delete;
//    StringNonCopyable& operator=(StringNonCopyable&&) = default;
//};
//
//void TestNoCopy() {
//    PriorityCollection<StringNonCopyable> strings;
//
//    const auto white_id = strings.Add("white");
//    const auto yellow_id = strings.Add("yellow");
//    const auto red_id = strings.Add("red");
//
//    strings.Promote(yellow_id);
//    for (int i = 0; i < 2; ++i) {
//        strings.Promote(red_id);
//    }
//    strings.Promote(yellow_id);
//    {
//        const auto& item = strings.Get(1);
//        ASSERT_EQUAL(item, "yellow");
//    }
//    {
//        const auto item = strings.GetMax();
//        ASSERT_EQUAL(item.first, "red");
//        ASSERT_EQUAL(item.second, 2);
//    }
//    {
//        const auto item = strings.PopMax();
//        ASSERT_EQUAL(item.first, "red");
//        ASSERT_EQUAL(item.second, 2);
//    }
//    {
//        const auto item = strings.PopMax();
//        ASSERT_EQUAL(item.first, "yellow");
//        ASSERT_EQUAL(item.second, 2);
//    }
//    {
//        const auto item = strings.PopMax();
//        ASSERT_EQUAL(item.first, "white");
//        ASSERT_EQUAL(item.second, 0);
//    }
//
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, TestNoCopy);
//    return 0;
//}
