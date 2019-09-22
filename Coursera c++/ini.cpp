#include "ini.h"

#include <iostream>
#include <string_view>
#include <utility>

namespace  Ini {
    namespace {
        string GetName(string_view line) {
            line.remove_prefix(1);
            line.remove_suffix(1);
            return string(line);
        }
        
        pair<string_view, string_view> Split(string_view line) {
            size_t equal = line.find('=');
            string_view key = line.substr(0, equal);
            line.remove_prefix(equal + 1);
            string_view value = line;
            return {key, value};
        }
        
        string_view RemoveFirstSpace(string_view line) {
            size_t first_letter = 0;
            while (first_letter < line.npos && line[first_letter] == ' ') {
                first_letter += 1;
            }
            line.remove_prefix(first_letter);
            return line;
        }
    }
    
    Section& Document::AddSection(string name) {
        return sections[name];
    }
    
    const Section& Document::GetSection(const string& name) const {
        return sections.at(name);
    }
    
    size_t Document::SectionCount() const {
        return sections.size();
    }
    
    Document Load(istream& input) {
        string name = "";
        Document doc;
        for (string line; getline(input,line);) {
            line = string(RemoveFirstSpace(line));
            if (line == "") continue;
            if (line[0] == '[') {
                name = GetName(line);
                doc.AddSection(name);
            } else {
                Section& new_section = doc.AddSection(name);
                auto [key, value] = Split(line);
                new_section[string(key)] = string(value);
            }
        }
        return doc;
    }
    
}
