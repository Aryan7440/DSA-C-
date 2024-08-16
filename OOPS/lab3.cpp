#include <iostream>
#include <math.h>
#define pi 3.1452
using namespace std;

double argument(double x, double y)
{
    if (x > 0 && y > 0)
        return atan(abs(y / x));
    if (x > 0 && y < 0)
        return -atan(abs(y / x));
    if (x < 0 && y > 0)
        return pi - atan(abs(y / x));
    if (x < 0 && y < 0)
        return atan(abs(y / x)) - pi;
}

class rectangle_coordinates;
class polar
{
private:
    double radius;
    double angle;
    friend polar operator-(polar obj1, polar obj);

public:
    polar();
    polar(double x, double y);
    ~polar();
    friend class rectangle_coordinates;

    void set(double x, double y);
    polar operator*(polar obj);

    void display();
};
class rectangle_coordinates
{
private:
    double x;
    double y;

public:
    rectangle_coordinates();
    rectangle_coordinates(double x, double y);
    ~rectangle_coordinates();
    void display();
    rectangle_coordinates conversion(polar obj);
};
rectangle_coordinates rectangle_coordinates::conversion(polar obj)
{
    rectangle_coordinates ans;
    ans.x = obj.radius * cos(obj.angle);
    ans.y = obj.radius * sin(obj.angle);
    return ans;
}

rectangle_coordinates::rectangle_coordinates()
{
    x = 0;
    y = 0;
}
rectangle_coordinates::rectangle_coordinates(double x, double y)
{
    this->x = x;
    this->y = y;
}

rectangle_coordinates::~rectangle_coordinates()
{
}
void rectangle_coordinates::display()
{
    cout << "f(x,y) = (" << x << "," << y << ")" << endl;
}

polar::polar(/* args */)
{
    radius = 0;
    angle = 0;
}
polar::polar(double x, double y)
{
    this->radius = fmod(x, 2 * pi);
    this->angle = fmod(y, 2 * pi);
}

polar::~polar()
{
    // cout << "destroyd" << endl;
}

void polar::set(double x, double y)
{
    radius = fmod(x, 2 * pi);
    angle = fmod(y, 2 * pi);
}
polar polar::operator*(polar obj)
{
    polar ans;
    ans.radius = radius * obj.radius;
    ans.angle = fmod((angle + obj.angle), 2 * pi);

    return ans;
}
void polar ::display()
{
    cout << "f(r,angle) = (" << radius << "," << angle << "*)" << endl;
}

polar operator-(polar obj1, polar obj2)
{
    polar ans;
    double real = (obj1.radius * cos(obj1.angle)) - (obj2.radius * cos(obj2.angle));
    double imag = (obj1.radius * sin(obj1.angle)) - (obj2.radius * sin(obj2.angle));
    ans.radius = sqrt(real * real + imag * imag);
    ans.angle = argument(real, imag);
    return ans;
}

int main()
{
    polar obj1(3, 1.0472);
    rectangle_coordinates obj5;
    polar obj2(4, 3.66519);
    obj1.display();
    obj2.display();
    polar obj3 = obj2 * obj1;
    obj3.display();
    polar obj4 = obj1 - obj2;
    obj4.display();
    obj5=obj5.conversion(obj1);
    obj5.display();
}
