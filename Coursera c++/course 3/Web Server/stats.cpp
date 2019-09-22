//
//  stats.cpp
//  Coursera c++
//
//  Created by Екатерина Кузина on 10/08/2019.
//  Copyright © 2019 Екатерина Кузина. All rights reserved.
//

#include "stats.h"

void Stats::AddMethod(string_view method) {
    if (method_count.find(method) != method_count.end()) {
        method_count[method]++;
    } else {
        method_count["UNKNOWN"]++;
    }
}

void Stats::AddUri(string_view uri) {
    if (uri_count.find(uri) != uri_count.end()) {
        uri_count[uri]++;
    } else {
        uri_count["unknown"]++;
    }
}

const map<string_view, int>&  Stats::GetMethodStats() const {
    return method_count;
}

const map<string_view, int>&  Stats::GetUriStats() const {
    return uri_count;
}

HttpRequest ParseRequest(string_view line) {
    HttpRequest request;
    
    size_t space = 0;
    while (space != line.npos && line[space] == ' ') {
        ++space;
    }
    line.remove_prefix(space);
    
    space = line.find(' ');
    request.method = line.substr(0, space);
    line.remove_prefix(++space);
    
    space = line.find(' ');
    request.uri = line.substr(0, space);
    line.remove_prefix(++space);

    request.protocol = line;
    
    return request;
}
