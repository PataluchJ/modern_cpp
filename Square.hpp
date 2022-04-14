#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square() = delete;
    Square(double x);
    Square(const Square & other) = default;
    Square(Square&& other) noexcept = default;
    Square& operator=(Square&) = default;
    Square& operator=(Square&&) noexcept = default;

    virtual double getArea() const noexcept override;
    virtual double getPerimeter() const noexcept override;
    virtual void print() const override;


private:
    double getY() = delete; // should not have Y dimension
};
