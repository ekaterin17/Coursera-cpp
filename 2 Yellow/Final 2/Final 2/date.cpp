#include "date.h"

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

Date ParseDate(istream& date_stream) {
    int year;
    date_stream >> year;
    date_stream.ignore(1);
    
    int month;
    date_stream >> month;
    date_stream.ignore(1);
    
    int day;
    date_stream >> day;
    date_stream.ignore(1);
    
    return Date(year, month, day);
}

ostream& operator << (ostream& outStream, const Date& date) {
    outStream << setfill('0') << setw(4);
    outStream << date.GetYear() << '-';
    outStream << setfill('0') << setw(2);
    outStream << date.GetMonth() << '-';
    outStream << setfill('0') << setw(2);
    outStream << date.GetDay();
    return outStream;
}

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear()) return true;
    if (lhs.GetYear() > rhs.GetYear()) return false;
    if (lhs.GetMonth() < rhs.GetMonth()) return true;
    if (lhs.GetMonth() > rhs.GetMonth()) return false;
    return lhs.GetDay() < rhs.GetDay();
}

bool operator <= (const Date& lhs, const Date& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator > (const Date& lhs, const Date& rhs) {
    return (lhs != rhs) && !(lhs < rhs);
}

bool operator >= (const Date& lhs, const Date& rhs) {
     return (lhs > rhs) || (lhs == rhs);
}

bool operator == (const Date& lhs, const Date& rhs) {
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth()
            && lhs.GetDay() == rhs.GetDay();
}

bool operator != (const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}
