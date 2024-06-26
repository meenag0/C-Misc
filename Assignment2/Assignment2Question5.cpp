// Assignment2Question5.cpp

/*
 Title: Assignment2Question5.cpp
 Description: A program to demonstrate features of different shapes.
 Date: April 25, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/


/*
DOCUMENTATION

Program Purpose:
    - This program defines a hierarchy of geometric shapes including Circle, Rectangle, and Triangle.
    - It calculates and displays the area, circumference, and bounding box of each shape.
    - Error handling is implemented for invalid shapes.

Compile: g++ -o // Assignment2Question5 // Assignment2Question5.cpp

Execution: ./Assignment2Question5

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
    Description: Testing Circle 
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
        Invalid circle! Radius must be greater than or equal to 0.

Test 3:
    Description: Testing Rectangle 
    Scenario:
        - Create a Rectangle object with corner points (-3, -2), (5, -2), (5, 4), (-3, 4).
        - Call display function.
    Expected Output:
        Rectangle
        Point 1: (-3, -2)
        Point 2: (5, -2)
        Point 3: (5, 4)
        Point 4: (-3, 4)
        Area: 48
        Circumference: 28
        Bounding Box: (-3, 4) , (5, 4) , (5, -2) , (-3, -2)

Test 4:
    Description: Testing Rectangle 
    Scenario:
        - Create a Rectangle object with corner points (0, 3) , (4, 3) , (4, 0) , (0, 0).
        - Call display function.
    Expected Output:
        Rectangle
        Point 1: (0, 0)
        Point 2: (4, 0)
        Point 3: (4, 3)
        Point 4: (0, 3)
        Area: 12
        Circumference: 14
        Bounding Box: (0, 3) , (4, 3) , (4, 0) , (0, 0)

Test 5:
    Description: Testing Square 
    Scenario:
        - Create a Rectangle object with corner points (0, 0) , (2, 0) , (2, -2) , (0, -2).
        - Call display function.
    Expected Output:
        Rectangle
        Point 1: (0, 0)
        Point 2: (2, 0)
        Point 3: (2, -2)
        Point 4: (0, -2)
        This is a square.
        Area: 4
        Circumference: 8
        Bounding Box: (0, 0) , (2, 0) , (2, -2) , (0, -2)

Test 6:
    Description: Testing invalid Rectangle
    Scenario:
        - Create a Rectangle object with invalid corner points.
        - Call display function.
    Expected Output:
Invalid Rectangle (Not Equal/Irregular): 
        Warning: Invalid rectangle! Opposite sides are not equal or not perpendicular.

Test 7:
    Description: Testing valid Triangle 
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

Test 8:
    Description: Testing invalid Triangle
    Scenario:
        - Create a Triangle object with zero-length side.
        - Call display function.
    Expected Output:
        Warning: Invalid triangle! Cannot create a triangle with a side of zero length or colinear points

Test 9:
    Description: Testing invalid Triangle
    Scenario:
        - Create a Triangle object with colinear points.
        - Call display function.
    Expected Output:
        Warning: Invalid triangle! Cannot create a triangle with a side of zero length or colinear points

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

// Base class representing a general shape
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

// Function to find the minimum of two float values
float min(float a, float b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

// Function to find the maximum of two float values
float max(float a, float b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

// Class representing a circle, derived from Shape
class Circle : public Shape {
private:
    Point center;
    float radius;

public:
    // Default constructor
    Circle() : center(Point()), radius(0) {}

    // Constructor with arguments
    Circle(Point center, float radius) : center(center), radius(radius) {
        if (!isValidShape()) {
            cout << "Invalid circle! Radius must be greater than or equal to 0." << endl;
        }
    }

    // Calculate area of the circle
    float calculateArea() const {
        return M_PI * radius * radius;
    }

    // Calculate circumference of the circle
    float calculateCircumference() const {
        return 2 * M_PI * radius;
    }

    // Calculate bounding box of the circle
    void boundingBox(Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft) const {
        topLeft = center.subtract(Point(radius, radius));
        topRight = center.add(Point(radius, -radius));
        bottomRight = center.add(Point(radius, radius));
        bottomLeft = center.subtract(Point(radius, -radius));
    }

    // Check if the circle is a valid shape
    bool isValidShape() const {
        return radius >= 0;
    }

    // Display information about the circle
    void display() const {
    if (isValidShape()) {
        cout << "Circle" << endl;
        cout << "Center: ";
        center.show();
        cout << endl;
        cout << "Radius: " << radius << endl;
        Shape::display(); // Call Shape::display() only if the shape is valid
    } 
    }
};


// Class representing a rectangle, derived from Shape
class Rectangle : public Shape {
private:
    Point p1, p2, p3, p4;

public:
    // Default constructor
    Rectangle() {}

    // Constructor with arguments
    Rectangle(Point p1, Point p2, Point p3, Point p4) : p1(p1), p2(p2), p3(p3), p4(p4) {
        // Check if the given points form a rectangle
        if (!isValidShape()) {
            cout << "Warning: Invalid rectangle! Opposite sides are not equal or not perpendicular." << endl;
        }
    }

    // Check if the rectangle is a square
    bool isSquare() const {
        Point widthVector = p2.subtract(p1);
        Point heightVector = p1.subtract(p4);
        return widthVector.getX() == heightVector.getY();
    }

    // Calculate area of the rectangle
    float calculateArea() const {
        Point widthVector = p2.subtract(p1);
        Point heightVector = p1.subtract(p4);
        return fabs(widthVector.getX() * heightVector.getY());
    }

    // Calculate circumference of the rectangle
    float calculateCircumference() const {
        Point widthVector = p2.subtract(p1);
        Point heightVector = p1.subtract(p4);
        return 2 * (fabs(widthVector.getX()) + fabs(heightVector.getY()));
    }

    // Calculate bounding box of the rectangle
    void boundingBox(Point& topLeft, Point& topRight, Point& bottomRight, Point& bottomLeft) const {
        float minX = min(min(p1.getX(), p2.getX()), min(p3.getX(), p4.getX()));
        float maxX = max(max(p1.getX(), p2.getX()), max(p3.getX(), p4.getX()));
        float minY = min(min(p1.getY(), p2.getY()), min(p3.getY(), p4.getY()));
        float maxY = max(max(p1.getY(), p2.getY()), max(p3.getY(), p4.getY()));

        topLeft = Point(minX, maxY);
        topRight = Point(maxX, maxY);
        bottomRight = Point(maxX, minY);
        bottomLeft = Point(minX, minY);
    }

    // Check if the rectangle is a valid shape
    bool isValidShape() const {
        // Calculate the lengths of the sides
        float side_length[4];
        side_length[0] = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
        side_length[1] = sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p2.getY(), 2));
        side_length[2] = sqrt(pow(p4.getX() - p3.getX(), 2) + pow(p4.getY() - p3.getY(), 2));
        side_length[3] = sqrt(pow(p1.getX() - p4.getX(), 2) + pow(p1.getY() - p4.getY(), 2));

        // Check if opposite sides are equal in length
        bool equalWidths = (fabs(side_length[0] - side_length[2]) == 0) && (fabs(side_length[1] - side_length[3]) == 0);

        // Check if adjacent sides are perpendicular
        float dot_product[4];
        dot_product[0] = (p2.getX() - p1.getX()) * (p3.getX() - p2.getX()) + (p2.getY() - p1.getY()) * (p3.getY() - p2.getY());
        dot_product[1] = (p3.getX() - p2.getX()) * (p4.getX() - p3.getX()) + (p3.getY() - p2.getY()) * (p4.getY() - p3.getY());
        dot_product[2] = (p4.getX() - p3.getX()) * (p1.getX() - p4.getX()) + (p4.getY() - p3.getY()) * (p1.getY() - p4.getY());
        dot_product[3] = (p1.getX() - p4.getX()) * (p2.getX() - p1.getX()) + (p1.getY() - p4.getY()) * (p2.getY() - p1.getY());

        bool orthogonalSides = (fabs(dot_product[0]) == 0) && (fabs(dot_product[1]) == 0) &&
                               (fabs(dot_product[2]) == 0) && (fabs(dot_product[3]) == 0);

        return equalWidths && orthogonalSides;
    }

    // Display information about the rectangle
    void display() const {
        if (isValidShape()) {
            cout << "Rectangle" << endl;
            cout << "Point 1: "; p1.show(); cout << endl;
            cout << "Point 2: "; p2.show(); cout << endl;
            cout << "Point 3: "; p3.show(); cout << endl;
            cout << "Point 4: "; p4.show(); cout << endl;
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
    // Default constructor
    Triangle() : p1(Point()), p2(Point()), p3(Point()) {}

    // Constructor with arguments
    Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {
        // Check if the given points form a valid triangle
        if (!isValidShape()) {
            cout << "Warning: Invalid triangle! Cannot create a triangle with a side of zero length or colinear points" << endl;
        }
    }

    bool isValidShape() const {
        // Check for sides with zero length
        if ((p1.getX() == p2.getX() && p1.getY() == p2.getY()) ||
            (p2.getX() == p3.getX() && p2.getY() == p3.getY()) ||
            (p1.getX() == p3.getX() && p1.getY() == p3.getY())) {
            // cout << "Invalid triangle! Cannot create a triangle with a side of zero length." << endl;
            return false;
        }

        // Check for colinear points
        float crossProduct = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p3.getX() - p1.getX()) * (p2.getY() - p1.getY());
        if (fabs(crossProduct) < 1e-6) {
            // cout << "Invalid triangle! Cannot create a triangle with colinear points." << endl;
            return false;
        }

        return true;
    }

    // Calculate area of the triangle
    float calculateArea() const {
        float s = calculateCircumference() / 2;
        float a = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
        float b = sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p2.getY(), 2));
        float c = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }


    // Calculate circumference of the triangle
    float calculateCircumference() const {
        float a = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
        float b = sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p2.getY(), 2));
        float c = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
        return a + b + c;
    }

    // Calculate bounding box of the triangle
    void boundingBox(Point& tl, Point& tr, Point& br, Point& bl) const {
        float minX = min(min(p1.getX(), p2.getX()), p3.getX());
        float minY = min(min(p1.getY(), p2.getY()), min(p3.getY(), minY));
        float maxX = max(max(p1.getX(), p2.getX()), max(p3.getX(), minX));
        float maxY = max(max(p1.getY(), p2.getY()), max(p3.getY(), minY));
        tl = Point(minX, minY);
        tr = Point(maxX, minY);
        br = Point(maxX, maxY);
        bl = Point(minX, maxY);
    }

    // Display information about the triangle
    void display() const {
       if (isValidShape()) {
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
    }
};


// Main function
int main() {
    cout << "Circle: " << endl;
    // Valid circle
    Circle c1(Point(0, 0), 5);
    c1.display();
    cout << endl;

    cout << "Invalid Circle: " << endl;
    // Invalid circle with negative radius (error handling demonstrated)
    Circle c2(Point(1, 1), -2);
    c2.display();
    cout << endl;

    cout << "Valid Rectangle 1: " << endl;
    // Valid rectangle
    Rectangle r1(Point(-3, -2), Point(5, -2), Point(5, 4), Point(-3, 4));
    r1.display();
    cout << endl;

    cout << "Valid Rectangle 2: " << endl;
    // Valid rectangle
    Rectangle r2(Point(0, 0), Point(4, 0), Point(4, 3), Point(0, 3));
    r2.display();
    cout << endl;  

    cout << "Square (Rectangle): " << endl;
    // Square rectangle (special case)
    Rectangle square_r(Point(0, 0), Point(2, 0), Point(2, -2), Point(0, -2));
    square_r.display();
    cout << endl;


    cout << "Invalid Rectangle (Not Equal/Irregular): " << endl;
    // Invalid rectangle with random points (error handling demonstrated)
    Rectangle inv_r1(Point(0, 0), Point(4, 0), Point(1, 2), Point(3, 3));
    inv_r1.display();
    cout << endl;

    cout << "Invalid Rectangle (Rhombus/Parallelogram): " << endl;
    // Invalid rectangle with random points (error handling demonstrated)
    Rectangle inv_r2(Point(-1, 3), Point(0, 0), Point(4, 0), Point(3, 3));
    inv_r2.display();
    cout << endl;


    cout << "Valid Triangle: " << endl;
    // Valid triangle
    Triangle t(Point(0, 0), Point(0, 3), Point(4, 0));
    t.display();
    cout << endl;

    cout << "Invalid Triangle [Side w/ Zero Length]: " << endl;
    // Invalid triangle with zero-length side (error handling demonstrated)
    Triangle invalid_t1(Point(0, 0), Point(0, 0), Point(1, 0));
    invalid_t1.display();
    cout << endl;

    cout << "Invalid Triangle [Colinear]: " << endl;
    // Invalid triangle with zero-length side (error handling demonstrated)
    Triangle invalid_t2(Point(-1, 3), Point(-1, 5), Point(-1, 8));
    invalid_t2.display();
    cout << endl;


    return 0;
}