//#include <algorithm>
//#include <iostream>
//#include <optional>
//#include <vector>
//#include <string>
//#include <numeric>
//
//using namespace std;
//
//template <typename Iterator>
//class IteratorRange {
//public:
//    IteratorRange(Iterator begin, Iterator end)
//    : first(begin)
//    , last(end)
//    {
//    }
//    
//    Iterator begin() const {
//        return first;
//    }
//    
//    Iterator end() const {
//        return last;
//    }
//    
//private:
//    Iterator first, last;
//};
//
//template <typename Collection>
//auto Head(Collection& v, size_t top) {
//    return IteratorRange{v.begin(), next(v.begin(), min(top, v.size()))};
//}
//
//struct Person {
//    string name;
//    int age, income;
//    bool is_male;
//};
//
//vector<Person> ReadPeople(istream& input) {
//    int count;
//    input >> count;
//    
//    vector<Person> result(count);
//    for (Person& p : result) {
//        char gender;
//        input >> p.name >> p.age >> p.income >> gender;
//        p.is_male = gender == 'M';
//    }
//    
//    return result;
//}
//
//template <typename Iter>
//std::optional<string> FindMostPopularName(IteratorRange<Iter> range) {
//    if (range.begin() == range.end()) {
//        return std::nullopt;
//    } else {
//        sort(range.begin(), range.end(), [](const Person& lhs, const Person& rhs) {
//            return lhs.name < rhs.name;
//        });
//        const string* most_popular_name = &range.begin()->name;
//        int count = 1;
//        for (auto i = range.begin(); i != range.end(); ) {
//            auto same_name_end = find_if_not(i, range.end(), [i](const Person& p) {
//                return p.name == i->name;
//            });
//            const auto cur_name_count = std::distance(i, same_name_end);
//            if (
//                cur_name_count > count ||
//                (cur_name_count == count && i->name < *most_popular_name)
//                ) {
//                count = cur_name_count;
//                most_popular_name = &i->name;
//            }
//            i = same_name_end;
//        }
//        return *most_popular_name;
//    }
//}
//
//struct PersonData {
//    vector<Person> sorted_people_by_age;
//    vector<int> wealthy;
//    optional<string> most_popular_male_name;
//    optional<string> most_popular_female_name;
//};
//
//PersonData BuildData(vector<Person> people) {
//    PersonData data;
//    
//    {
//        IteratorRange males{
//            begin(people),
//            partition(begin(people), end(people), [](const Person& p) {
//                return p.is_male;
//            })
//        };
//        IteratorRange females{males.end(), end(people)};
//        
//        data.most_popular_male_name = FindMostPopularName(males);
//        data.most_popular_female_name = FindMostPopularName(females);
//    }
//    
//    {
//        data.sorted_people_by_age = people;
//        sort(data.sorted_people_by_age.begin(), data.sorted_people_by_age.end(),
//             [](const Person& lhs, const Person& rhs) {
//                 return lhs.age < rhs.age;
//             });
//    }
//    
//    {
//        sort(people.begin(), people.end(),
//             [](const Person& lhs, const Person& rhs) {
//                 return lhs.income > rhs.income;
//             });
//        data.wealthy.resize(people.size());
//        
//        if (!people.empty()) {
//            data.wealthy[0] = people[0].income;
//            for (size_t i = 1; i < data.wealthy.size(); ++i) {
//                data.wealthy[i] = data.wealthy[i-1] + people[i].income;
//            }
//        }
//    }
//    
//    return data;
//}
//
//int main() {
//    const PersonData people_data = BuildData(ReadPeople(cin));
//    
//    for (string command; cin >> command; ) {
//        if (command == "AGE") {
//            int adult_age;
//            cin >> adult_age;
//            auto adult_begin = lower_bound(
//                                           begin(people_data.sorted_people_by_age),
//                                           end(people_data.sorted_people_by_age),
//                                           adult_age,
//                                           [](const Person& lhs, int age) {
//                                               return lhs.age < age;
//                                           });
//            
//            cout << "There are " << std::distance(adult_begin, end(people_data.sorted_people_by_age))
//            << " adult people for maturity age " << adult_age << '\n';
//        } else if (command == "WEALTHY") {
//            int count;
//            cin >> count;
//            cout << "Top-" << count << " people have total income " << people_data.wealthy[count - 1] << '\n';
//        } else if (command == "POPULAR_NAME") {
//            char gender;
//            cin >> gender;
//            
//            const auto most_popular_name = gender == 'M' ? people_data.most_popular_male_name : people_data.most_popular_female_name;
//            
//            if (!most_popular_name) {
//                cout << "No people of gender " << gender << '\n';
//            } else {
//                cout << "Most popular name among people of gender " << gender << " is "
//                << *most_popular_name << '\n';
//            }
//        }
//    }
//}
