#include "search_server.h"
#include "iterator_range.h"

#include <algorithm>
#include <future>
#include <iterator>
#include <sstream>
#include <iostream>
#include <numeric>
#include <queue>

string_view ReadToken(string_view& line) {
    while (!line.empty() && line[0] == ' ') {
        line.remove_prefix(1);
    }
    size_t space = line.find(' ');
    string_view word = line.substr(0, space);
    line.remove_prefix(space == line.npos ? line.size() : space);
    return word;
}

vector<string_view> SplitIntoWords(string_view line) {
    vector<string_view> words;
    for (string_view word = ReadToken(line); !word.empty() ; word = ReadToken(line)) {
        words.push_back(word);
    }
    return words;
}

SearchServer::SearchServer(istream& document_input) {
  UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
    /*future<InvertedIndex> new_inverted_index;
    new_inverted_index = async([&] {
        return InvertedIndex{document_input};
    });
    Synchronized<InvertedIndex> new_index(new_inverted_index.get());
    index = move(new_index);*/
    index = InvertedIndex{document_input};
    
}

void SearchServer::AddQueriesStream(istream& query_input, ostream& search_results_output) {
    vector<future<string> > requests;
    for (string current_query; getline(query_input, current_query); ) {
        requests.push_back(async([=] {
            return AddQuerieStream(current_query);
        }));
    }
    
    for (auto& request : requests) {
        search_results_output << request.get();
    }
    
    /*vector<size_t> docid_count(index.GetDocuments().size());
    vector<int64_t> docids(index.GetDocuments().size());
    
    for (string current_query; getline(query_input, current_query); ) {
        const auto words = SplitIntoWords(current_query);
        docid_count.assign(docid_count.size(), 0);
        for (const auto& word : words) {
            for (const auto& [docid, count] : index.Lookup(word)) {
                docid_count[docid] += count;
            }
        }
    
        iota(docids.begin(), docids.end(), 0);
        partial_sort(docids.begin(), Head(docids, 5).end(), docids.end(),
                     [&docid_count](int64_t lhs, int64_t rhs) {
                         return make_pair(docid_count[lhs], -lhs) > make_pair(docid_count[rhs], -rhs);
                    });

        search_results_output << current_query << ':';
        for (size_t docid : Head(docids, 5)) {
            const size_t hit_count = docid_count[docid];
            if (hit_count == 0) {
                break;
            }
            search_results_output << " {"
            << "docid: " << docid << ", "
            << "hitcount: " << hit_count << '}';
        }
        search_results_output << '\n';
  }*/
      
}

string SearchServer::AddQuerieStream(string current_query) {
    vector<size_t> docid_count(index.GetDocuments().size(),0);
    vector<int64_t> docids(index.GetDocuments().size(),0);
    const auto words = SplitIntoWords(current_query);
    for (const auto& word : words) {
        for (const auto& [docid, count] : index.Lookup(word)) {
            docid_count[docid] += count;
        }
    }
    
    iota(docids.begin(), docids.end(), 0);
    partial_sort(docids.begin(), Head(docids, 5).end(), docids.end(),
                    [&docid_count](int64_t lhs, int64_t rhs) {
                        return make_pair(docid_count[lhs], -lhs) > make_pair(docid_count[rhs], -rhs);
                    });
    
    ostringstream search_results_output;
    search_results_output << current_query << ':';
    for (size_t docid : Head(docids, 5)) {
        const size_t hit_count = docid_count[docid];
        if (hit_count == 0) {
            break;
        }
        search_results_output << " {"
        << "docid: " << docid << ", "
        << "hitcount: " << hit_count << '}';
    }
    search_results_output << '\n';
    return search_results_output.str();
}

//////////////////////////////////////////////////////////////

InvertedIndex::InvertedIndex(istream& stream) {
    for (string current_document; getline(stream, current_document);) {
        docs.push_back(move(current_document));
        
        const size_t docid = docs.size() - 1;
        for (string_view word : SplitIntoWords(docs.back())) {
            auto& ids = index[word];
            if (!ids.empty() && ids.back().docid == docid) {
                ids.back().count++;
            } else {
                ids.push_back({docid, 1});
            }
        }
    }
}

const vector<Entry>& InvertedIndex::Lookup(string_view word) const {
    static vector<Entry> result;
    if (auto it = index.find(word); it != index.end()) {
        return it->second;
    } else {
        return result;
    }
}
