#pragma once

#include "Synchronized.h"

#include <deque>
#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Entry {
    size_t docid;
    int count;
};

class InvertedIndex {
public:
    InvertedIndex() = default;
    explicit InvertedIndex(istream& document_input);
    const vector<Entry>& Lookup(string_view word) const;

    const deque<string>& GetDocuments() const {
        return docs;
    }
    
private:
  map<string_view, vector<Entry> > index;
  deque<string> docs;
};

class SearchServer {
public:
    SearchServer() = default;
    explicit SearchServer(istream& document_input);
    void UpdateDocumentBase(istream& document_input);
    void AddQueriesStream(istream& query_input, ostream& search_results_output);

private:
    string AddQuerieStream(string current_query);
    InvertedIndex index;
    //Synchronized<InvertedIndex> index;
};
