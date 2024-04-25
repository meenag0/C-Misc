/*
DOCUMENTATION

Program Purpose:
    - This program defines a hierarchy of geometric shapes including Circle, Rectangle, and Triangle.
    - It calculates and displays the area, circumference, and bounding box of each shape.
    - Error handling is implemented for invalid shapes.

Compile: g++ -o ShapeHierarchy ShapeHierarchy.cpp

Execution: ./ShapeHierarchy

Notes:
    - The program utilizes inheritance to create a hierarchy of geometric shapes.
    - Virtual functions are used to calculate the area, circumference, and bounding box of each shape.
    - Error handling is implemented to handle invalid shapes.

Classes:
    - Point:
        - Represents a point in 2D space.
        - Data members: float x, y (coordinates of the point)
        - Member functions: show(), getX(), getY(), add(), subtract()

    - Shape:
        - Abstract base class representing a geometric shape.
        - Virtual functions: calculateArea(), calculateCircumference(), isValidShape(), boundingBox(), display()

    - Circle:
        - Derived class from Shape representing a circle.
        - Data members: Point center, float radius
        - Overrides: calculateArea(), calculateCircumference(), isValidShape(), boundingBox(), display()

    - Rectangle:
        - Derived class from Shape representing a rectangle.
        - Data members: four Points (topLeft, topRight, bottomRight, bottomLeft)
        - Overrides: calculateArea(), calculateCircumference(), isValidShape(), boundingBox(), display()

    - Triangle:
        - Derived class from Shape representing a triangle.
        - Data members: three Points (p1, p2, p3)
        - Overrides: calculateArea(), calculateCircumference(), isValidShape(), boundingBox(), display()

Functions:
    - void Point::show()
        Purpose: Display the coordinates of the point.
        Parameters: None
        Returns: None

    - float Point::getX()
        Purpose: Get the x-coordinate of the point.
        Parameters: None
        Returns: float (x-coordinate)

    - float Point::getY()
        Purpose: Get the y-coordinate of the point.
        Parameters: None
        Returns: float (y-coordinate)

    - Point Point::add(const Point& p)
        Purpose: Add two points.
        Parameters: const Point& p (point to be added)
        Returns: Point (result of addition)

    - Point Point::subtract(const Point& p)
        Purpose: Subtract one point from another.
        Parameters: const Point& p (point to be subtracted)
        Returns: Point (result of subtraction)

    - float Shape::calculateArea()
        Purpose: Calculate the area of the shape.
        Parameters: None
        Returns: float (area of the shape)

    - float Shape::calculateCircumference()
        Purpose: Calculate the circumference of the shape.
        Parameters: None
        Returns: float (circumference of the shape)

    - bool Shape::isValidShape()
        Purpose: Check if the shape is valid.
        Parameters: None
        Returns: bool (true if shape is valid, false otherwise)

    - void Shape::boundingBox(Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft)
        Purpose: Calculate the bounding box of the shape.
        Parameters: Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft (output parameters for bounding box)
        Returns: None

    - void Shape::display()
        Purpose: Display information about the shape (area, circumference, bounding box).
        Parameters: None
        Returns: None

    - float Circle::calculateArea()
        Purpose: Calculate the area of the circle.
        Parameters: None
        Returns: float (area of the circle)

    - float Circle::calculateCircumference()
        Purpose: Calculate the circumference of the circle.
        Parameters: None
        Returns: float (circumference of the circle)

    - bool Circle::isValidShape()
        Purpose: Check if the circle is valid (radius > 0).
        Parameters: None
        Returns: bool (true if circle is valid, false otherwise)

    - void Circle::boundingBox(Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft)
        Purpose: Calculate the bounding box of the circle.
        Parameters: Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft (output parameters for bounding box)
        Returns: None

    - void Circle::display()
        Purpose: Display information about the circle (center, radius, area, circumference, bounding box).
        Parameters: None
        Returns: None

    - float Rectangle::calculateArea()
        Purpose: Calculate the area of the rectangle.
        Parameters: None
        Returns: float (area of the rectangle)

    - float Rectangle::calculateCircumference()
        Purpose: Calculate the circumference of the rectangle.
        Parameters: None
        Returns: float (circumference of the rectangle)

    - bool Rectangle::isValidShape()
        Purpose: Check if the rectangle is valid.
        Parameters: None
        Returns: bool (true if rectangle is valid, false otherwise)

    - void Rectangle::boundingBox(Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft)
        Purpose: Calculate the bounding box of the rectangle.
        Parameters: Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft (output parameters for bounding box)
        Returns: None

    - void Rectangle::display()
        Purpose: Display information about the rectangle (corner points, area, circumference, bounding box).
        Parameters: None
        Returns: None

    - float Triangle::calculateArea()
        Purpose: Calculate the area of the triangle.
        Parameters: None
        Returns: float (area of the triangle)

    - float Triangle::calculateCircumference()
        Purpose: Calculate the circumference of the triangle.
        Parameters: None
        Returns: float (circumference of the triangle)

    - bool Triangle::isValidShape()
        Purpose: Check if the triangle is valid.
        Parameters: None
        Returns: bool (true if triangle is valid, false otherwise)

    - void Triangle::boundingBox(Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft)
        Purpose: Calculate the bounding box of the triangle.
        Parameters: Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft (output parameters for bounding box)
        Returns: None

    - void Triangle::display()
        Purpose: Display information about the triangle (corner points, area, circumference, bounding box).
        Parameters: None
        Returns: None

TEST PLAN

Test 1:
    Description: Testing Circle behavior
    Scenario:
        - Create a Circle object with radius 5 and center at (0, 0).
        - Call display function.
    Expected Output:
        Circle
        Center: (0, 0)
        Radius: 5
        Area: 78.5398
        Circumference: 31.4159
        Bounding Box: (-5, -5) , (5, -5) , (5, 5) , (-5, 5)

Test 2:
    Description: Testing invalid Circle
    Scenario:
        - Create a Circle object with negative radius.
        - Call display function.
    Expected Output:
        Invalid circle! Radius must be greater than 0.

Test 3:
    Description: Testing Rectangle behavior
    Scenario:
        - Create a Rectangle object with corner points (-2, 7), (3, 2), (3, -3), (-2, -3).
        - Call display function.
    Expected Output:
        Rectangle
        Top-Left: (-2, 7)
        Top-Right: (3, 2)
        Bottom-Right: (3, -3)
        Bottom-Left: (-2, -3)
        Area: 40
        Circumference: 30
        Bounding Box: (-2, -3) , (3, -3) , (3, 7) , (-2, 7)

Test 4:
    Description: Testing invalid Rectangle
    Scenario:
        - Create a Rectangle object with invalid corner points.
        - Call display function.
    Expected Output:
        Invalid rectangle! Top-left point should have smaller x and larger y coordinates than bottom-right point.

Test 5:
    Description: Testing Square behavior
    Scenario:
        - Create a Rectangle object with corner points (0, 0), (2, 0), (2, -2), (0, -2).
        - Call display function.
    Expected Output:
        Rectangle
        Top-Left: (0, 0)
        Top-Right: (2, 0)
        Bottom-Right: (2, -2)
        Bottom-Left: (0, -2)
        This is a square.
        Area: 4
        Circumference: 8
        Bounding Box: (0, -2) , (2, -2) , (2, 0) , (0, 0)

Test 6:
    Description: Testing Triangle behavior
    Scenario:
        - Create a Triangle object with corner points (0, 0), (0, 3), (4, 0).
        - Call display function.
    Expected Output:
        Triangle
        Point 1: (0, 0)
        Point 2: (0, 3)
        Point 3: (4, 0)
        Area: 6
        Circumference: 12
        Bounding Box: (0, 0) , (4, 0) , (4, 3) , (0, 3)

Test 7:
    Description: Testing invalid Triangle
    Scenario:
        - Create a Triangle object with colinear points.
        - Call display function.
    Expected Output:
        Invalid triangle! Cannot create a triangle with colinear points.

Test 8:
    Description: Testing invalid Triangle
    Scenario:
        - Create a Triangle object with zero-length side.
        - Call display function.
    Expected Output:
        Invalid triangle! Cannot create a triangle with a side of zero length.
*/



