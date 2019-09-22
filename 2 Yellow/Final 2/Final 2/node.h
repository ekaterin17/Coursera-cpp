#pragma once

#include "date.h"

#include <memory>
#include <string>

using namespace std;

enum Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum LogicalOperation {
    Or,
    And
};

template<typename T>
bool compare(Comparison cmp, const T& a, const T& b) {
    switch (cmp) {
        case Comparison::Less:
            return a < b;
            
        case Comparison::LessOrEqual:
            return a <= b;
            
        case Comparison::Greater:
            return a > b;
            
        case Comparison::GreaterOrEqual:
            return a >= b;
            
        case Comparison::Equal:
            return a == b;
            
        case Comparison::NotEqual:
            return a != b;
    }
}

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
    EmptyNode() {}
    
    bool Evaluate(const Date& date, const string& event) const override {
        return true;
    }
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& cmp, const Date& date)
    : comparison_(cmp)
    , date_(date) {}
    
    bool Evaluate(const Date& date, const string& event) const override;
    
private:
    const Comparison comparison_;
    const Date date_;
};

class EventComparisonNode  : public Node {
public:
    EventComparisonNode(const Comparison& cmp, const string& event)
    : comparison_(cmp)
    , event_(event) {}
    
    bool Evaluate(const Date& date, const string& event) const override;
    
private:
    const Comparison comparison_;
    const string event_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right)
    : op_(op)
    , left_(left)
    , right_(right) {}
    
    bool Evaluate(const Date& date, const std::string& event) const override;
private:
    const LogicalOperation op_;
    const shared_ptr<Node> left_;
    const shared_ptr<Node> right_;
};
