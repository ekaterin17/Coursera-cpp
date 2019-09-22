//#include <algorithm>
//#include <iomanip>
//#include <iostream>
//#include <map>
//#include <ostream>
//#include <vector>
//#include <sstream>
//#include <string>
//
//class Date {
//public:
//    Date() {};
//    Date(const int& year, const int& month, const int& day) {
//        this->year = year;
//        if (!(0 < month && month < 13)) {
//            throw "Month value is invalid: " + std::to_string(month);
//        }
//        this->month = month;
//        if (!(0 < day && day < 32)) {
//            throw "Day value is invalid: " + std::to_string(day);
//        }
//        this->day = day;
//    };
//    
//    int GetYear() const {
//        return year;
//    };
//    int GetMonth() const {
//        return month;
//    };
//    int GetDay() const {
//        return day;
//    };
//    
//private:
//    int year;
//    int month;
//    int day;
//};
//
//std::string ParseNumber(std::stringstream& stream) {
//    std::string number = "";
//    if (stream.peek() == '-' || stream.peek() == '+') {
//        number += stream.peek();
//        stream.ignore(1);
//    }
//    while (isdigit(stream.peek())) {
//        number += stream.peek();
//        stream.ignore(1);
//    }
//    return number;
//}
//
//Date ParseDate(const std::string& s) {
//    std::stringstream stream(s);
//    std::string year = ParseNumber(stream);
//    if (year.size() == 0 || (year[0] == '-' || year[0] == '+') && year.size() == 1)
//        throw "Wrong date format: " + s;
//    if (stream.eof() || stream.peek() != '-') throw "Wrong date format: " + s;
//    stream.ignore(1);
//    
//    std::string month = ParseNumber(stream);
//    if (month.size() == 0 || (month[0] == '-' || month[0] == '+') && month.size() == 1)
//        throw "Wrong date format: " + s;
//    if (stream.eof() || stream.peek() != '-') throw "Wrong date format: " + s;
//    stream.ignore(1);
//    
//    std::string day = ParseNumber(stream);
//    if (day.size() == 0 || (day[0] == '-' || day[0] == '+') && day.size() == 1)
//        throw "Wrong date format: " + s;
//    if (!stream.eof()) throw "Wrong date format: " + s;
//    
//    Date date(stoi(year),stoi(month),stoi(day));
//    return date;
//}
//
//void PrintDate(const Date& date) {
//    std::cout << std::setfill('0') << std::setw(4);
//    std::cout << date.GetYear() << '-';
//    std::cout << std::setfill('0') << std::setw(2);
//    std::cout << date.GetMonth() << '-';
//    std::cout << std::setfill('0') << std::setw(2);
//    std::cout << date.GetDay();
//}
//
//bool operator < (const Date& lhs, const Date& rhs) {
//    if (lhs.GetYear() < rhs.GetYear()) return true;
//    if (lhs.GetYear() > rhs.GetYear()) return false;
//    if (lhs.GetMonth() < rhs.GetMonth()) return true;
//    if (lhs.GetMonth() > rhs.GetMonth()) return false;
//    return lhs.GetDay() < rhs.GetDay();
//}
//
//class Database {
//public:
//    void AddEvent(const Date& date, const std::string& event) {
//        if (data.count(date) == 0 || count(data[date].begin(), data[date].end(), event) == 0)
//            data[date].push_back(event);
//        sort(data[date].begin(), data[date].end());
//    }
//    
//    bool DeleteEvent(const Date& date, const std::string& event) {
//        if (data.count(date) > 0) {
//            auto it = find(data[date].begin(), data[date].end(), event);
//            if (it != data[date].end()) {
//                data[date].erase(it);
//                return true;
//            }
//        }
//        return false;
//    }
//    int DeleteDate(const Date& date) {
//        auto it = data.find(date);
//        if (it != data.end()) {
//            size_t eventsCount = it->second.size();
//            data.erase(it);
//            return (int)eventsCount;
//        }
//        return 0;
//    }
//    
//    void Find(const Date& date) const {
//        if (data.count(date) > 0) {
//            for (std::string event : data.at(date)) {
//                std::cout << event << std::endl;
//            }
//        }
//    }
//    
//    void Print() const {
//        for (auto const& date : data) {
//            for (auto const& event : date.second) {
//                PrintDate(date.first);
//                std::cout << " " << event << std::endl;
//            }
//        }
//    };
//    
//private:
//    std::map<Date,std::vector<std::string>> data;
//};
//
//int main() {
//    Database base;
//    std::string request;
//    while (getline(std::cin,request)) {
//        if (request != "") {
//            std::stringstream input(request);
//            std::string command;
//            input >> command;
//            if (command == "Add") {
//                std::string dateString, event;
//                input >> dateString >> event;
//                Date date;
//                try {
//                    date = ParseDate(dateString);
//                    base.AddEvent(date,event);
//                } catch (std::string ex) {
//                    std::cout << ex << std::endl;
//                }
//            } else if (command == "Del") {
//                std::string dateString, event;
//                input >> dateString >> event;
//                Date date;
//                try {
//                    date = ParseDate(dateString);
//                    if (event == "") {
//                        std::cout << "Deleted " << base.DeleteDate(date) << " events\n";
//                    } else {
//                        if (base.DeleteEvent(date, event)) {
//                            std::cout << "Deleted successfully\n";
//                        } else {
//                            std::cout << "Event not found\n";
//                        }
//                    }
//                } catch (std::string ex) {
//                    std::cout << ex << std::endl;
//                }
//            } else if (command == "Find") {
//                std::string dateString;
//                input >> dateString;
//                Date date;
//                try {
//                    date = ParseDate(dateString);
//                    base.Find(date);
//                } catch (std::string ex) {
//                    std::cout << ex << std::endl;
//                }
//            } else if (command == "Print") {
//                base.Print();
//            } else {
//                std::cout << "Unknown command: " << command << std::endl;
//            }
//        }
//    }
//    return 0;
//}