#include <iostream>
#include <cmath>
using namespace std;

// Class representing a point in 2D space
class Point {
    float x, y;

public:
    // Constructor with default arguments
    Point(float x = 0, float y = 0) : x(x), y(y) {}

    // Display the point coordinates
    void show() const {
        cout << "(" << x << ", " << y << ")";
    }

    // Getter functions for x and y coordinates
    float getX() const { return x; }
    float getY() const { return y; }

    // Add two points
    Point add(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // Subtract one point from another
    Point subtract(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
};

// Abstract base class representing a geometric shape
class Shape {
public:
    // Virtual function to calculate the area of the shape
    virtual float calculateArea() const {
        return 0;
    }

    // Virtual function to calculate the circumference of the shape
    virtual float calculateCircumference() const {
        return 0;
    }

    // Virtual function to check if the shape is valid
    virtual bool isValidShape() const {
        return true;
    }

    // Virtual function to calculate the bounding box of the shape
    virtual void boundingBox(Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft) const {}

    // Virtual destructor
    virtual ~Shape() {}

    // Virtual function to display information about the shape
    virtual void display() const {
        cout << "Area: " << calculateArea() << endl;
        cout << "Circumference: " << calculateCircumference() << endl;
        cout << "Bounding Box: ";
        Point topLeft, topRight, bottomRight, bottomLeft;
        boundingBox(topLeft, topRight, bottomRight, bottomLeft);
        topLeft.show();
        cout << " , ";
        topRight.show();
        cout << " , ";
        bottomRight.show();
        cout << " , ";
        bottomLeft.show();
        cout << endl;
    }
};

// Class representing a circle, derived from Shape
class Circle : public Shape {
    Point center;
    float radius;

public:
    // Constructors
    Circle() : center(Point()), radius(0) {}

    Circle(Point center, float radius) : center(center), radius(radius) {
        if (radius <= 0) {
            cout << "Invalid circle! Radius must be greater than 0. \n" << endl;
            return;
        }
    }

    // Calculate area of the circle
    float calculateArea() const override {
        return M_PI * radius * radius;
    }

    // Calculate circumference of the circle
    float calculateCircumference() const override {
        return 2 * M_PI * radius;
    }

    // Calculate bounding box of the circle
    void boundingBox(Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft) const override {
        topLeft = center.subtract(Point(radius, radius));
        topRight = center.add(Point(radius, -radius));
        bottomRight = center.add(Point(radius, radius));
        bottomLeft = center.subtract(Point(radius, -radius));
    }

    // Check if the circle is a valid shape
    bool isValidShape() const override {
        return radius > 0;
    }

    // Display information about the circle
    void display() const override {
        cout << "Circle" << endl;
        cout << "Center: ";
        center.show();
        cout << endl;
        cout << "Radius: " << radius << endl;
        Shape::display();
    }
};

// Class representing a rectangle, derived from Shape
class Rectangle : public Shape {
private:
    Point topLeft, topRight, bottomRight, bottomLeft;
    bool valid;

public:
    // Constructors
    Rectangle() : topLeft(Point()), topRight(Point()), bottomRight(Point()), bottomLeft(Point()), valid(false) {}

    Rectangle(Point tl, Point tr, Point br, Point bl) : topLeft(tl), topRight(tr), bottomRight(br), bottomLeft(bl), valid(true) {
        if (fabs(tr.getX() - tl.getX()) != fabs(br.getX() - bl.getX()) ||
            fabs(tl.getY() - bl.getY()) != fabs(tr.getY() - br.getY())) {
            cout << "Not a rectangle! Opposite sides are not equal." << endl;
            valid = false;
            return; // Exit constructor if error occurs
        }
    }

    // Check if the rectangle is a square
    bool isSquare() const {
        float width = topRight.getX() - topLeft.getX();
        float height = topLeft.getY() - bottomLeft.getY();
        return width == height;
    }

    // Calculate area of the rectangle
    float calculateArea() const override {
        if (!valid)
            return 0;
        return fabs(bottomRight.getX() - topLeft.getX()) * fabs(topLeft.getY() - bottomRight.getY());
    }

    // Calculate circumference of the rectangle
    float calculateCircumference() const override {
        if (!valid)
            return 0;
        return 2 * (fabs(bottomRight.getX() - topLeft.getX()) + fabs(topLeft.getY() - bottomRight.getY()));
    }

    // Calculate bounding box of the rectangle
    void boundingBox(Point& tl, Point& tr, Point& br, Point& bl) const override {
        if (!valid)
            return;
        tl = topLeft;
        tr = topRight;
        br = bottomRight;
        bl = bottomLeft;
    }

    // Check if the rectangle is a valid shape
    bool isValidShape() const override {
        return valid;
    }

    // Display information about the rectangle
    void display() const override {
        if (isValidShape()) {
            cout << "Rectangle" << endl;
            cout << "Top-Left: ";
            topLeft.show();
            cout << endl;
            cout << "Top-Right: ";
            topRight.show();
            cout << endl;
            cout << "Bottom-Right: ";
            bottomRight.show();
            cout << endl;
            cout << "Bottom-Left: ";
            bottomLeft.show();
            cout << endl;
            if (isSquare()) {
                cout << "This is a square." << endl;
            }
            Shape::display(); // Call Shape::display() only if the shape is valid
        }
    }
};

// Class representing a triangle, derived from Shape
class Triangle : public Shape {
private:
    Point p1, p2, p3;

public:
    // Constructors
    Triangle() : p1(Point()), p2(Point()), p3(Point()) {}

    Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {
        // Check for sides with zero length
        if ((p1.getX() == p2.getX() && p1.getY() == p2.getY()) ||
            (p2.getX() == p3.getX() && p2.getY() == p3.getY()) ||
            (p1.getX() == p3.getX() && p1.getY() == p3.getY())) {
            cout << "Invalid triangle! Cannot create a triangle with a side of zero length. \n" << endl;
            return; // Exit constructor if error occurs
        }

        // Check for colinear points
        float crossProduct = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p3.getX() - p1.getX()) * (p2.getY() - p1.getY());
        if (fabs(crossProduct) < 1e-6) {
            cout << "Invalid triangle! Cannot create a triangle with colinear points." << endl;
            return; // Exit constructor if error occurs
        }
    }

    // Calculate area of the triangle
    float calculateArea() const override {
        float s = calculateCircumference() / 2;
        float a = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
        float b = sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p2.getY(), 2));
        float c = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Calculate circumference of the triangle
    float calculateCircumference() const override {
        float a = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
        float b = sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p2.getY(), 2));
        float c = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
        return a + b + c;
    }

    // Calculate bounding box of the triangle
    void boundingBox(Point& tl, Point& tr, Point& br, Point& bl) const override {
        float minX = min(min(p1.getX(), p2.getX()), p3.getX());
        float minY = min(min(p1.getY(), p2.getY()), p3.getY());
        float maxX = max(max(p1.getX(), p2.getX()), p3.getX());
        float maxY = max(max(p1.getY(), p2.getY()), p3.getY());
        tl = Point(minX, minY);
        tr = Point(maxX, minY);
        br = Point(maxX, maxY);
        bl = Point(minX, maxY);
    }

    // Check if the triangle is a valid shape
    bool isValidShape() const override {
        return true;
    }

    // Display information about the triangle
    void display() const override {
        cout << "Triangle" << endl;
        cout << "Point 1: ";
        p1.show();
        cout << endl;
        cout << "Point 2: ";
        p2.show();
        cout << endl;
        cout << "Point 3: ";
        p3.show();
        cout << endl;
        Shape::display();
    }
};

