#include "database.h"

#include <algorithm>
#include <iostream>

void Database::Add(const Date& date, const string& event) {
    if (events[date].find(event) == events[date].end()) {
        events[date].insert(event);
        db[date].push_back(event);
    }
}

void Database::Print(std::ostream& stream) const {
    for (auto it : db) {
        for (auto const& event : it.second) {
            stream << it.first << " " << event << endl;
        }
    }
}

pair<Date, string> Database::Last(const Date& date) const {
    if (db.empty()) {
        throw std::invalid_argument("No entries");
    }
    
    auto it = db.lower_bound(date);
    
    if (it == db.begin() && date < it->first) {
        throw std::invalid_argument("No entries");
    }
    
    if (it == db.end() || it->first != date) {
        it = prev(it);
    }
    
    return make_pair(it->first, it->second.back());
}
