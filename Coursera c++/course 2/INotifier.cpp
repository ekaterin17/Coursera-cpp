//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void SendSms(const string& number, const string& message) {
//    cout << "Send '" << message << "' to number " << number << endl;
//}
//
//void SendEmail(const string& email, const string& message) {
//    cout << "Send '" << message << "' to e-mail "  << email << endl;
//}
//
///*
// Реализуйте здесь классы INotifier, SmsNotifier, EmailNotifier
// */
//class INotifier {
//public:
//    INotifier(const string& address_)
//    :address(address_) {}
//    
//    virtual void Notify(const string& message) const = 0;
//    
//protected:
//    const string address;
//};
//
//class SmsNotifier : public INotifier {
//public:
//    SmsNotifier(const string& number): INotifier(number) {}
//    void Notify(const string& message) const {
//        SendSms(address, message);
//    }
//};
//
//class EmailNotifier : public INotifier {
//public:
//    EmailNotifier(const string& email): INotifier(email) {}
//    void Notify(const string& message) const {
//        SendEmail(address, message);
//    }
//};
//
//void Notify(INotifier& notifier, const string& message) {
//    notifier.Notify(message);
//}
//
//
//int main() {
//    SmsNotifier sms{"+7-495-777-77-77"};
//    EmailNotifier email{"na-derevnyu@dedushke.ru"};
//    
//    Notify(sms, "I have White belt in C++");
//    Notify(email, "And want a Yellow one");
//    return 0;
//}
