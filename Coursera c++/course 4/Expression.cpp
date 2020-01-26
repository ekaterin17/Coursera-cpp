//#include "Expression.h"
//#include "test_runner.h"
//
//#include <sstream>
//#include <utility>
//
//using namespace std;
//
//class ValueExpr : public Expression {
//public:
//    ValueExpr(int val)
//    : val_(val) {}
//    
//    int Evaluate() const override {
//        return val_;
//    }
//    
//    string ToString() const override {
//        return to_string(val_);
//    }
//    
//private:
//    int val_;
//};
//
//class BinaryExpr : public Expression {
//public:
//    BinaryExpr(ExpressionPtr left, ExpressionPtr right)
//    : left_(move(left))
//    , right_(move(right)) {}
//    
//    virtual int Evaluate() const = 0;
//    
//    string ToString() const final {
//        return  "(" + left_->ToString() + ")" +
//        GetOperation() +
//        "(" + right_->ToString() + ")";
//    }
//    
//private:
//    virtual string GetOperation() const = 0;
//    
//protected:
//    ExpressionPtr left_, right_;
//};
//
//class SumExpr : public BinaryExpr {
//public:
//    SumExpr(ExpressionPtr left, ExpressionPtr right)
//    : BinaryExpr(move(left), move(right)) {}
//    
//    int Evaluate() const override {
//        return left_->Evaluate() + right_->Evaluate();
//    }
//    
//private:
//    string GetOperation() const override {
//        return "+";
//    }
//};
//
//class ProductExpr : public BinaryExpr {
//public:
//    ProductExpr(ExpressionPtr left, ExpressionPtr right)
//    : BinaryExpr(move(left), move(right)) {}
//    
//    int Evaluate() const override {
//        return left_->Evaluate() * right_->Evaluate();
//    }
//    
//private:
//    string GetOperation() const override {
//        return "*";
//    }
//};
//
//ExpressionPtr Value(int value) {
//    return make_unique<ValueExpr>(value);
//}
//
//ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right) {
//    return make_unique<SumExpr>(move(left), move(right));
//}
//
//ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right) {
//    return make_unique<ProductExpr>(move(left), move(right));
//}
//
//string Print(const Expression* e) {
//    if (!e) {
//        return "Null expression provided";
//    }
//    stringstream output;
//    output << e->ToString() << " = " << e->Evaluate();
//    return output.str();
//}
//
//void Test() {
//    ExpressionPtr e1 = Product(Value(2), Sum(Value(3), Value(4)));
//    ASSERT_EQUAL(Print(e1.get()), "(2)*((3)+(4)) = 14");
//    
//    ExpressionPtr e2 = Sum(move(e1), Value(5));
//    ASSERT_EQUAL(Print(e2.get()), "((2)*((3)+(4)))+(5) = 19");
//    
//    ASSERT_EQUAL(Print(e1.get()), "Null expression provided");
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, Test);
//    return 0;
//}
