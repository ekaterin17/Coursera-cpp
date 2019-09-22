//#include <algorithm>
//#include <deque>
//#include <iostream>
//#include <string>
//
//int priority(std::string operation) {
//    if (operation == "+" || operation == "-") {
//        return 1;
//    } else {
//        return 2;
//    }
//}
//
//void BuildExpression(std::deque<std::string>& expr, const std::string& operation, const int& number) {
//    expr.push_front("(");
//    expr.push_back(")");
//    expr.push_back(operation);
//    expr.push_back(std::to_string(number));
//}
//
//void BuildExpressionWithoutRedundant(std::deque<std::string>& expr, const std::string& operation, const int& number) {
//    if (expr.size() == 1 || priority(operation) <= priority(expr[expr.size()-2])) {
//        expr.push_back(operation);
//        expr.push_back(std::to_string(number));
//        return;
//    }
//    
//    expr.push_front("(");
//    expr.push_back(")");
//    expr.push_back(operation);
//    expr.push_back(std::to_string(number));
//}
//
//int main() {
//    std::string x;
//    std::cin >> x;
//    
//    std::deque<std::string> expr;
//    expr.push_back(x);
//    
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i) {
//        std::string operation;
//        int m;
//        std::cin >> operation >> m;
//        BuildExpressionWithoutRedundant(expr, operation, m);
//    }
//    
//    for (const auto& item : expr) {
//        if (item == "+" || item == "-" || item == "*" || item == "/") {
//            std::cout << " " << item << " ";
//        } else {
//            std::cout << item;
//        }
//    }
//    
//    return 0;
//}
