#pragma once

enum class Color : unsigned char {
    Red,
    Green,
    Blue,
    None
};

class Shape
{
public:
    Shape() = default;
    explicit Shape(Color c) : color(c) {}
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
private:
    Color color = Color::None;
};
