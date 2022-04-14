#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
    using Shape::Shape;
public:
    Rectangle() = delete;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;
    Rectangle(Rectangle&& other) noexcept = default;
    Rectangle& operator=(Rectangle&) = default;
    Rectangle& operator=(Rectangle&&) noexcept = default;

    virtual double getArea() const noexcept override;
    virtual double getPerimeter() const noexcept override;
    virtual void print() const override;
    
    virtual double getX() const noexcept final ;
    virtual double getY() const noexcept;

private:
    double x_ = 0.0;
    double y_ = 0.0;
};
