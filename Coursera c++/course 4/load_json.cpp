//#include "json.h"
//#include "test_runner.h"
//
//#include <algorithm>
//#include <iostream>
//#include <sstream>
//#include <vector>
//using namespace std;
//
//struct Spending {
//    string category;
//    int amount;
//};
//
//bool operator == (const Spending& lhs, const Spending& rhs) {
//    return lhs.category == rhs.category && lhs.amount == rhs.amount;
//}
//
//ostream& operator << (ostream& os, const Spending& s) {
//    return os << '(' << s.category << ": " << s.amount << ')';
//}
//
//int CalculateTotalSpendings(
//                            const vector<Spending>& spendings
//                            ) {
//    int result = 0;
//    for (const Spending& s : spendings) {
//        result += s.amount;
//    }
//    return result;
//}
//
//string MostExpensiveCategory(
//                             const vector<Spending>& spendings
//                             ) {
//    auto compare_by_amount =
//    [](const Spending& lhs, const Spending& rhs) {
//        return lhs.amount < rhs.amount;
//    };
//    return max_element(begin(spendings), end(spendings),
//                       compare_by_amount)->category;
//}
//
//vector<Spending> LoadFromJson(istream& input) {
//    vector<Spending> document;
//    Document doc = Load(input);
//    for (const Node& array : doc.GetRoot().AsArray()) {
//        document.push_back({array.AsMap().at("category").AsString(), array.AsMap().at("amount").AsInt()});
//    }
//    return document;
//}
//
//void TestLoadFromJson() {
//    istringstream json_input(R"([
//                             {"amount": 2500, "category": "food"},
//                             {"amount": 1150, "category": "transport"},
//                             {"amount": 5780, "category": "restaurants"},
//                             {"amount": 7500, "category": "clothes"},
//                             {"amount": 23740, "category": "travel"},
//                             {"amount": 12000, "category": "sport"}
//                             ])");
//
//    const vector<Spending> spendings = LoadFromJson(json_input);
//
//    const vector<Spending> expected = {
//        {"food", 2500},
//        {"transport", 1150},
//        {"restaurants", 5780},
//        {"clothes", 7500},
//        {"travel", 23740},
//        {"sport", 12000}
//    };
//    ASSERT_EQUAL(spendings, expected);
//}
//
//void TestJsonLibrary() {
//    // Ð¢ÐµÑÑ‚ Ð´ÐµÐ¼Ð¾Ð½ÑÑ‚Ñ€Ð¸Ñ€ÑƒÐµÑ‚, ÐºÐ°Ðº Ð¿Ð¾Ð»ÑŒÐ·Ð¾Ð²Ð°Ñ‚ÑŒÑÑ Ð±Ð¸Ð±Ð»Ð¸Ð¾Ñ‚ÐµÐºÐ¾Ð¹ Ð¸Ð· Ñ„Ð°Ð¹Ð»Ð° json.h
//
//    istringstream json_input(R"([
//                             {"amount": 2500, "category": "food"},
//                             {"amount": 1150, "category": "transport"},
//                             {"amount": 12000, "category": "sport"}
//                             ])");
//
//    Document doc = Load(json_input);
//    const vector<Node>& root = doc.GetRoot().AsArray();
//    ASSERT_EQUAL(root.size(), 3u);
//
//    const map<string, Node>& food = root.front().AsMap();
//    ASSERT_EQUAL(food.at("category").AsString(), "food");
//    ASSERT_EQUAL(food.at("amount").AsInt(), 2500);
//
//    const map<string, Node>& sport = root.back().AsMap();
//    ASSERT_EQUAL(sport.at("category").AsString(), "sport");
//    ASSERT_EQUAL(sport.at("amount").AsInt(), 12000);
//
//    Node transport(map<string, Node>{{"category", Node("transport")}, {"amount", Node(1150)}});
//    Node array_node(vector<Node>{transport});
//    ASSERT_EQUAL(array_node.AsArray().size(), 1u);
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, TestJsonLibrary);
//    RUN_TEST(tr, TestLoadFromJson);
//}
