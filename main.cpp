#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <functional>

#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

void printCollectionElements(const Collection& collection)
{
    for(const auto& it: collection)
        if(it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for(const auto& it : collection)
        if(it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr uint64_t fib(uint64_t n){
    if(n == 0 || n == 1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

template<class DerivedType, class... Arguments>
    std::shared_ptr<Shape> make_shape(Arguments&&... args)
    {
        return make_shared<DerivedType>(std::forward<Arguments>(args)...);
    }

int main()
{
    auto v = fib(45);
    std::cout << "Fib(45) = " << v << "\n";
    Collection shapes = {
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
        make_shared<Circle>(Color::Red),
        make_shared<Rectangle>(Color::Green)
    };

    auto p1 = make_shape<Circle>(5.5);
    auto p2 = make_shape<Rectangle>(9.0, 8.0);
    shapes.push_back(std::move(p1));
    shapes.push_back(std::move(p2));


    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), 
        [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
            if(first == nullptr || second == nullptr)
                return false;
            return (first->getArea() < second->getArea());
        }
    );

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, 
        [](shared_ptr<Shape> s ){
            if(s)
                return (s->getPerimeter() > 20);
            return false;
        },
        "perimeter bigger than 20");
    /*std::function<bool(shared_ptr<Shape>)> lessThanX = [x = 10](shared_ptr<Shape> s) {
        if(s)
            return (s->getArea() < x);
        return false;
     };
*/
    std::function<bool(shared_ptr<Shape>)> areaLessThanX = [x=10](shared_ptr<Shape> s) {
    if(s)
        return (s->getArea() < x);
    return false;
};
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than X");
    return 0;
}

