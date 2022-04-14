#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
    using Shape::Shape;
public:
    Circle() = delete;
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle(Circle&& other) noexcept = default;
    Circle& operator=(Circle&) = default;
    Circle& operator=(Circle&&) noexcept = default;

    virtual double getArea() const noexcept override;
    virtual double getPerimeter() const noexcept override;
    virtual void print() const override;

    double getRadius() const noexcept;
    [[deprecated]]
    double getPi() const;
private:
    double r_ = 0.0;
};
