//#include <iostream>
//#include <vector>
//#include <set>
//#include <sstream>
//#include <string>
//
//using namespace std;
//
//class Learner {
//private:
//    set<string> dict;
//    
//public:
//    int Learn(const vector<string>& words) {
//        int cntBefore = (int)dict.size();
//        for (const auto& word : words) {
//            dict.insert(word);
//        }
//        return (int)dict.size() - cntBefore;
//    }
//    
//    vector<string> KnownWords() {
//        return {dict.begin(), dict.end()};
//    }
//};
//
//int main() {
//    Learner learner;
//    string line;
//    while (getline(cin, line)) {
//        vector<string> words;
//        stringstream ss(line);
//        string word;
//        while (ss >> word) {
//            words.push_back(word);
//        }
//        cout << learner.Learn(words) << "\n";
//    }
//    cout << "=== known words ===\n";
//    for (auto word : learner.KnownWords()) {
//        cout << word << "\n";
//    }
//}
