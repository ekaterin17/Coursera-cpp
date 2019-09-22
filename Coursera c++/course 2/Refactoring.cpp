//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Person {
//public:
//    Person(const string& name, const string& activity)
//    : name_(name)
//    , activity_(activity){}
//    
//    string GetName() const {
//        return name_;
//    }
//    
//    string GetActivity() const {
//        return activity_;
//    }
//    
//    virtual void Walk(const string& destination) const {
//        cout << GetActivity() << ": " << GetName() << " walks to: " << destination << endl;
//    };
//    
//protected:
//    const string name_;
//    const string activity_;
//};
//
//class Student : public Person {
//public:
//    Student(const string& name, const string& favouriteSong)
//    : Person(name, "Student")
//    , FavouriteSong(favouriteSong)
//    {}
//    
//    void Learn() const  {
//        cout << "Student: " << GetName() << " learns" << endl;
//    }
//    
//    void Walk(const string& destination) const override {
//        Person::Walk(destination);
//        SingSong();
//    }
//    
//    void SingSong() const {
//        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
//    }
//    
//private:
//    const string FavouriteSong;
//};
//
//
//class Teacher : public Person {
//public:
//    Teacher(const string& name, const string& subject)
//    : Person(name, "Teacher")
//    ,Subject(subject)
//    {}
//    
//    void Teach() const {
//        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
//    }
//    
//protected:
//    const string Subject;
//};
//
//
//class Policeman : public Person {
//public:
//    Policeman(const string& name)
//    : Person(name, "Policeman")
//    {}
//    
//    void Check(const Person& t) const {
//        cout << "Policeman: " << GetName() << " checks " << t.GetActivity() << ". "
//        <<  t.GetActivity() << "'s name is: " << t.GetName() << endl;
//    }
//};
//
//
//void VisitPlaces(const Person& person, const vector<string>& places) {
//    for (auto p : places) {
//        person.Walk(p);
//    }
//}
//
//int main() {
//    Teacher t("Jim", "Math");
//    Student s("Ann", "We will rock you");
//    Policeman p("Bob");
//    
//    VisitPlaces(t, {"Moscow", "London"});
//    p.Check(s);
//    VisitPlaces(s, {"Moscow", "London"});
//    return 0;
//}