// Main function
int main() {
    cout << "Circle: " << endl;
    // Valid circle
    Circle c(Point(0, 0), 5);
    c.display();
    cout << endl;
    cout << endl;

    cout << "Invalid Circle: " << endl;
    // Invalid circle with negative radius (error handling demonstrated)
    Circle invalid_c(Point(1, 1), -2);
    cout << endl;

    cout << "Invalid Rectangle 1: " << endl;
    // Valid rectangle
    Rectangle r(Point(-2, 7), Point(3, 2), Point(3, -3), Point(-2, -3));
    r.display();
    cout << endl;
    cout << endl;

    cout << "Invalid Rectangle 2: " << endl;
    // Invalid rectangle with top-left point having larger x or smaller y than bottom-right (error handling demonstrated)
    Rectangle invalid_r(Point(0, 2), Point(0, 2), Point(0, -3), Point(0, -3));
    cout << endl;

    cout << "Rectangle: " << endl;
    // Invalid rectangle with top-left point having larger x or smaller y than bottom-right (error handling demonstrated)
    Rectangle valid_r(Point(0, 0), Point(4, 0), Point(4, -2), Point(0, -2));
    cout << endl;
    cout << endl;


    cout << "Square: " << endl;
    // Square rectangle (special case)
    Rectangle square_r(Point(0, 0), Point(2, 0), Point(2, -2), Point(0, -2));
    square_r.display();
    cout << endl;
    cout << endl;

    cout << "Triangle: " << endl;
    // Valid triangle
    Triangle t(Point(0, 0), Point(0, 3), Point(4, 0));
    t.display();
    cout << endl;
    cout << endl;

    cout << "Invalid Triangle: " << endl;
    // Invalid triangle with zero-length side (error handling demonstrated)
    Triangle invalid_t1(Point(0, 0), Point(0, 0), Point(1, 0));
    cout << endl;

    return 0;
}
