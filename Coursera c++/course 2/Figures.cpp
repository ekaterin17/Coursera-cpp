//#include <cmath>
//#include <iomanip>
//#include <iostream>
//#include <memory>
//#include <vector>
//#include <sstream>
//#include <string>
//
//using namespace std;
//
//class Figure {
//public:
//    virtual string Name() const = 0;
//    virtual double Perimeter() const = 0;
//    virtual double Area() const = 0;
//};
//
//class Rect : public Figure {
//public:
//    Rect(const int& width_, const int& height_)
//    : width(width_)
//    , height(height_){}
//    
//    string Name() const override {
//        return "RECT";
//    }
//    
//    double Perimeter() const override {
//        return 2*(width + height);
//    }
//    
//    double Area() const override {
//        return width * height;
//    }
//    
//private:
//    double width;
//    double height;
//};
//
//class Triangle : public Figure {
//public:
//    Triangle(const int& a_, const int& b_, const int& c_)
//    : a(a_)
//    , b(b_)
//    , c(c_){}
//    
//    string Name() const override {
//        return "TRIANGLE";
//    }
//    
//    double Perimeter() const override {
//        return a + b + c;
//    }
//    
//    double Area() const override {
//        double p = Perimeter() / 2.0;
//        return sqrt(p * (p - a) * (p - b) * (p - c));
//    }
//    
//private:
//    double a, b, c;
//};
//
//class Circle : public Figure {
//public:
//    Circle(const int& radius_)
//    : radius(radius_){}
//    
//    string Name() const override {
//        return "CIRCLE";
//    }
//    
//    double Perimeter() const override {
//        return 2 * pi * radius;
//    }
//    
//    double Area() const override {
//        return pi * radius * radius;
//    }
//    
//private:
//    const double pi = 3.14;
//    double radius;
//};
//
//shared_ptr<Figure> CreateFigure(istream& inputStream) {
//    string figure;
//    inputStream >> figure;
//    
//    if (figure == "RECT") {
//        int width, height;
//        inputStream >> width >> height;
//        return make_shared<Rect>(width, height);
//    } else if (figure == "TRIANGLE") {
//        int a, b, c;
//        inputStream >> a >> b >> c;
//        return make_shared<Triangle>(a,b,c);
//    } else {
//        int radius;
//        inputStream >> radius;
//        return make_shared<Circle>(radius);
//    }
//}
//
//int main() {
//    vector<shared_ptr<Figure>> figures;
//    for (string line; getline(cin, line); ) {
//        istringstream is(line);
//        
//        string command;
//        is >> command;
//        if (command == "ADD") {
//            figures.push_back(CreateFigure(is));
//        } else if (command == "PRINT") {
//            for (const auto& current_figure : figures) {
//                cout << fixed << setprecision(3)
//                << current_figure->Name() << " "
//                << current_figure->Perimeter() << " "
//                << current_figure->Area() << endl;
//            }
//        }
//    }
//    return 0;
//}
