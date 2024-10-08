#include <iostream>

class Shape {
public:
    virtual double area() const = 0;        // Pure virtual function
    virtual double perimeter() const = 0;   // Pure virtual function
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double area() const override {
        // Using Heron's formula to calculate the area of a triangle
        double s = (side1 + side2 + side3) / 2;
        return (s * (s - side1) * (s - side2) * (s - side3))*(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    // Example usage
    Rectangle rectangle(4.0, 5.0);
    Triangle triangle(3.0, 4.0, 5.0);

    std::cout << "Rectangle - Area: " << rectangle.area() << ", Perimeter: " << rectangle.perimeter() << std::endl;
    std::cout << "Triangle - Area: " << triangle.area() << ", Perimeter: " << triangle.perimeter() << std::endl;

    return 0;
}
