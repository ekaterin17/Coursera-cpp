#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

class Date {
public: 
    Date(const int& year_, const int& month_, const int& day_)
    : year(year_)
    , month(month_)
    , day(day_) {}

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& is);

ostream& operator << (ostream& outStream, const Date& date);

bool operator < (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator > (const Date& lhs, const Date& rhs);
bool operator >= (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
