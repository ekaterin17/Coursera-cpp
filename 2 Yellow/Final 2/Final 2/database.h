#pragma once
#include "date.h"

#include <map>
#include <set>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& events);

    void Print(ostream& stream) const;
    
    template <typename Predicate>
    int RemoveIf(Predicate p) {
        int cnt = 0;
        vector<Date> clean;
        for (auto& it: db) {
            auto it2 = stable_partition(it.second.begin(), it.second.end(), [&] (const string& event) {
                return !p(it.first, event);
            });

            for (auto it3 = it2; it3 != it.second.end(); ++it3) {
                events[it.first].erase(*it3);
                ++cnt;
            }

            it.second.erase(it2, it.second.end());
            if (it.second.empty()) {
                clean.push_back(it.first);
            }

        }
        
        for (const auto& date: clean) {
            db.erase(date);
            events.erase(date);
        }
        
        return cnt;
    }
    
    template <typename Predicate>
    vector<pair<Date, string>> FindIf(Predicate p) const {
        vector<pair<Date, string>> res;
        for (auto it: db) {
            for (const auto& event: it.second) {
                if (p(it.first, event)) {
                    res.push_back(make_pair(it.first, event));
                }
            }
        }
        return res;
    }
    
    pair<Date, string> Last(const Date& date) const;

private:
    map<Date, vector<string>> db;
    map<Date, set<string>> events;
};

template <typename T1, typename T2>
ostream& operator << (ostream& stream, const pair<T1, T2>& pair) {
    stream << pair.first << ' ' << pair.second;
    return stream;
}
