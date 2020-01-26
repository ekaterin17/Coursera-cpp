//#include "test_runner.h"
//#include <functional>
//#include <iostream>
//#include <memory>
//#include <sstream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//
//struct Email {
//    string from;
//    string to;
//    string body;
//};
//
//
//class Worker {
//public:
//    virtual ~Worker() = default;
//    virtual void Process(unique_ptr<Email> email) = 0;
//
//    virtual void Run() {
//        // только первому worker-у в пайплайне нужно это имплементировать
//        throw logic_error("Unimplemented");
//    }
//
//protected:
//    // реализации должны вызывать PassOn, чтобы передать объект дальше
//    // по цепочке обработчиков
//    void PassOn(unique_ptr<Email> email) const {
//        if (next_worker) {
//            next_worker->Process(move(email));
//        }
//    }
//
//public:
//    void SetNext(unique_ptr<Worker> next) {
//        next_worker = move(next);
//    }
//
//private:
//    unique_ptr<Worker> next_worker;
//};
//
//
//class Reader : public Worker {
//public:
//    explicit Reader(istream& in)
//    : in_(in)
//    {}
//
//    void Process(unique_ptr<Email> ) override {
//    }
//
//    void Run() override {
//        for (;;) {
//            auto email = make_unique<Email>();
//            getline(in_, email->from);
//            getline(in_, email->to);
//            getline(in_, email->body);
//            if (in_) {
//                PassOn(move(email));
//            } else {
//                break;
//            }
//        }
//    }
//
//private:
//    istream& in_;
//};
//
//
//class Filter : public Worker {
//public:
//    using Function = function<bool(const Email&)>;
//
//public:
//    explicit Filter(Function func)
//    : func_(move(func))
//    {}
//
//    void Process(unique_ptr<Email> email) override {
//        if (func_(*email)) {
//            PassOn(move(email));
//        }
//    }
//
//private:
//    Function func_;
//};
//
//
//class Copier : public Worker {
//public:
//    explicit Copier(string recipient)
//    : recipient_(move(recipient))
//    {}
//
//    void Process(unique_ptr<Email> email) override {
//        if (email->to != recipient_) {
//            auto copy = make_unique<Email>(*email);
//            copy->to = recipient_;
//            PassOn(move(email));
//            PassOn(move(copy));
//        } else {
//            PassOn(move(email));
//        }
//    }
//
//private:
//    const string recipient_;
//};
//
//
//class Sender : public Worker {
//public:
//    explicit Sender(ostream& out) : out_(out) {}
//
//    void Process(unique_ptr<Email> email) override {
//        out_ << email->from << "\n" << email->to << "\n" << email->body << "\n";
//        PassOn(move(email));
//    }
//
//private:
//    ostream& out_;
//};
//
//
//// реализуйте класс
//class PipelineBuilder {
//public:
//    // добавляет в качестве первого обработчика Reader
//    explicit PipelineBuilder(istream& in) {
//        pipeline.push_back(make_unique<Reader>(in));
//    }
//
//    // добавляет новый обработчик Filter
//    PipelineBuilder& FilterBy(Filter::Function filter) {
//        pipeline.push_back(make_unique<Filter>(move(filter)));
//        return *this;
//    }
//
//    // добавляет новый обработчик Copier
//    PipelineBuilder& CopyTo(string recipient) {
//        pipeline.push_back(make_unique<Copier>(move(recipient)));
//        return *this;
//    }
//
//    // добавляет новый обработчик Sender
//    PipelineBuilder& Send(ostream& out) {
//        pipeline.push_back(make_unique<Sender>(out));
//        return *this;
//    }
//
//    // возвращает готовую цепочку обработчиков
//    unique_ptr<Worker> Build() {
//        for (size_t i = pipeline.size(); i > 1; --i) {
//            pipeline[i-2]->SetNext(move(pipeline[i-1]));
//        }
//        return move(pipeline[0]);
//    }
//
//private:
//    vector<unique_ptr<Worker> > pipeline;
//};
//
//
//void TestSanity() {
//    string input = (
//                    "erich@example.com\n"
//                    "richard@example.com\n"
//                    "Hello there\n"
//
//                    "erich@example.com\n"
//                    "ralph@example.com\n"
//                    "Are you sure you pressed the right button?\n"
//
//                    "ralph@example.com\n"
//                    "erich@example.com\n"
//                    "I do not make mistakes of that kind\n"
//                    );
//    istringstream inStream(input);
//    ostringstream outStream;
//
//    PipelineBuilder builder(inStream);
//    builder.FilterBy([](const Email& email) {
//        return email.from == "erich@example.com";
//    });
//    builder.CopyTo("richard@example.com");
//    builder.Send(outStream);
//    auto pipeline = builder.Build();
//
//    pipeline->Run();
//
//    string expectedOutput = (
//                             "erich@example.com\n"
//                             "richard@example.com\n"
//                             "Hello there\n"
//
//                             "erich@example.com\n"
//                             "ralph@example.com\n"
//                             "Are you sure you pressed the right button?\n"
//
//                             "erich@example.com\n"
//                             "richard@example.com\n"
//                             "Are you sure you pressed the right button?\n"
//                             );
//
//    ASSERT_EQUAL(expectedOutput, outStream.str());
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, TestSanity);
//    return 0;
//}
