#include "Common.h"

using namespace std;

// Этот файл сдаётся на проверку
// Здесь напишите реализацию необходимых классов-потомков `IShape`

bool IsPointInSize(Point p, Size s) {
    return p.x >= 0 && p.y >= 0 && p.x < s.width && p.y < s.height;
}

Size GetImageSize(const Image& image) {
    auto width = static_cast<int>(image.empty() ? 0 : image[0].size());
    auto height = static_cast<int>(image.size());
    return {width, height};
}

class Shape : public IShape {
public:
    void SetPosition(Point pos) override {
        position = pos;
    }
    
    Point GetPosition() const override {
        return position;
    }
    
    void SetSize(Size s) override {
        size = s;
    }
    
    Size GetSize() const override {
        return size;
    }
    
    void SetTexture(std::shared_ptr<ITexture> texture_) override {
        texture = move(texture_);
    }
    
    ITexture* GetTexture() const override {
        return texture.get();
    }
    
    void Draw(Image& image) const override {
        Point p;
        auto image_size = GetImageSize(image);
        for (p.y = 0; p.y < size.height; ++p.y) {
            for (p.x = 0; p.x < size.width; ++p.x) {
                if (IsPointInShape(p)) {
                    char pixel = '.';
                    if (texture && IsPointInSize(p, texture->GetSize())) {
                        pixel = texture->GetImage()[p.y][p.x];
                    }
                    Point dp = { position.x + p.x, position.y + p.y };
                    if (IsPointInSize(dp, image_size)) {
                        image[dp.y][dp.x] = pixel;
                    }
                }
            }
        }
    }
    
    
private:
    Point position;
    Size size;
    shared_ptr<ITexture> texture;
    virtual bool IsPointInShape(Point) const = 0;
};

class Ellipse : public Shape {
public:
    std::unique_ptr<IShape> Clone() const override {
        return make_unique<Ellipse>(*this);
    }
private:
    bool IsPointInShape(Point p) const override {
        return IsPointInEllipse(p, GetSize());
    }
};

class Rectangle : public Shape {
public:
    std::unique_ptr<IShape> Clone() const override {
        return make_unique<Rectangle>(*this);
    }
private:
    bool IsPointInShape(Point) const override {
        return true;
    }
};

// Напишите реализацию функции
unique_ptr<IShape> MakeShape(ShapeType shape_type) {
    switch(shape_type){
        case ShapeType::Ellipse :
            return make_unique<Ellipse>();
        case ShapeType::Rectangle :
            return make_unique<Rectangle>();
    }
    return nullptr;
}
