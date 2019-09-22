#include "node.h"

bool DateComparisonNode::Evaluate(const Date &date, const string &event) const {
    return compare(comparison_, date, date_);
}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) const {
    return compare(comparison_, event, event_);
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    switch(op_) {
        case LogicalOperation::Or:
            return left_->Evaluate(date, event) || right_->Evaluate(date, event);
            
        case LogicalOperation::And:
            return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    }
    
    throw invalid_argument("Invalid logical operation");
}
