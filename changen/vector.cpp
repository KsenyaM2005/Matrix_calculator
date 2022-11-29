#include "vector.h"
#include <cmath>

///Constructor
Vector::Vector(vector<long double>& num)
    :Column(num)
{
    if (numbers.size() > 3)
        throw runtime_error("Interesting vec");
}

///Operators
Vector Vector::operator+(Vector& vec)
{
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Bad vector size");
    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] += vec.numbers[i];
    Vector res{numbers};
    return res;
}

void Vector::operator+=(Vector& vec)
{
    *this = *this + vec;
}

Vector Vector::operator-(Vector& vec)
{
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Bad vector size");
    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] -= vec.numbers[i];
    Vector res{numbers};
    return res;
}

void Vector::operator-=(Vector& vec)
{
    *this = *this - vec;
}

Vector Vector::operator*(Vector& vec)
{
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("Bad vector size");
    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] *= vec.numbers[i];
    Vector res{numbers};
    return res;
}

void Vector::operator*=(Vector& vec)
{
    *this = *this * vec;
}

Vector Vector::operator*(double num)
{
    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] *= num;
    Vector res{numbers};
    return res;
}

void Vector::operator*=(double num)
{
    *this = *this * num;
}

Vector Vector::operator/ (double num)
{
    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] /= num;
    Vector res{numbers};
    return res;
}

void Vector::operator/= (double num)
{
    *this = *this / num;
}

///Methods
///
long double Vector::scal_prod(const Vector& vec) //scalar product
{
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("bad product");
    if (numbers.size() == 3)
    {
        long double x = numbers[0]*vec.numbers[0];
        long double y = numbers[1]*vec.numbers[1];
        long double z = numbers[2]*vec.numbers[2];
        return x+y+z;
    }
    else
    {
        long double x = numbers[0]*vec.numbers[0];
        long double y = numbers[1]*vec.numbers[1];
        return x+y;
    }
}

Vector Vector::vec_prod(const Vector& vec) //Vector product
{
    if (numbers.size() != vec.numbers.size())
        throw runtime_error("bad product");
    if (numbers.size() != 3)
        throw runtime_error("bad size");
    long double x = numbers[1]*vec.numbers[2] - numbers[2]*vec.numbers[1];
    long double y = numbers[2]*vec.numbers[0] - numbers[0]*vec.numbers[2];
    long double z = numbers[0]*vec.numbers[1] - numbers[1]*vec.numbers[0];
    vector<long double> ans {x, y, z};
    Vector res{ans};
    return res;
}

long double Vector::length()
{
    if (numbers.size() == 3)
        return sqrt(numbers[0]*numbers[0] + numbers[1]*numbers[1] + numbers[2]*numbers[2]);
    return sqrt(numbers[0]*numbers[0] + numbers[1]*numbers[1]);
}

void Vector::show()
{
    for (int i : numbers)
        cout << i << ' ';
}
